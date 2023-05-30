/*
函数：把完成一定功能的相关操作封装成一个函数，提高代码的重复性和可读性。
1） 函数类型
    返回值类型
    函数可以有返回值也可以没有返回值
    没有返回值时，函数类型为void
2） 函数名要符合标识符规则
3） 函数参数
    函数定义的括号内：形参
        形参的名字是任意，类型和实参一致。
        形参可以有多个，用逗号分割
    
*/
#include<iostream>
using namespace std;
//return max
int maxNum(int x, int y)
{
    if(x>y)
    {
        return x;
    }
    return y;
}
//1-n的求和
int getSum(int n)
{
    //函数体实现求和
    int sum = 0; //存放求和结果
    for (int i = 0; i <= n; i++)
    {
        sum += i; // sum = sum + i;
    }
    return sum;
}
int main()
{
    //定义变量s, 接收函数的执行结果
    //int s = getSum(50);
    //cout << "1-50的求和结果：" << s << endl;

    cout << "Please enter two number: " << endl;
    int a, b;
    cin >> a >> b;
    int max = maxNum(a, b);
    cout << "Max number is: " << max << endl;
    
    return 0;
}