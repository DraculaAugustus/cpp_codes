/*
引用: 在程序中定义的每个变量都有一个存储单元，
    变量的名字就是存储单元的名字。
    引用就是该存储单元的别名。
    一般用于函数的形参和返回值上。
    1)  int &b = a;
        类型 地址运算符 引用名=变量名;
    2)  引用b和变量a指的是同一块内存。
    3)  引用在初始化
*/
#include<iostream>
using namespace std;
int main()
{
    int a = 10;
    // 1)引用定义时必须初始化
    // int &b;
    int &b = a;

    //2)引用在初始化后是不可改变的（可以把引用看作指针常量，指向不能变，值可以变
    int c = 50;
    b = c;
    cout << a << "  " << b << " " << c << endl;

    //3)只能引用变量，不能引用常量
    //int &d = 50;
    system("pause");
    return 0;
}
int main1()
{
    int a = 20;
    int &b = a;
    cout << a << "  " << b << endl;

    //a和b指的是同一块内存，a变了
    a = 50;
    cout << a << "  " << b << endl;

    b = 100;
    cout << a << "  " << b << endl;
    system("pause");
    return 0;
}