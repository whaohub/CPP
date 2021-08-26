
#include <iostream>
#include <vector>
#include "screen.h"
#include "AllocSnd.h"
#include "Allocator.h"
#include "TestFoo.h"
#include "NewHandler.h"
/// <summary>
/// 内存池测试
/// </summary>

void allocTest()
{
	std::cout << sizeof(Screen) << std::endl;
	const int Size = 100;
	Screen* pArray[Size];

	//分配100次
	for (int i = 0; i < Size; ++i)
	{
		pArray[i] = new Screen(i);
	}

	//输出前十个pointer 比较其间隔
	for (int i = 0; i < 10;++i) 
	{
		std::cout << pArray[i] << std::endl;
	}
	for (int i = 0; i < Size; ++i)
	{
		delete pArray[i];
	}
}

void allocsndTest()
{
	std::cout << "size allocsnd = " << sizeof(AllocSnd) << std::endl;

	const int NUM = 100;
	AllocSnd* p[NUM];
	for (int i = 0; i < NUM; ++i)
	{
		 p[i] = new AllocSnd;
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "p = " << p[i] << std::endl;
	}

	for (int i = 0; i < NUM; ++i)
	{
		delete p[i];
	}
}


void allocatorTest()
{
	TestFoo* p[100];
	std::cout << "sizeof foo = " << sizeof(TestFoo) << std::endl;
	for (int i = 0; i < 20; ++i)
	{

		p[i] = new TestFoo();
		std::cout << "p = " << p[i] << std::endl;
				
	}
		
	for (int i = 0; i < 20; ++i)
	{
		delete p[i];
	}
}

void NewHandlerTest()
{
	std::set_new_handler(noMoreMemory);

	int* p = new int[90000000];
	assert(p);
}

int main() 
{
	//allocTest();
	//allocsndTest();
	//allocatorTest();
	
	TestFoo* p = new TestFoo();
	std::cout << sizeof(TestFoo)<<sizeof(*p);
	return 0;
}