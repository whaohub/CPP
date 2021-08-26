#ifndef __SCREEN__H__
#define __SCREEN__H__

class Screen
{
public:
	Screen(int x) :i(x) {}
	int get() { return i; }

	void* operator new (size_t size);
	void operator delete(void * pdead, size_t);
private:
	int i;
private:
	Screen* next;
	static Screen* freeStore;   // 指向内存空间指针
	static const int screenChunk;   //分配内存大小的常量
};

#endif
