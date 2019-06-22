
//啥样的对象能放到 vector 里面
//1. 能拷贝
//2. 支持移动语义
//
//啥样的对象能放到 List 里面
//1. 和vector 相同
//
//啥用的对象 能放到 deque 里面
//1. 和 vector 相同
//
//啥样的对象 能放到 是std::array 中
//1. 和 vector 相同
//
// std::set：
// 1. 能拷贝
// 2. 能比较
//
// std::map
// key 能拷贝 能比较
// value 能拷贝就行
//
// std::unordered 
// key 能拷贝 能比较相等 能哈希
// value 能拷贝就行

#include <iostream>
#include <vector>


class Test {

public:
    Test()
    {

    }

    //&& 右值引用
    ////转移构造函数
    //体现了 C++ 11 中的 “ 移动语义“
    Test(Test&&){

    }
private:
    Test(const Test&a);
};

int main()
{
    std::vector<Test> v;
    Test t;
    v.push_back(t);
    return 0;
}
