#ifndef ___MAINFORM__H__
#define ___MAINFROM__H__
#include "Factory.h"
#include "Operation.h"

//ʹ�ó���͹�����������˱�������

class MainForm
{
public:
	MainForm(Factory* factory):m_factory(factory) {}
	~MainForm() 
	{ 	
	}
	void PrintTest()const
	{
		//Operation* operation0 = new AddOperation();        //�����ھ������
	   
		std::shared_ptr<Operation> operation(m_factory->CreateFactory()); //ͨ������ȥ���ض��������ڳ���
		operation->PrintOperation();
		//operation0->PrintOperation();
	}
private:
	std::shared_ptr<Factory> m_factory;  //ָ�룬û�б������������벻��Ҫfactory���壬����Ҫ֪�������ڴ��С
};
#endif

