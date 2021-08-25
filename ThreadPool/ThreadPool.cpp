#include "ThreadPool.h"
#include <memory>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
//创建的线程执行
void *thread_rountie(void* arg)
{
    struct timespec abstime;
    int timeout;
    printf("thread %d is starting\n", (int)pthread_self());

    threadpool_t *pool = (threadpool_t*)arg;
    
    while(true)
    {
        timeout = 0;

        condition_lock(&pool->ready);

        pool->idle++;    //空闲线程
        //任务为空并且线程未退出时
        while(NULL == pool->first && !pool->quit)
        {
            printf("thread %d is waiting\n", (int)pthread_self());
            //设置线程超时时间
            clock_gettime(CLOCK_REALTIME, &abstime);
            abstime.tv_sec += 2;
            int status;
        
            status = condition_timedwait(&pool->ready, &abstime);
            if(ETIMEDOUT == status)
            {
                printf("thread %d wait timed out\n", (int)pthread_self());
                timeout = 1;
                break;
            }
        }

        pool->idle--;
        if(pool->first != NULL)
        {
            task_t *task = pool->first;
            pool->first = task->next;

            //任务执行需要时间，解锁让其他线程访问线程池
            condition_unlock(&pool->ready);
            task->run(task->arg);

            free(task);             //释放任务
            condition_lock(&pool->ready);    //重新加锁
        }

        if(pool->quit && pool->first == NULL)   //线程退出
        {
            pool->counter--;

            if(0 == pool->counter)   //所有工作线程为0
            {
                condition_signal(&pool->ready);
            }
            condition_unlock(&pool->ready);

            break;
        }
        if(1 == timeout)  //若超时，退出工作线程
        {
            pool->counter--;
            condition_unlock(&pool->ready);
            break;
        }
        condition_unlock(&pool->ready);

    }
    printf("thread %d is exiting\n", (int)pthread_self());
    return NULL;

}



void threadPool_init(threadpool_t *threadpool,int threadNums)
{
    condition_init(&threadpool->ready);
    threadpool->first = NULL;
    threadpool->last = NULL;
    threadpool->counter = 0;
    threadpool->idle = 0;
    threadpool->max_threads = threadNums;
    threadpool->quit = 0;
}

void threadPool_addTask(threadpool_t *threadpool, void *(*run)(void *args), void* arg)
{
    task_t *newTask = (task_t*)malloc(sizeof(task_t));    //分配任务对象
    newTask->run = run;                //函数指针赋值
    newTask->arg = arg;                //函数参数
    newTask->next = NULL;              //新的任务放到队列尾端

    condition_lock(&threadpool->ready);   //访问线程池，对线程池加锁

    //增加任务到任务队列
    if(NULL == threadpool->first)
    {
        threadpool->first = newTask;
    }
    else
    {
        threadpool->last->next = newTask;
    }
    threadpool->last = newTask;

    if(threadpool->idle > 0)   //如果存在空闲线程则唤醒线程
    {
        std::cout<<"threadpool->idle > 0"<<std::endl;
        
        condition_signal(&threadpool->ready);
    }
    else if(threadpool->counter < threadpool->max_threads)   //线程池没有到达最大，创建线程
    {
        pthread_t tid;
        pthread_create(&tid, NULL, thread_rountie,threadpool);
        threadpool->counter++;
    }

    condition_unlock(&threadpool->ready);
}


//线程池销毁
void threadPool_destory(threadpool_t *pool)
{
    //如果已经调用销毁，直接返回
    if(pool->quit)
    {
    return;
    }
    //加锁
    condition_lock(&pool->ready);
    //设置销毁标记为1
    pool->quit = 1;
    //线程池中线程个数大于0
    if(pool->counter > 0)
    {
        //对于等待的线程，发送信号唤醒
        if(pool->idle > 0)
        {
            condition_broadcast(&pool->ready);
        }
        //正在执行任务的线程，等待他们结束任务
        while(pool->counter)
        {
            condition_wait(&pool->ready);
        }
    }
    condition_unlock(&pool->ready);
    condition_destroy(&pool->ready);
}