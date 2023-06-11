/*
Circle圆类，数据（属性）int x, int y, double radius
方法 showCircle()   getArea()   getPerimeter()
*/
#include <iostream>
using namespace std;
//#define PI 3.1415926

class Circle
{
    private:
        int x;
        int y;
        double radius;
        const double PI;

    public:
        //构造函数，是初始化对象时调用，用于给属性赋初值
        Circle(int tx, int ty, double r):PI(3.1415926)
        {
            //把参数赋值给类内的属性
            x = tx;
            y = ty;
            radius = r;
            cout << "3个参数的构造函数！" << endl;
        }
        //构造函数用初始化列表的方式，给属性赋初始值
        Circle(int tx, int ty) : x(tx), y(ty),PI(3.1415926){}
        Circle():PI(3.1415926){}
        void setRadius(double r)
        {
            radius = r;
        }
        void showCircle();
        double getArea();
        double getPerimeter();
};

int main04(void)
{
    Circle *c = new Circle(2,5);
    c->setRadius(10);
    c->showCircle();
    cout << "面积：" << c->getArea() << endl;
    cout << "周长：" << c->getPerimeter() << endl;
    delete c;
    return 0;
}

int main03(void)
{
    Circle c;
    c.setRadius(10);
    cout << "面积：" << c.getArea() << endl;
    return 0;
}

int main(void)
{
    Circle *c = new Circle(1,3,7);
    c->showCircle();
    cout << "面积：" << c->getArea() << endl;
    cout << "周长：" << c->getPerimeter() << endl;
    delete c;
    return 0;
}


int main01(void)
{
    //实例化Circle对象
    Circle c1(2,3,5);
    c1.showCircle();
    cout << "面积：" << c1.getArea() << endl;
    cout << "周长：" << c1.getPerimeter() << endl;
    return 0;
}

void Circle::showCircle()
{
    cout << "圆心坐标：(" << x << ", " << y << ")" << endl;
}

double Circle::getArea()
{
    return PI * radius * radius;
}

double Circle::getPerimeter()
{
    return 2 * PI * radius;
}