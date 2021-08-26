// 
//

# include <iostream>
# include <mutex>
# include <pthread.h>
#include "Singleton.h"
#define THREAD_NUM 5  //线程个数

void* print_hello(void* thread_id)
{
	pthread_detach(pthread_self());  //分离线程

	int pthreadId = *((int*)thread_id);
	std::cout << "pthread id is" << pthreadId << std::endl; //打印线程id
	Singleton::getIntance()->print();  //打印对象地址

	pthread_exit(NULL);
}

int main()
{
	pthread_t pthread_id[THREAD_NUM] = {};  //线程id
	int index[THREAD_NUM] = {}; //线程索引
	int ret;

	std::cout << "main is start" << std::endl;

	for (int i = 0; i < THREAD_NUM; ++i)
	{
		index[i] = i;
		ret = pthread_create(&pthread_id[i], NULL, print_hello, (void*)&(index[i]));
		if (ret)
		{
			std::cout << "create pthread error" << std::endl;
			exit(-1);
		}
	}
	Singleton::deleteIntance();
	return 0;
}

