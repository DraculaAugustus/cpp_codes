/*
结构体：
    存储一个学生的信息，姓名char[], no, age(int), score(doble)
    struct 结构体名称{属性类型 属性名;};
    1)结构体的大小=每个属性之和
    2)初始化一：
        属性是char name[20]; 赋值strcmp(name, "")
        其它*/
#include<iostream>
using namespace std;
#include<cstring>

//定义结构体
typedef struct Student
{
    //属性类型  属性名
    int no; //id
    char name[10];
    char gender; //sex
    int age;
    float score;
}Stu;

int main(void)
{
    Stu s1;
    s1.age = 20;
    cout << "年龄：" << s1.age << endl;
    return 0;
}

//结构体赋初始值，可以用名称.属性
//也可以用c++11的统一初始化方式
int main02(void)
{
    Student s1{2023, "张三", 'm', 20, 90.4};
    //获取属性值并打印
    cout << "学号：" << s1.no << endl;
    cout << "姓名：" << s1.name << endl;
    cout << "性别：" << s1.gender << endl;
    cout << "年龄：" << s1.age << endl;
    cout << "成绩：" << s1.score << endl;

    return 0;
}

int main01()
{
    //定义一个学生（定义一个Student类型的变量）
    Student s1;
    //初始化学生，（给结构体的属性赋初始值）
    s1.no = 2023005;
    strcpy(s1.name, "zhangsan");
    s1.gender = 'm';
    s1.age = 18;
    s1.score = 78.9;
    //获取属性值并打印
    cout << "学号：" << s1.no << endl;
    cout << "姓名：" << s1.name << endl;
    cout << "性别：" << s1.gender << endl;
    cout << "年龄：" << s1.age << endl;
    cout << "成绩：" << s1.score << endl;

    //结构体的存储
    cout << "结构体的内存：" << sizeof(s1) << endl;
    return 0;
}