#include "screen.h"

 /// <summary>
 /// С��memory pool 1
 /// </summary>
 

Screen* Screen::freeStore = 0;
const int Screen::screenChunk = 24;  //

void* Screen::operator new(size_t size)
{
	Screen* p;
	//LinkList �ڴ�Ϊ�գ���������һ����ڴ�
	if (!freeStore)
	{
		size_t chunk = screenChunk * size;    //�����ڴ��С��sizeΪ���������С
		freeStore = p = reinterpret_cast<Screen*>(new char[chunk]);

		//���ڴ�ָ��Ƭ����ʽ��������
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