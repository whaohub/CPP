#ifndef __ITERATOR__H__
#define __ITERATOR__H__
#include <vector>
#include <list>
#include <array>
#include <iostream>
/*
* 迭代器的范围，begin与end必须指向同一个容器中的元素，或最后一个位置，end
* 一定要在begin之后，begin包含，end不包含，始于左闭右开，
* 如果begin与end相等则范围为空，
* 如果不相等则至少包含一个。
* 可以对begin递增，使begin==end
*/
typedef std::vector<int>::iterator iter;
// 迭代器测试
void IteratorFun() 
{
	std::vector<int> ve = {1, 2, 3};
	std::vector<int>::iterator begin = ve.begin();
	std::vector<int>::iterator end = ve.end();

	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}
}

//迭代器查找目标值
bool  FindNum(std::vector<int>& ve, const int& num)
{
	//当不需要写访问时，应使用cbegin，cend;
	auto begin = ve.cbegin();
	auto end = ve.cend();

	while (begin != end)
	{
		if (*begin == num)
		{
			return true;
		}
		++begin;
	}
	return false;	 
}

//容器初始化
/*当使用一个容器初始化另一个容器的拷贝时，俩个容器类型和元素类型都必须相同
当使用迭代器来拷贝一个范围时就不需要容器类型相同了，而且新容器与原容器元素
类型也可以不同，只要拷贝元素能转换为新容器元素类型就可以
*/
void InitContainer()
{
	std::list<std::string> list;
	std::vector<const char*> vstr = { "hello", "world" };  //列表初始化，除了array类型之外，容器还隐含了容器的大小
	list = {vstr.begin(), vstr.end()};   //可以进行类型转换

	std::array<int, 5> arry = { 1,2 };   //标准库array,需要指定元素的类型和元素的大小 ，
	//相对于内置类型数组，array可以进行数组拷贝，但是需要元素类型和大小都匹配

	std::array<int, 5> arry1 = arry;  //元素的大小也是array的类型一部分


	auto begin = list.cbegin();
	auto end= list.cend();

	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}
}
#endif
