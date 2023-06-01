/*
命名空间
*/
#include<iostream>
using namespace std;

namespace ns
{
    int add(int a, int b)
    {
        return a + b;
    }
    int sub(int a, int b)
    {
        return a - b;
    }
    int multi(int a, int b)
    {
        return a * b;
    }
}

//3)引用命名空间
using namespace ns;
int main(void)
{
    cout << add(2, 3) << endl;
    cout << sub(10, 4) << endl;
    cout << multi(3, 5) << endl;
    return 0;
}

//使用using
using ns::add;
using ns::multi;
using ns::sub;
int main02(void)
{
    cout << add(2, 3) << endl;
    cout << sub(10, 4) << endl;
    cout << multi(3, 5) << endl;
    return 0;
}

int main01(void)
{
    cout << ns::add(2, 3) << endl;
    cout << ns::sub(10, 4) << endl;
    cout << ns::multi(3, 5) << endl;
    return 0;
}