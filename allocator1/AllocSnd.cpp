#include "AllocSnd.h"
#include <iostream>

AllocSnd* AllocSnd::headofFreeList = 0;
const int AllocSnd::BLOCK_SIZE = 512;

void* AllocSnd::operator new(size_t size)
{
	//���̳з���ʱ����С������ʹ��::operator new
	if (size != sizeof(AllocSnd))
		return ::operator new(size);

	AllocSnd* p = headofFreeList; //�ڴ�����ͷ�ڵ�

	if (p)   //���ڴ�ڵ��ѷ��䣬listͷ�Ƶ���һ���ڵ�
	{
		headofFreeList = p->next;
	}
	else
	{
		AllocSnd* newBlock = static_cast<AllocSnd*> (::operator new(BLOCK_SIZE * sizeof(AllocSnd)));   //�����ڴ�ش�С
		
		//�ڴ�ָ�ɿ飬
		for (int i = 0; i < BLOCK_SIZE - 1; ++i)
		{
			newBlock[i].next = &newBlock[i + 1];
		}

		newBlock[BLOCK_SIZE - 1].next = 0;   //β�ڵ�ָ���

		p = newBlock;  //ȡ��һ���ڵ��ڴ�

		headofFreeList = &newBlock[1]; //��һ���ڵ㱻����
	}

	return p;
}

void AllocSnd::operator delete(void* pdead, size_t size)
{
	if (pdead == NULL)
		return;
	if (size != sizeof(AllocSnd))
	{
		::operator delete(pdead);
		return;
	}

	AllocSnd* p = static_cast<AllocSnd*>(pdead);
	p->next = headofFreeList;   //��Ҫɾ���Ľڵ�ŵ�ͷ�ڵ�
	headofFreeList = p;        
}