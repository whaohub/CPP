#ifndef __TEST1__H__
#define __TEST1__H__
#include <iostream>
class Test1
{
public:
	Test1()
	{
		std::cout << "Test1 ctor" << std::endl;
	}
	~Test1()
	{
		std::cout << "test1 dto" << std::endl;
	}
};
#endif