#ifndef __MALLOC__H__
#define __MALLOC__H__
#include <iostream>
#include <memory>
#include "Test.h"
class Malloc
{
public:
	Malloc():m_test(new Test())
	{
		std::cout << "ctor" << std::endl;
	}
	~Malloc()
	{
		//delete m_test;  //不适用智能指针时,不加delete ，test资源没有被释放，使用智能指针时提示使用指向完整类型的对象指针
		std::cout << "dctor" << std::endl;
	}
private:
	//Test* m_test;
	std::shared_ptr<Test> m_test;
};
#endif
