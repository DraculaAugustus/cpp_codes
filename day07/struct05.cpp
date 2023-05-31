/*
结构体的嵌套
*/
#include<iostream>
using namespace std;
#include<cstring>

struct date
{
    int year;
    int month;
    int day;
};

struct Student
{
    //属性类型  属性名
    int no; //id
    char name[10];
    char gender; //sex
    date birthday;
    int age;
    float score;
};

int main(void)
{
    Student s{2023007, "zhangsan", 'm', {2000, 5, 13}, 22, 89.7};
    cout << "学号：" << s.no << endl;
    cout << "姓名：" << s.name << endl;
    cout << "性别：" << s.gender << endl;
    cout << "出生日期：" << s.birthday.year << "年" << s.birthday.month << "月" << s.birthday.day << "日" << endl;
    cout << "年龄：" << s.age << endl;
    cout << "成绩：" << s.score << endl;

    return 0;
}