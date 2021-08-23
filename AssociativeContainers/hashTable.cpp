#include <hash_set>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <hashtable.h>
#include <bits/stl_function.h>
#include <hash_fun.h>
#include <ext/functional>

using namespace std;
using namespace __gnu_cxx;
//hashtable中元素比较函数
struct eqstr
{
    bool operator()(const char *str1, const char *str2) const
    {
        return (strcmp(str1, str2) == 0);
    }
};

void hashTest()
{
    hashtable<int,
              int,
              __gnu_cxx::hash<int>,
              identity<int>,
              equal_to<int>>
        ht(50, __gnu_cxx::hash<int>(), equal_to<int>());

    std::cout << "ht.size() =" << ht.size() << std::endl;             //元素个数
    cout << "bucket_count() = " << ht.bucket_count() << endl;         //桶子个数（质数）
    cout << "max_bucket_count() = " << ht.max_bucket_count() << endl; //最大桶子个数

    ht.insert_unique(59);
    ht.insert_unique(63);
    ht.insert_unique(108);
    ht.insert_unique(2);
    ht.insert_unique(53);
    ht.insert_unique(55);

    cout << "inserted size() =" << ht.size() << endl;

    //声明一个迭代器
    hashtable<int,
              int,
              __gnu_cxx::hash<int>,
              identity<int>,
              equal_to<int>>::iterator ite = ht.begin();

    for(int i = 0; i < ht.size(); ++i,++ite)   //打印所有节点
    {
        cout<<"value = "<<*ite << ' ';
    }
    cout<<endl;

    //遍历所有buckets,如果其节点个数不为0，就打印出节点个数
    for(int i = 0; i < ht.bucket_count(); ++i)
    {
        int num = ht.elems_in_bucket(i); 
        if(num != 0)
        {
            cout<<"bucket["<<i<<"] has"<<num<<"elems."<<endl;
        }
    }

    //验证re_hashing,可重复，原先6个元素，再增加48
    for(int i = 0;i <= 47;++i)
    {
        ht.insert_equal(i);  
    }
    std::cout << "ht.size() =" << ht.size() << std::endl;             //元素个数
    cout << "bucket_count() = " << ht.bucket_count() << endl;

    //遍历所有buckets,如果其节点个数不为0，就打印出节点个数
    for(int i = 0; i < ht.bucket_count(); ++i)
    {
        int num = ht.elems_in_bucket(i); 
        if(num != 0)
        {
            cout<<"bucket["<<i<<"] has"<<num<<"elems."<<endl;
        }

    }

    ite = ht.begin();

    for(int i = 0; i < ht.size(); ++i,++ite)   //打印所有节点
    {
        cout<<"value = "<<*ite << ' ';
    }
    cout<<endl;

    cout<<"find 2"<<*(ht.find(2))<<endl;
    cout<<"count 2"<<ht.count(2)<<endl;
}

int main(int argc, char **argv)
{
    hashTest();
    return 0;
}