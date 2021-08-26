#include "AllocSnd.h"
#include <iostream>

AllocSnd* AllocSnd::headofFreeList = 0;
const int AllocSnd::BLOCK_SIZE = 512;

void* AllocSnd::operator new(size_t size)
{
	//当继承发生时，大小会有误，使用::operator new
	if (size != sizeof(AllocSnd))
		return ::operator new(size);

	AllocSnd* p = headofFreeList; //内存链表头节点

	if (p)   //若内存节点已分配，list头移到下一个节点
	{
		headofFreeList = p->next;
	}
	else
	{
		AllocSnd* newBlock = static_cast<AllocSnd*> (::operator new(BLOCK_SIZE * sizeof(AllocSnd)));   //分配内存池大小
		
		//内存分割成块，
		for (int i = 0; i < BLOCK_SIZE - 1; ++i)
		{
			newBlock[i].next = &newBlock[i + 1];
		}

		newBlock[BLOCK_SIZE - 1].next = 0;   //尾节点指向空

		p = newBlock;  //取第一个节点内存

		headofFreeList = &newBlock[1]; //第一个节点被返回
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
	p->next = headofFreeList;   //将要删除的节点放到头节点
	headofFreeList = p;        
}