#ifndef __FACTORY__H__
#define __FACTORY__H__

/*
	����һ����������Ľӿڣ����������ʵ������һ���࣬
	����������һ�����ʵ�����ӳٵ�����
*/

#include "Operation.h"

class Factory         //����
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