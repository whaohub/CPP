#ifndef _SMARTPOINTER_H_
#define _SMARTPOINTER_H_
#include <memory>
#include <iostream>
#include <assert.h>

template <typename T>
class SmartPointer
{
public:
    //构造
    SmartPointer(T *ptr = nullptr);

    //拷贝构造
    SmartPointer(const SmartPointer &ptr);

    //拷贝赋值
    SmartPointer &operator=(const SmartPointer &);

    //*运算符重载
    T &operator*();

    //->重载
    T *operator->();

    //析构函数
    ~SmartPointer();

    size_t use_count();

private:
    T *m_ptr;
    size_t *m_count;
};

template <typename T>
SmartPointer<T>::SmartPointer(T *ptr) : m_ptr(ptr)
{
    if (m_ptr != NULL)
    {
        std::cout<<"ctor"<<std::endl;
        m_count = new size_t(1);
    }
    else
    {
        m_count = new size_t(0);
    }
}

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T> &ptr)
{
    if (this != &ptr)
    {
        std::cout<<"copy ctor"<<std::endl;
        this->m_ptr = ptr.m_ptr;
        this->m_count = ptr.m_count;
        (*this->m_count)++;
        
    }
}

template <typename T>
SmartPointer<T> &SmartPointer<T>::operator=(const SmartPointer<T> &ptr)
{
    std::cout<<"operator ="<<std::endl;
    if (this->m_ptr == ptr.m_ptr) //检测自我赋值
    {
        return *this;
    }

    if (this->m_ptr)
    {
        --(*this->m_count);
        if ((*this->m_count) == 0)
        {
            delete this->m_ptr;
            delete this->m_count;
        }
    }
    this->m_ptr = ptr.m_ptr;
    this->m_count = ptr.m_count;
    (*this->m_count)++;
    return *this;
}

template<typename T>
T& SmartPointer<T>::operator*()
{
    assert(this->m_ptr != nullptr);

    return *(this->m_ptr);
}

template<typename T>
T* SmartPointer<T>::operator->()
{
    assert(this->m_ptr != nullptr);

    return this->m_ptr;
}

template<typename T>
SmartPointer<T>::~SmartPointer()
{
    --(*this->m_count);
    if(*this->m_count == 0)
    {
        std::cout<<"dtor"<<std::endl;   
        delete m_ptr;
        delete m_count;
    }
}

template<typename T>
size_t SmartPointer<T>::use_count()
{
    return *this->m_count;
}
#endif