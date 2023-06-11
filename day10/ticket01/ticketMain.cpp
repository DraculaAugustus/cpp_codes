/*
1)动态多态的三要素
    a.父类的方法是virtual修饰
    b.子类重写父类的虚函数
    c.父类的指针指向子类的对象
2)虚函数分文件定义时，只需要在头文件用virtual修饰
*/
#include <iostream>
#include "ticket.h"
using namespace std;

int main(void)
{
    Person **pers = new Person*[3];
    pers[0] = new Person();
    pers[1] = new Student();
    pers[2] = new Solder();
    for (int i = 0; i < 3; i++)
    {
        pers[i]->saleTicket();
    }
    delete[] pers;
    return 0;
}

int main01(void)
{
    //声明一个长度是3的数组，实例化为不同的人，让他们去买票
    Person *pers[3];    //指针数组
    //栈中存储三个人
    Person p1;
    Student p2;
    Solder p3;
    pers[0] = &p1;
    pers[1] = &p2;
    pers[2] = &p3;
    //遍历数组，实现每个人都去买票
    for (int i = 0; i < 3; i++)
    {
        pers[i]->saleTicket();
    }

    return 0;
}
