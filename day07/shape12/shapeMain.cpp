/*
计算圆和圆和长方形的面积。
    POP：面向过程的开发模式。
        以功能为中心，专注于功能的实现。把整个需求分解成若干个步骤，
        每个步骤定义一个函数，通过函数的逐步调用来实现整个需求。
        完成简单的需求开发起来比较简单，更符合人类的思维。
        不利于维护和扩展。
    OOP：面向对象的开发模式。
        将整个需求涉及到的事物伪装为对象，然后把对象的操作封装为函数（方法）
        将这些对象协作完成我们的需求。
        面向对象的最小单位：类
        缺点：对于简单问题也需要好几个文件。
        优点：易于维护和扩展。保护对象的数据不能随便修改。
*/
#include <iostream>
#include "point.h"
#include "circle.h"
#include "rectangle.h"
using namespace std;

int main(void)
{
    Point point{5, 7};
    showPoint(point);

    Circle c{{0, 1}, 3};
    showCircle(c);
    cout << "圆的面积：" << circleArea(c) << endl;
    cout << "圆的周长：" << circlePerimeter(c) << endl;

    Rectangle rect{{3, 4}, 5, 2};
    showRectangle(rect);
    cout << "长方形的面积：" << rectArea(rect) << endl;
    cout << "长方形的周长：" << rectPerimeter(rect) << endl;
    return 0;
}