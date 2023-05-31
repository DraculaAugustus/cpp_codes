/*
函数的调用
1)C++中每一个函数都是独立的，不能嵌套定义（一个函数体内定义另一个函数）
2)C++中函数可以嵌套调用

递归：自己调用自己
递归三要素：
1) 确定函数完成了什么功能（入参和返回值分别是什么）
2) 终止条件
3) 递推公式
能用递归实现的，一般都可以用循环的方式实现，只不过递归的代码更简单
递归的缺点：
1) 产生重复计算的问题；
2) 递归的深度比较深时，会有栈内存溢出。
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