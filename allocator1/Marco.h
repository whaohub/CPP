#ifndef __MARCO_H__
#define __MARCO_H__
#include "Allocator.h"

#define DECLAER_POOL_ALLOC()\
public:\
void* operator new(size_t size) {return myAlloc.allocate(size);}\
void operator delete(void* pdead, size_t size){myAlloc.deallocate(pdead, size);}\
protected:\
	static Allocator myAlloc;

#define IMPLEMENT_POOL_ALLOC(class_name)\
Allocator class_name::myAlloc;

#endif
