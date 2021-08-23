#include "strBlob.h"

StrBlob::StrBlob() :m_dataSptr(std::make_shared<std::vector<std::string>>())
{}

StrBlob::StrBlob(std::initializer_list<std::string> il) : m_dataSptr(std::make_shared<std::vector<std::string>>(il))
{}

void StrBlob::check(size_type i, const std::string& msg)const
{
	if (i >= m_dataSptr->size())
	{
		throw std::out_of_range(msg);
	}
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty strBlob");
	m_dataSptr->pop_back();
}

std::string& StrBlob::front()
{
	
	return rtnFront();
}

std::string& StrBlob::back()
{
	
	return rtnBack();
}

const std::string& StrBlob::front() const 
{
	
	return rtnFront();
}

const std::string& StrBlob::back()const 
{
	
	return rtnBack();
}