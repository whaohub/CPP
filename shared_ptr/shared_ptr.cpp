/*
2020.8.16 By Whao  智能指针
*/
#include <iostream>
#include <vector>
// #include "malloc.h"
// #include "Test1.h"
// #include "strBlob.h"
#include "smartPointer.h"
/*
    程序使用动态内存出于以下三种原因
    * 程序不知道自己需要多少对象。  eg：容器类
    * 程序不知道所需对象的准确类型。
    * 程序需要在多个对象间共享数据。
*/

// void pointerTest0()
// {
//      // Malloc* mac = new Malloc();  //动态分配内存，返回指向该对象的指针
//     /*
//         先调用析构函数，在释放内存，也就是先析构test指针（不用智能指针的情况）
//         使用智能指针时首先析构了本对象，最后智能指针才析构了test对象。
//     */
//   //  delete mac;      

//     //语法
//     //最安全和使用动态内存的方法是调用一个名为make_shared标准库函数，指向一个值为" hello"的字符串
//     std::shared_ptr<std::string> sp0 = std::make_shared < std::string > ("hello");  //智能指针默认指向空，必须与string的构造函数相匹配
    

//     auto sp1  = std::make_shared<std::vector<std::string>>();//指向一个空vector<string>的智能指针

//     auto tsp  = std::make_shared<Test>();
//     auto t1sp = std::make_shared<Test>();

//     tsp = t1sp; //递减tsp的计数，递增t1sp的计数,当计数为0时，会自动调用析构函数
//     std::cout << t1sp.use_count() << std::endl;

//     StrBlob b1;
//     {
//         StrBlob b2 = {"a", "b", "c"};
//         b1 = b2;
//         b2.push_back("end");
//     }
//     std::cout << "b1 size" << b1.size() << "b2size";//<< b2.size();
// }

void SmartPointerTest()
{
    SmartPointer<int> sp(new int(10));
    SmartPointer<int> sp1(sp);
    SmartPointer<int> sp3(new int(20));
    sp3 = sp;

    std::cout<<"operator* = "<<*sp<<std::endl;
    std::cout<<"use_count"<<sp.use_count()<<std::endl;
}
int main()
{
  SmartPointerTest();
}

