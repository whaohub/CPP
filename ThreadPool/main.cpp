#include "ThreadPool.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void* mytask(void *arg)
{
    printf("thread %d is working on task %d\n", (int)pthread_self(), *(int*)arg);
    sleep(1);
    free(arg);
    return NULL;
}

//测试代码
int main(void)
{
    threadpool_t pool;
    //初始化线程池，最多三个线程
    threadPool_init(&pool, 3);
    int i;
    //创建十个任务
    for(i=0; i < 10; i++)
    {
        int *arg = (int*)malloc(sizeof(int));
        *arg = i;
        threadPool_addTask(&pool, mytask, arg);
        sleep(2);
        
    }
    sleep(2);
    int *arg = (int*)malloc(sizeof(int));
        *arg = 10;
    threadPool_addTask(&pool, mytask, arg);
    threadPool_destory(&pool);
    return 0;
}