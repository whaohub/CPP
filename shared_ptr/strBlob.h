#ifndef __STRBLOB__H__
#define __STRBLOB__H__
#include <iostream>
#include <vector>
#include <memory>

/*
	到目前为止，我们使用的类中，分配的资源都与对应对象生存期一致。
	例如，每个vector拥有其自己的元素，当我们拷贝一个vector时，原vector和
	副本是相互分离的
*/
//void print()
//{
//	std::vector<std::string> v1;
//	{
//		std::vector<std::string>v2 = {"a"};
//		v1 = v2;
//	}//v2被销毁，资源也被销毁
//	std::cout << v1.at(0) << std::endl;
//}
/*
*   要允许多个对象共享相同的状态，使用动态内存
	实现一个新的集合类型的最简单方法是使用某个标准库容器来管理元素采用这种方法，我们可以借助标准库
	类型来管理元素所使用的内存空间。
*/
class StrBlob
{
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	//元素个数
	size_type size()const { return m_dataSptr->size(); }
	//是否为空
	bool empty()const { return m_dataSptr->empty(); }
	//添加删除元素
	void push_back(const std::string& str) { m_dataSptr->push_back(str); }
	void pop_back();

	std::string& front();
	std::string& back();
	const std::string& front()const;
	const std::string& back()const;

private:
	std::shared_ptr<std::vector<std::string>> m_dataSptr;
	//因为 size_type 是一个无符号整型，当传递给 check 的参数小于 0 的时候，参数值会转换成一个正整数。
	void check(size_type i, const std::string &msg)const;

	/*
	* 为什么我们不直接重新写两个有const的函数，反而是写一个小函数do_front() or do_back()让原来的函数调用它呢？

原因如下：

1、首先当然是避免多处代码重用了，现在虽然只是一两处代码重用，但养成习惯总是好的，随着类的规模发展，这样写的好处就明显的多了。

2、这个小函数是在类内部定义的，因此它隐式地被声明为内联函数，因此调用它不会带来额外的运行时开销。

书上也说，在实践中，设计良好的C++代码常常包含大量的这种小函数，通过调用这些小函数来完成其他函数的“实际”工作

总之，建议对于公共代码使用私有功能函数
	*/
	std::string& rtnFront()const { check(0, "front on empty strBlob"); return m_dataSptr->front(); }
	std::string& rtnBack()const { check(0, "back on empty strBlob"); return m_dataSptr->back(); }
};
#endif
