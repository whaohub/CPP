#ifndef __TESTFOO_H__
#define __TESTFOO_H__
#include "Allocator.h"
#include "Marco.h"
class TestFoo
{
public:
	//static void* operator new(size_t size);
	DECLAER_POOL_ALLOC();
	//static void operator delete(void*, size_t);

private:
	//static Allocator myAlloc;
	int i;
	char c;
};
IMPLEMENT_POOL_ALLOC(TestFoo);
//Allocator TestFoo::myAlloc;

//void* TestFoo::operator new(size_t size)
//{
//	return myAlloc.allocate(size);
//}
//void TestFoo::operator delete(void* pdead, size_t size)
//{
//	myAlloc.deallocate(pdead, size);
//}

#endif
