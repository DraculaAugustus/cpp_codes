/*
结构体数组与结构体指针
    指针访问结构体属性  指针->属性名
    非指针变量访问结构体属性    变量.属性名
*/
#include<iostream>
using namespace std;

struct Student
{
    //属性类型  属性名
    int no; //id
    char name[10];
    char gender; //sex
    int age;
    float score;
};

//求平均成绩
double avgScore(Student *p, int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        //(p+i)是指向第i个学生的指针
        sum += (p + i)->score;
    }
    return sum / n;
}

int main(void)
{
    //用结构体数组存储班级所有学生的信息
    Student s[5] = {{2023001, "王一", 'M', 23, 89.7},
                    {2023002, "甜妞", 'W', 20, 88.7},
                    {2023003, "可可", 'W', 21, 99.7},
                    {2023004, "赵莉", 'W', 20, 89.3},
                    {2023005, "冯珂", 'M', 23, 82.6}};
    //计算平均成绩
    double sum = 0.0;
    for (int i = 0; i < 5; i++)
    {
        sum += s[i].score;
    }
    cout << "平均成绩为：" << sum / 5 << endl;
    cout << "平均成绩为：" << avgScore(s, 5) << endl;
    return 0;
}