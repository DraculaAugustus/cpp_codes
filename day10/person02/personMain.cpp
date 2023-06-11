/*
虚析构:
    Person(姓名，年龄)      showPerson()
    Student继承Person(专业)     showStudent()
    Teacher继承Person(职称)     showTeacher()

    写析构函数时定义成虚析构，否则，只析构父类不析构子类，
    子类中的堆中属性没有被析构，造成内存溢出。
*/
#include <iostream>
using namespace std;
#include "person.h"

int main(void)
{
    //针对接口编程，父类的类型指向子类的指针
    //问题: 没有调用子类的析构函数，子类的属性没有析构
    Person *p1 = new Student("Mary", 8, "英语");
    p1->showPerson();
    cout << endl;
    delete p1;
    cout << "------------------" << endl;

    Person *t = new Teacher("张老师", 20, "副教授");
    t->showPerson();
    cout << endl;
    delete t;

    return 0;
}