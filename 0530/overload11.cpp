/*
overload:重载
    函数名相同，
    函数调用时，
    不能用返回值
    */

#include<iostream>
using namespace std;

//返回两个值中较大的值（整型，浮点型，char)
int getMax(int a, int b)
{
    cout << "整数的比较！" << endl;
    return a > b ? a : b;
}

double getMax(double a, double b)
{
    cout << "浮点数的比较！" << endl;
    return a > b ? a : b;
}

char getMax(char a, char b)
{
    cout << "字符的比较！" << endl;
    return a > b ? a : b;
}

int main(void)
{
    cout << getMax(10, 15) << endl;
    cout << getMax(11.3, 11.33) << endl;
    cout << getMax('5', 'u') << endl;

    return 0;
}

