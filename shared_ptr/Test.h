#ifndef __TEST__H__
#define __TEST__H__
#include <iostream>
class Test
{
public:
	Test()
	{
		std::cout << "test ctor" << std::endl;
	}
	~Test()
	{
		std::cout << "test dtor" << std::endl;
	}
private:

};
#endif
