#ifndef ___OPERATION__H__
#define ___OPERATION__H__
#include <iostream>
#include <vector>

void print(const std::vector<int >& v)
{
	std::vector<int>::const_iterator cbegin = v.cbegin();
	while (cbegin != v.cend())
	{
		std::cout << *cbegin << std::endl;
		++cbegin;
	}
}
void Assign()
{
	std::vector<int> v0 = {1, 2};
	std::vector<int> v1 = { 2, 3 };

	swap(v0, v1);     //swap通常要比元素拷贝快得多
	print(v0);
	print(v1);

	std::vector<int> v2;
	v2.assign(v0.cbegin(), v0.cend());  //赋值运算会使指向左边的容器内部的迭代器，引用指针失效，而swap不会
	print(v2);
	std::vector<int>v3;
	v3.assign( 3, 3 );
	print(v3);

	std::string s = "hello";
	std::string::iterator iter = s.begin();
	

	std::list<const char*> listr = { "hello world"  };  //assign 可以将容器类型不同，但是元素相容类型进行赋值
	std::vector<std::string> vstr;
	vstr.assign(listr.cbegin(), listr.cend());

	std::cout << vstr[0] << std::endl;

}

#endif

