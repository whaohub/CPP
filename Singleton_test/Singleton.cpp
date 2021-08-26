#include"Singleton.h"
#include <new>
# include <iostream>
Singleton::Singleton()
{
	std::cout << "ctor" << std::endl;
}
Singleton::~Singleton()
{
	std::cout << "delete ctor" << std::endl;
}
Singleton* Singleton::getIntance()
{
	if (m_obj == NULL)
	{
		m_obj = new(std::nothrow) Singleton();
	}
	return m_obj;
}

void Singleton::deleteIntance()
{
	if (m_obj)
	{
		delete m_obj;
		m_obj = NULL;
	}
}
void Singleton::print()const
{
	std::cout << "address is:" << this << std::endl;
}