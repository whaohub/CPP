#ifndef __OPERATION__H__
#define __OPERATION__H__
#include <iostream>
class Operation    //����
{
public:
	Operation(){}
	virtual ~Operation()
	{
		std::cout << "operation dtor" << std::endl;
	}
	virtual void PrintOperation()=0;
};

class AddOperation : public Operation  //�ӷ���
{
public:
	AddOperation(){}
	~AddOperation() 
	{ 
		std::cout << "add dtor" << std::endl; 
	}
	virtual void PrintOperation()
	{
		std::cout << "add Operation" << std::endl;
	}

}; 

class SubOperation  : public Operation  //������
{
public:
	SubOperation() {}
	~SubOperation() 
	{
		std::cout << "sub dtor" << std::endl;
	}
	virtual void PrintOperation()
	{
		std::cout << "sub operation" << std::endl;
	}
};
#endif // !__OPERATON__H__

