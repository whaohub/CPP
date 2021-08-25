/*
 * @Author: Whao 
 * @Date: 2021-08-14 22:25:13 
 * @Last Modified by:   Whao 
 * @Last Modified time: 2021-08-14 22:25:13 
 */

#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "condition.h"

//线程池任务对象的结构
typedef struct task
{
    void * (*run) (void* args);   //函数指针，指向任务处理函数
    void* arg;                    //参数
    struct task *next;            // 任务队列下一个任务，链表
}task_t;

//线程池结构体
typedef struct threadpool
{
    condition_t ready;            //状态量
    task *first;                  //任务队列第一个任务
    task *last;                   //任务队列最后一个任务
    int counter;                  //线程池已有线程数
    int idle;                     //线程池空闲线程数
    int max_threads;              //线程池最大线程数
    int quit;                     //线程退出标志
}threadpool_t;

//线程池初始化
void threadPool_init(threadpool_t *threadpool, int threadNums);

//线程池添加任务
void threadPool_addTask(threadpool_t *threadpool, void *(*run)(void *args), void* arg);

//线程池回收
void threadPool_destory(threadpool_t *threadpool);


#endif