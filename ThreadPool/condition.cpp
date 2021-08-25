#include "condition.h"
#include <stdio.h>

void error_handler(char *err)
{
    puts(err);
}

int condition_init(condition_t* cond)
{
    int status;
    if(status = pthread_mutex_init(&cond->pmutex,NULL))
    {
        error_handler("pthread_mutex_init");
        return status;
    }

    if(status = pthread_cond_init(&cond->pcond,NULL))
    {
        error_handler("pthread_cond_init");
        return status;
    }

    return 0;
}

int condition_lock(condition_t *cond)
{
    int status;
    if(status = pthread_mutex_lock(&cond->pmutex))
    {
        error_handler("pthread_mutex_lock");
        return status;
    }

    return 0;
}

int condition_unlock(condition_t *cond)
{
    int status;
    if(status = pthread_mutex_unlock(&cond->pmutex))
    {
        error_handler("pthread_mutex_unlock");
        return status;
    }
    return 0;
}

//等待
int condition_wait(condition_t *cond)
{
    return pthread_cond_wait(&cond->pcond, &cond->pmutex);
}

//固定时间等待
int condition_timedwait(condition_t *cond, const struct timespec *abstime)
{
    return pthread_cond_timedwait(&cond->pcond, &cond->pmutex, abstime);
}

//唤醒一个睡眠线程
int condition_signal(condition_t* cond)
{
    return pthread_cond_signal(&cond->pcond);
}

//唤醒所有睡眠线程
int condition_broadcast(condition_t *cond)
{
    return pthread_cond_broadcast(&cond->pcond);
}

//释放
int condition_destroy(condition_t *cond)
{
    int status;
    if((status = pthread_mutex_destroy(&cond->pmutex)))
        return status;
    
    if((status = pthread_cond_destroy(&cond->pcond)))
        return status;
        
    return 0;
}