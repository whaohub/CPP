# ifndef __SINGLETON__H__
# define  __SINGLETON__H__
/*
普通单例模式 --- 线程不安全
*/
class Singleton
{
public:
	static Singleton* getIntance();
	static void deleteIntance();
	void print()const;
private:
	Singleton();
	~Singleton();
	Singleton(const Singleton&);
	const Singleton& operator=(const Singleton&);

	static Singleton* m_obj;
};
# endif
