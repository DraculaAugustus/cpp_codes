#include "student.h"
#include <iostream>
using namespace std;

int main(void)
{
    //定义常对象，只能访问常成员函数
    //常量指针：指针指向的对象不能修改，指针的指向可以修改
    Student const *stu = new Student(101, "李四", 15);
    int age = stu->getAge();
    char *name = stu->getName();
    int n = stu->getNumber();
    cout << n << ", " << name << ", " << age << endl;
    stu->setNumber(18);
    delete stu;
    return 0;
}

int main01(void)
{
    //定义普通的对象，能调用成员函数和普通成员函数
    Student *zhangsang = new Student(100, "张三", 19);
    zhangsang->show();
    zhangsang->setAge(21);
    zhangsang->show();
    delete zhangsang;
    return 0;
}