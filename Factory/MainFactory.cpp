// 工厂方法模式 2020.8.9 by Whao
/*
  相对于简单工厂模式，简单工厂模式在工厂类中增加了必要的逻辑判断，根据客户端选择的条件动态的去
  实例化相关的类，但是如果需要增加新的功能时就需要去修改原有的工厂类，不符合 开放封闭原则，
  而工厂方法模式，只需要在原有操作和工厂中添加相应的类。
*/

#include <iostream>
#include "MainFrom.h"
#include "Operation.h"
int main()
{
    AddFactory *addFactory = new AddFactory();
    SubFactory *subFactory = new SubFactory();  //new 要调用delete ，使用了智能指针管理
    MainForm mainForm(addFactory);
    MainForm mainForm1(subFactory);
    mainForm.PrintTest();
    mainForm1.PrintTest();

}
    


