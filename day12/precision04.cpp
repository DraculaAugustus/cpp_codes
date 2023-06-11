/*
设置精度：小数部分和整数部分位数的和，不含小数点
            如果整数部分超出了精度，科学计数法
            如果整数部分小于精度，整数+小数超出精度，截取小数部分。
            设置是永久性的，直到被修改。
            int p=cout.precison(新精度);
            返回设置之前的精度。
    流控制符 setprecision()
    成员函数 precsion()
*/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// int main(void)
// {
//     const double PI = 3.1415926535;
//     const double e = 2.718281828;
//     //返回设置之前的精度
//     int p = cout.precision(9);
//     cout << PI << ", " << e << endl;
//     cout << "之前的精度：" << p << endl;
//     //恢复精度
//    p = cout.precision(p);
//     cout << PI << ", " << e << endl;
//     cout << "之前的精度：" << p << endl;
//     return 0;
// } 

int main(void)
{
    //默认输出的精度
    const double PI = 3.1415926535;
    cout << "默认精度是6：" << PI << endl;
    //设置精度是永久的，直到被改变
    cout << setprecision(9);
    cout << PI << endl;
    cout << 12345678.902 << endl;
    cout << 1234567890.123 << endl;
    return 0;
}