/*
命名空间：避免标识符的名字冲突
    程序大到一定程度，通常分成多个子项目，每个子项目分别由不同的人或者组来完成，
    因此，多人协作的开发模式很难保证标识符的命名问题。
    为了避免名称冲突的问题，C++引入了命名空间（名称空间），
    开发者只需要保证在同一个命名空间下名称不冲突即可。

调用不同命名空间下的函数，使用域操作符::,
如果使用同一个命名空间下的多个函数，都需要添加::，比较麻烦
*/
#include<iostream>
using namespace std;

//函数可以先声明，然后定义
int add(int a, int b);

//说明一个命名空间 ns1
namespace ns1
{
    //在该命名空间下所有的函数，变量不要冲突
    int fun(int x, int b);
}

namespace ns2
{
    int fun(int x, int y);
    namespace ns3
    {
        int fun(int x, int y);
    }
}

int main(void)
{
    cout << ns1::fun(2, 3) << endl;
    cout << ns2::fun(20, 30) << endl;
    cout << ns2::ns3::fun(200, 300) << endl;
    return 0;
}

//定义函数
int add(int a, int b)
{
    return a + b;
}

//是命名空间ns1下的fun方法
int ns1::fun(int x, int y)
{
    cout << "命名空间ns1." << endl;
    return x + y;
}
//是命名空间ns2下的fun方法
int ns2::fun(int x, int y)
{
    cout << "命名空间ns2." << endl;
    return x + y;
}
//是命名空间ns3下的fun方法
int ns2::ns3::fun(int x, int y)
{
    cout << "命名空间ns3." << endl;
    return x + y;
}