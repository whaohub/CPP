#ifndef __ITERATOR__H__
#define __ITERATOR__H__
#include <vector>
#include <list>
#include <array>
#include <iostream>
/*
* �������ķ�Χ��begin��end����ָ��ͬһ�������е�Ԫ�أ������һ��λ�ã�end
* һ��Ҫ��begin֮��begin������end��������ʼ������ҿ���
* ���begin��end�����ΧΪ�գ�
* �������������ٰ���һ����
* ���Զ�begin������ʹbegin==end
*/
typedef std::vector<int>::iterator iter;
// ����������
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

//����������Ŀ��ֵ
bool  FindNum(std::vector<int>& ve, const int& num)
{
	//������Ҫд����ʱ��Ӧʹ��cbegin��cend;
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

//������ʼ��
/*��ʹ��һ��������ʼ����һ�������Ŀ���ʱ�������������ͺ�Ԫ�����Ͷ�������ͬ
��ʹ�õ�����������һ����Χʱ�Ͳ���Ҫ����������ͬ�ˣ�������������ԭ����Ԫ��
����Ҳ���Բ�ͬ��ֻҪ����Ԫ����ת��Ϊ������Ԫ�����;Ϳ���
*/
void InitContainer()
{
	std::list<std::string> list;
	std::vector<const char*> vstr = { "hello", "world" };  //�б��ʼ��������array����֮�⣬�����������������Ĵ�С
	list = {vstr.begin(), vstr.end()};   //���Խ�������ת��

	std::array<int, 5> arry = { 1,2 };   //��׼��array,��Ҫָ��Ԫ�ص����ͺ�Ԫ�صĴ�С ��
	//����������������飬array���Խ������鿽����������ҪԪ�����ͺʹ�С��ƥ��

	std::array<int, 5> arry1 = arry;  //Ԫ�صĴ�СҲ��array������һ����


	auto begin = list.cbegin();
	auto end= list.cend();

	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}
}
#endif
