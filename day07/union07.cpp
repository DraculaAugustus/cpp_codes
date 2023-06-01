/*
联合体
联合体所占用的内存字节数和最大成员占用内存字节数相等。
在使用时只需要给一个属性赋值即可，其它的属性就都有值。
*/
#include<iostream>
using namespace std;

//定义联合体
union my_data
{
    int i;
    char ch;
    float f;
};

int main(void)
{
    //定义联合体变量
    my_data d;
    d.i = 97;
    cout << "整型i: " << d.i << endl;
    cout << "字符型ch: " << d.ch << endl;
    cout << "浮点型f: " << d.f << endl;

    d.ch = 'A';
    cout << "整型i: " << d.i << endl;
    cout << "字符型ch: " << d.ch << endl;
    cout << "浮点型f: " << d.f << endl;

    d.f = 100;
    cout << "整型i: " << d.i << endl;
    cout << "字符型ch: " << d.ch << endl;
    cout << "浮点型f: " << d.f << endl;

    cout << "d的内存大小：" << sizeof(d) << endl;
    cout << "整型的内存：" << sizeof(d.i) << endl;
    cout << "字符型的内存：" << sizeof(d.ch) << endl;
    cout << "浮点型d内存：" << sizeof(d.f) << endl;

    return 0;
}