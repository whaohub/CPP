#ifndef __FACTORY__H__
#define __FACTORY__H__

/*
	定义一个创建对象的接口，让子类决定实例化哪一个类，
	工厂方法是一个类的实例化延迟到子类
*/

#include "Operation.h"

class Factory         //抽象
{
public:
	Factory() {}
	virtual ~Factory() {}
	virtual	 Operation* CreateFactory() = 0;
};

class AddFactory : public Factory
{
public:
	AddFactory() {}
	~AddFactory() 
	{
		//delete operation;
	}
	virtual  Operation* CreateFactory()
	{
	    /*Operation * operation =*/ return  new AddOperation();
	}
};

class SubFactory : public Factory
{
public:
	SubFactory(){}
	~SubFactory(){}
	virtual   Operation* CreateFactory()
	{
		return new SubOperation();
	}
};
#endif