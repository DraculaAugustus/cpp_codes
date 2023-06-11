/*
数组中的元素类型不仅可以是基本数据类型，也可以是对象类型，也可以是指针类型。
数组中的元素类型是指针叫做指针数组。int *a[10]={};
数组的创建和初始化
    int a[10] = {1,2,3};
*/
#include <iostream>
using namespace std;
#include "../const03/student.h"
// ../表示是上一级路径

int main(void)
{
    Student *stu[5] = {
        new Student(101, "张三", 17),
        new Student(102, "李四", 18),
        new Student(103, "王五", 19),
        new Student(104, "赵六", 17),
        new Student(105, "宋钱", 19)};
    int sum = 0;
    //修改下脚标为1的对象
    delete stu[1];
    stu[1] = new Student(106, "李三", 17);
    for (int i= 0; i < 5; i++)
    {
        //stu[i]是一个指针，指向Student对象
        stu[i]->show();
        sum += stu[i]->getAge();
    }
    cout << "平均年龄为：" << ((double)sum / 5) << endl;

    //遍历数组，析构对象
    for (int i = 0; i < 5;i++)
    {
        delete stu[i];
    }
    return 0;
}

int main01(void)
{
    Student stu[5] = {Student(101, "张三", 17),
                      Student(102, "李四", 18),
                      Student(103, "王五", 19),
                      Student(104, "赵六", 17),
                      Student(105, "宋钱", 19)};
    int sum = 0;//存放年龄的和
    for (int i = 0; i < 5;i++)
    {
        //用下脚标获取每一个对象stu[i]
        stu[i].show();
        sum += stu[i].getAge();
    }
    //计算平均年龄
    cout << "平均年龄：" << ((double)sum) / 5 << endl;

    return 0;
}