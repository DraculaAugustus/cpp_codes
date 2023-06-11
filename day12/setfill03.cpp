/*
设置填充
    1)在设置域宽后，输出的字符宽度小于域宽时的填充，默认是用空格填充
    2)设置后永久有效，直到被修改
    3)char c=cout.fill('新填充符');
        返回设置之前的填充符，默认填充符是空格。
    流控制符 setfill()
    成员函数 fill()
*/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main(void)
{
    double values[] = { 1.23, 15.16, 653.7, 4358.24, 2769.34 };
    //返回以前设置的填充
    char f = cout.fill('*');
    cout << "以前的填充符:" << f << "what it is?" << endl;
    for (int i = 0; i < 5;i++)
    {
        cout.width(10);//域宽=10
        cout << values[i] << endl;
    }
    f = std::cout.fill(f);//设置为以前的填充方式
    cout << "以前的填充符:" << f << "what it is?" << endl;
    for (int i = 0; i < 5;i++)
    {
        cout.width(10);//域宽=10
        cout << values[i] << endl;
    }
    return 0;
}

int main01(void)
{
    double values[] = { 1.23, 15.16, 653.7, 4358.24, 2769.34 };
    //数字右对齐，用*填充
    cout.fill('*');
    for (int i = 0; i < 5; i++)
    {
        cout << setw(7) << values[i] << endl;
    }
        return 0;
}