/*
函数参数：数值作为函数的参数
*/
#include<iostream>
using namespace std;
//exchange two number varluable
//值传递：把实参复制一份给形参，因此，形参的变化不会影响实参
void mySwap(int x, int y)
{
    cout << "before: x = " << x << "    y = " << y << endl;
    int temp = x;
    x = y;
    y = temp;
    cout << "after: x = " << x << "    y = " << y << endl;
}

//地址传递：通过指针解引用*x, *y, 操作的是函数外的实参a, b的值
void mySwap_ptr(int *x, int *y)
{
    cout << "function before: x = " << *x << "    y = " << *y << endl;
    int temp = *x;
    *x = *y;
    *y = temp;
    cout << "function after: x = " << *x << "    y = " << *y << endl;
}

//引用传递：形参x, y变化时影响了实参
void mySwap_ref(int &x, int &y)
{
    cout << "function before: x = " << x << "    y = " << y << endl;
    int temp = x;
    x = y;
    y = temp;
    cout << "function after: x = " << x << "    y = " << y << endl;
}

int main()
{
    int a = 10;
    int b = 50;
    cout << "before: a = " << a << "    b = " << b << endl;

    // 调用后，a = 50, b = 10;
    //mySwap(a, b);
    //mySwap_ptr(&a, &b);
    mySwap_ref(a, b);
    cout << "after: a = " << a << "    b = " << b << endl;

    return 0;
}