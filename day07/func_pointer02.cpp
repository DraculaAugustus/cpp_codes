/*
函数指针
*/
#include<iostream>
using namespace std;

int add(int x, int y)
{
    return x + y;
}

int main(void)
{
    int a = add(10, 30);
    cout << "result: " << a << endl;
    //定义一个函数指针叫做fp，接收两个int类型的参数，并且返回一个int类型
    int (*fp)(int, int);
    fp = add; //函数指针指向add()方法
    //fp是add()的别名，因此可以用fp来调用add方法
    int b = fp(a, 30);
    cout << "result: " << b << endl;
    return 0;
}