/**/
#include <iostream>
#include "divException05.cpp"
using namespace std;

//两个数相除
void func1()
{
    int a = 0, b = 0;
    cout << "请输入两个100以内的整数：";
    cin >> a >> b;
    if(b==0)
    {
        //抛出一个异常的对象
        DivException e(1, "除数为0！");
        throw e;
    }
    cout << a << "除以" << b << "的结果为：" << a / b << endl;
}

void func2()
{
    try
    {
        cout << "func2()的开始代码" << endl;
        func1();
        cout << "func2()的结束代码" << endl;
    }
    catch(const DivException &e)
    {
        cout << "func2()的错误信息：" << e.what() << endl;
    }
    catch(...)
    {
        cout << "func2的未知异常！" << endl;
    }
    
}

int main(void)
{
    // try
    // {
    //     func2();
    // }
    // catch(const DivException &e)
    // {
    //     cout << "错误描述信息：" << e.what() << endl;
    // }
    // catch(...)
    // {
    //     cout << "未知异常！" << endl;
    // }
    func2();
    cout << "调用后的正常代码！" << endl;
    return 0;
}