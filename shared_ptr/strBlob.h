#ifndef __STRBLOB__H__
#define __STRBLOB__H__
#include <iostream>
#include <vector>
#include <memory>

/*
	��ĿǰΪֹ������ʹ�õ����У��������Դ�����Ӧ����������һ�¡�
	���磬ÿ��vectorӵ�����Լ���Ԫ�أ������ǿ���һ��vectorʱ��ԭvector��
	�������໥�����
*/
//void print()
//{
//	std::vector<std::string> v1;
//	{
//		std::vector<std::string>v2 = {"a"};
//		v1 = v2;
//	}//v2�����٣���ԴҲ������
//	std::cout << v1.at(0) << std::endl;
//}
/*
*   Ҫ��������������ͬ��״̬��ʹ�ö�̬�ڴ�
	ʵ��һ���µļ������͵���򵥷�����ʹ��ĳ����׼������������Ԫ�ز������ַ��������ǿ��Խ�����׼��
	����������Ԫ����ʹ�õ��ڴ�ռ䡣
*/
class StrBlob
{
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	//Ԫ�ظ���
	size_type size()const { return m_dataSptr->size(); }
	//�Ƿ�Ϊ��
	bool empty()const { return m_dataSptr->empty(); }
	//���ɾ��Ԫ��
	void push_back(const std::string& str) { m_dataSptr->push_back(str); }
	void pop_back();

	std::string& front();
	std::string& back();
	const std::string& front()const;
	const std::string& back()const;

private:
	std::shared_ptr<std::vector<std::string>> m_dataSptr;
	//��Ϊ size_type ��һ���޷������ͣ������ݸ� check �Ĳ���С�� 0 ��ʱ�򣬲���ֵ��ת����һ����������
	void check(size_type i, const std::string &msg)const;

	/*
	* Ϊʲô���ǲ�ֱ������д������const�ĺ�����������дһ��С����do_front() or do_back()��ԭ���ĺ����������أ�

ԭ�����£�

1�����ȵ�Ȼ�Ǳ���ദ���������ˣ�������Ȼֻ��һ�����������ã�������ϰ�����Ǻõģ�������Ĺ�ģ��չ������д�ĺô������ԵĶ��ˡ�

2�����С�����������ڲ�����ģ��������ʽ�ر�����Ϊ������������˵���������������������ʱ������

����Ҳ˵����ʵ���У�������õ�C++���볣����������������С������ͨ��������ЩС������������������ġ�ʵ�ʡ�����

��֮��������ڹ�������ʹ��˽�й��ܺ���
	*/
	std::string& rtnFront()const { check(0, "front on empty strBlob"); return m_dataSptr->front(); }
	std::string& rtnBack()const { check(0, "back on empty strBlob"); return m_dataSptr->back(); }
};
#endif
