#include "screen.h"

 /// <summary>
 /// 小型memory pool 1
 /// </summary>
 

Screen* Screen::freeStore = 0;
const int Screen::screenChunk = 24;  //

void* Screen::operator new(size_t size)
{
	Screen* p;
	//LinkList 内存为空，所以申请一大块内存
	if (!freeStore)
	{
		size_t chunk = screenChunk * size;    //分配内存大小，size为单个对象大小
		freeStore = p = reinterpret_cast<Screen*>(new char[chunk]);

		//将内存分割成片，链式连接起来
		for (; p != &freeStore[screenChunk - 1]; ++p)
		{
			p->next = p + 1;
		}
		p->next = 0;
	}

	p = freeStore;
	freeStore = freeStore->next;
	return p;
}



//?
void Screen::operator delete(void* pdead, size_t size)
{
	(static_cast<Screen*>(pdead))->next = freeStore;
	freeStore = static_cast<Screen*>(pdead);
}