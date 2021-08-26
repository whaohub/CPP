#ifndef __ALLOCSND__H__
#define __ALLOCSND__H__

/// <summary>
/// 
/// </summary>
class AllocSnd
{
public:
	static void* operator new(size_t);
	static void operator delete(void* ,size_t);
private:
	struct AllocObj
	{
		unsigned long li;
		char c;
	};

private:
	union 
	{
		AllocObj obj;
		AllocSnd* next;     //«∂»Î Ω÷∏’Î £°£°£°£°
	};
private:
	static AllocSnd* headofFreeList;
	static const int BLOCK_SIZE;
};

#endif
