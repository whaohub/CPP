/*
 * @Author: Whao 
 * @Date: 2021-08-15 15:33:19 
 * @Last Modified by: Whao
 * @Last Modified time: 2021-08-15 15:33:39
 */

#ifndef _CONDITION_H_
#define _CONFITION_H_

#include <pthread.h>

typedef struct condition
{
    pthread_mutex_t pmutex;
    pthread_cond_t pcond;
}condition_t;

void error_handler(char *err);

int condition_init(condition_t *cond); // 条件变量和锁的初始化
int condition_lock(condition_t *cond); //加锁
int condition_unlock(condition_t *cond); //解锁
int condition_wait(condition_t *cond);   //
int condition_timedwait(condition_t *cond, const struct timespec *abstime);
int condition_signal(condition_t* cond);    //至少唤醒一个等待该条件的线程
int condition_broadcast(condition_t *cond); //唤醒等待该条件的所有线程
int condition_destroy(condition_t *cond);


#endif