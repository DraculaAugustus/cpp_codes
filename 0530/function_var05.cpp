/*
值传递和引用传递的区别：
    1)  对实参只是参与运算没有做修改，值传递和引用传递都可以。
    2)  引用传递的调用只能用变量，不能用常量和表达式。
        而值传递的调用，可以用变量，常量和表达式。
    3)  值传递的形参是对实参的复制，引用传递函数内使用的就是实参
        当参数是复杂类型（类，结构体，数组）时，引用传递会节省时间和空间。
*/

#include<iostream>
using namespace std;
#define PI 3.1415926

//计数圆面积
double area01(int r)
{
    return PI * r * r;
}

//引用类型的形参
double area02(int &r)
{
    return PI * r * r;
}

int main(void)
{
    cout << "值传递，2的面积：" << area01(2) << endl;
    int a = 5;
    cout << "值传递，5的面积：" << area01(a) << endl;

    int b = 2;
    cout << "引用传递，2的面积：" << area02(b) << endl;
    return 0;
}