/*
内联函数：inline修饰的函数。
    函数提高了代码的重用性和可读性，但是降低了程序的执行效率。

    inline只是说明该函数为内联函数，到底是不是内联函数要看编译器是不是把他当作内联函数。
    */

#include<iostream>
using namespace std;

//定义一个内联函数，实现两个值相加
inline int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int a = 10, b = 20, c;
    c = add(a, b);
    cout << "c = " << c << endl;

    c = add(100, 200);
    cout << "c = " << c << endl;

    return 0;
}