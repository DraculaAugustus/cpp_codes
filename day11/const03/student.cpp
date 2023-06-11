#include "student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student(int number, const char *name, int age)
{
    this->number = number;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->age = age;
}
Student::~Student()
{
    if(name != nullptr)
    {
        delete[] this->name;
    }
    cout << "Student析构！" << endl;
}
Student::Student(const Student &stu)
{
    this->number = stu.number;
    this->name = new char[strlen(stu.name) + 1];
    strcpy(this->name, stu.name);
    this->age = stu.age;
}
void Student::setNumber(int number)
{
    this->number = number;
}
void Student::setName(const char *name)
{
    if(this->name != nullptr)
    {
        delete[] this->name;
    }
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
void Student::setAge(int age)
{
    this->age = age;
}
int Student::getNumber() const
{
    return this->number;
}
char * Student::getName() const
{
    return this->name;
}
int Student::getAge() const
{
    return this->age;
}
void Student::show() const
{
    cout << "学号：" << this->number << "姓名：" << this->name << "年龄：" << this->age << endl;
}