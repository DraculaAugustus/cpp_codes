/*
枚举类：符合常量的集合
*/
#include<iostream>
using namespace std;

//定义一个枚举类，枚举元素的起始值默认从0开始，依次加1
//enum weekday{Sun,Mon,Tue, Wed,Thu, Fri,Sat};//Sun=0,Mon=1,2,3,4,5,6
//可以显示指定某个元素的值，则下一个枚举类型的值如果没有指定，就是上一个枚举类型值+1
enum weekday{Sun = 7,Mon = 1,Tue,Wed,Thu,Fri,Sat};


int main(void)
{
    //从
    int day;
    cout << "请输入[1-7]的整数：";
    cin >> day;
    //定义一个枚举变量
    weekday d = (weekday)day;
    switch(d) //switch后面的数据类型：整型，字符型，枚举型
    {
        case Sun:
            cout << "今天是星期日！" << endl;
            break;
        case Mon:
            cout << "今天是星期一！" << endl;
            break;
        case Tue:
            cout << "今天是星期二！" << endl;
            break;
        case Wed:
            cout << "今天是星期三！" << endl;
            break;
        case Thu:
            cout << "今天是星期四！" << endl;
            break;
        case Fri:
            cout << "今天是星期五！" << endl;
            break;
        case Sat:
            cout << "今天是星期六！" << endl;
            break;
        default:
            cout << "输入有误" << endl;
            break;
    }
    return 0;
}