/*
异常：代码偏离正常流程的现象叫做异常。
异常无处不在，肯定会发生。有的是开发者的疏忽造成的，有时是客户传参的问题造成的，还有其它的异常。
常见的异常有哪些？
    1）访问数组的下脚标越界，在越界时又写入了数据。
    2）整数除法时输入为0
    3）通过野指针来操作对象。
    4）用new动态申请内存返回空指针
    5）算术运算溢出
C++解释器是如何处理异常的？
    代码在运行过程中，遇到异常会往外（调用者）抛，如果调用者没有处理异常，该异常会最终抛给main方法。
    如果main方法也没有处理异常，就会中断程序的执行，影响后续正常代码的执行。
如何处理异常？
    异常处理就是在运行时对异常进行检测try，捕获catch，提示，传递throw等操作过程。
    catch()用来捕获异常
        针对异常的类型来捕获，catch(const char *a)，捕获try代码块中抛出的字符串异常
        catch()可以写成一个一个链，用来捕获多种类型的异常
        当不确定抛出的异常具体是什么类型时，catch(...){}可以捕获所有异常，一般放在catch链的最后
        如果上面的catch()捕获异常，并且处理异常后，后面的catch(){}不再捕获
    try(){}用来检测代码块中的是否有异常，和catch一起使用
    throw 抛出异常，抛出的是对象不是类型，可以抛出任意类型的对象。
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int myDiv()
{
    int num1 = 0;
    int num2 = 0;
    cout << "Please enter two number: " << endl;
    cin >> num1 >> num2;
    //如果输入的数据不合格，抛出异常，让调用者处理异常
    if(!(num1>=0&&num1<=100))
    {
        throw "num1的不是数字！";
    }
    else if(num2==0)
    {
        throw "除数为0";
    }
    return num1 / num2;
}

int myDiv02()
{
    int num1 = 0;
    int num2 = 0;
    cout << "Please enter two number: " << endl;
    cin >> num1 >> num2;
    //如果输入的数据不合格，抛出异常，让调用者处理异常
    if(!isdigit(num1))
    {
        throw 1;
    }
    else if(num2==0)
    {
        throw 0;
    }
    return num1 / num2;
}

int main(void)
{
    //从控制台输入两个值，计算两个值的商
    //把可能发生异常的代码块放在try代码块中，
    //try代码块就是用来检测异常的。
    try
    {
        int d = myDiv();
        cout << "两个值相除的结果为：" << d << endl;
    }
    catch (int num1) //catch用来捕获int类型的异常
    {
        cout << "int类型的异常" << num1 << endl;
    }
    catch(const char* num1) //catch用来捕获字符串类型的异常
    {
        cout << "字符串类型的异常" << num1 << endl; //打印异常信息
    }
    catch(...)
    {
        cout << "未知类型的异常，一般放在catch链的最后！" << endl;
    }
    
    
    cout << "计算结束！" << endl;

    // char *p = new char[0xffffffff];
    // for (int i = 0; i < 10;i++)
    // {
    //     *p = 'A';
    // }
    
    // unsigned short a = 65531;
    // unsigned short b = 64321;
    // cout << a << " " << b << endl;
    // cout << a + b << endl;
    return 0;
}

int main01(void)
{
    string s = "hello world!";
    cout << s << endl;
    s[0] = 'H';//可以修改
    // cout << s << endl;
    // s[13] = 'K';
    // cout << s << endl;
    s.at(13) = 'k';
    cout << s << endl;
    cout << "打印后的正常代码！" << endl;

    return 0;
}