#ifndef ___MAINFORM__H__
#define ___MAINFROM__H__
#include "Factory.h"
#include "Operation.h"

//使用抽象和工厂方法解除了编译依赖

class MainForm
{
public:
	MainForm(Factory* factory):m_factory(factory) {}
	~MainForm() 
	{ 	
	}
	void PrintTest()const
	{
		//Operation* operation0 = new AddOperation();        //依赖于具体对象
	   
		std::shared_ptr<Operation> operation(m_factory->CreateFactory()); //通过方法去返回对象，依赖于抽象
		operation->PrintOperation();
		//operation0->PrintOperation();
	}
private:
	std::shared_ptr<Factory> m_factory;  //指针，没有编译依赖，编译不需要factory定义，不需要知道他的内存大小
};
#endif

