#ifndef __NEWHANDLER__H__
#define __NEWHANDLER__H__

/*
* ��operator newû����Ϊ������������� ���ڴ�ʱ
* ���׳�std::bad_alloc �쳣���ϱ������᷵��0
* �������������ô��
* new(nothrow)Foo ����0�����׳��쳣
* �׳��쳣֮ǰ���ȵ���һ����client�趨�ĺ���
*/

// ������new handler����ʽ���趨����
//typedef void (*new_handler)();
//new_handler set_new_handler(new_handler p)throw();
/*
* ������õ�new handler ֻ������ѡ��
* �ø�����ڴ����
* ����abort()��exit()
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
