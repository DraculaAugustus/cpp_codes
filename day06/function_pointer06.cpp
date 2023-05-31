/*
指针参数：
    实参是数组时，形参是指针类型，是指向数组的第一个元素的指针。
    数组作为参数传递给函数时，弱化成了指针，无法计数得到数组的长度，需要用参数的形式传给函数。
*/

#include<iostream>
using namespace std;

//定义一个函数，实现数组元素的翻转
void reverseArray(int *p, int n)
{
    //计数数组的长度
    //int len = sizeof(p) / sizeof(int);
    //cout << "数组的长度：" << len << endl;

    int *i, *j; // i指向数组的第一个元素，j指向数组的最后一个元素
    int temp; // 交换使用的临时变量
    for (i = p, j = p + n - 1; i < j; i++, j--)
    {
        // 交换i和j所指的变量的值
        temp = *i;
        *i = *j;
        *j = temp;
    }
}
int main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //计数数组的长度
    int len = sizeof(a) / sizeof(int);
    cout << "数组的长度：" << len << endl;
    reverseArray(a, len);
    // 打印数组
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << "   ";
    }
    cout << endl;
    return 0;
}