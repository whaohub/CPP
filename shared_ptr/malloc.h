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
		//delete m_test;  //����������ָ��ʱ,����delete ��test��Դû�б��ͷţ�ʹ������ָ��ʱ��ʾʹ��ָ���������͵Ķ���ָ��
		std::cout << "dctor" << std::endl;
	}
private:
	//Test* m_test;
	std::shared_ptr<Test> m_test;
};
#endif
