#include "person.h"
#include <iostream>
#include <cstring>
using namespace std;

Person::Person(const char *name, int age)
{
    m_sName = new char[strlen(name) + 1];
    strcpy(m_sName, name);
    m_nAge = age;
    cout << "Person的构造函数！" << endl;
}
Person::~Person()
{
    if(m_sName != nullptr)
    {
        delete[] m_sName;
    }
    cout << "Person的析构函数！" << endl;
}
void Person::showPerson()
{
    cout << "姓名：" << m_sName << "，年龄：" << m_nAge;
}

Student::Student(const char *name, int age, const char *major):Person(name, age)
{
    m_sMajor = new char[strlen(major) + 1];
    strcpy(m_sMajor, major);
    cout << "Student构造函数！" << endl;
}
Student::~Student()
{
    if(m_sMajor != nullptr)
    {
        delete[] m_sMajor;
    }
    cout << "Student析构函数！" << endl;
}
void Student::showStudent()
{
    showPerson();
    cout << "，专业：" << m_sMajor << endl;
}

Teacher::Teacher(const char *name, int age, const char *title):Person(name, age)
{
    m_sTitle = new char[strlen(title) + 1];
    strcpy(m_sTitle, title);
    cout << "Teacher构造函数！" << endl;
}
Teacher::~Teacher()
{
    if(m_sTitle != nullptr)
    {
        delete[] m_sTitle;
    }
    cout << "Teacher析构函数！" << endl;
}
void Teacher::showTeacher()
{
    showPerson();
    cout << "，职称：" << m_sTitle << endl;
}