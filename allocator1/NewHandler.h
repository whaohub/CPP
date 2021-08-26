#ifndef __NEWHANDLER__H__
#define __NEWHANDLER__H__

/*
* 当operator new没能力为你分配你所分配 的内存时
* 会抛出std::bad_alloc 异常。老编译器会返回0
* 可以令编译器这么做
* new(nothrow)Foo 返回0，不抛出异常
* 抛出异常之前会先调用一个由client设定的函数
*/

// 以下是new handler的形式和设定方法
//typedef void (*new_handler)();
//new_handler set_new_handler(new_handler p)throw();
/*
* 设计良好的new handler 只有俩个选择
* 让更多的内存可用
* 调用abort()或exit()
*/

#include <new>
#include <iostream>
#include <cassert>

void noMoreMemory()
{
	std::cout << "out of memory" << std::endl;
	abort();
}


#endif
