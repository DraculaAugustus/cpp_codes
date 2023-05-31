/*
函数的调用
1)
2)

已知第一个人...
*/
#include<iostream>
using namespace std;

//斐波那契数列
//0,1,1,2,3,5,8,13,21...
//计算斐波那契数列第n位上的值
int fibo(int n)
{
    if(n <= 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

//递归
int getAge(int n)
{
    //1)终止条件
    if(n == 1)
    {
        return 20;
    }
    //2)递推公式
    return getAge(n - 1) + 2;
}

int main(void)
{
    int a = getAge(10);
    cout << "NO.10 age is " << a << "years" << endl;

    int b = fibo(9);
    cout << "斐波那契数列第9为的值为：" << b << endl;
    return 0;
}