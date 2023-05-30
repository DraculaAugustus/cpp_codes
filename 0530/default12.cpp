#include<iostream>
using namespace std;

//计数一个值的n此方
int power(int a, int n = 2)
{
    int sum = 1;
    for (int i = 0; i < n; i++)
    {
        sum *= a;
    }
    return sum;
}

int main(void)
{
    //使用默认值没有传参
    cout << "2的2次方：" << power(2) << endl;
    cout << "2的3次方：" << power(2, 3) << endl;
    return 0;
}