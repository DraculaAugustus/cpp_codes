/*
圆类
    类的组合：一个类嵌套在另一个类中
                构造函数的写法。
    常属性构造函数，拷贝构造函数的写法
*/
#include <iostream>
#include "point05.cpp"
using namespace std;

class Circle
{
    private:
        //直接赋值，初始化列表的方式
        const double PI;
        Point center;
        double radius;
    public:
        //常引用：保护实参对象不被修改
        Circle(const Point &p, double radius);
        Circle(const Circle &c);
        ~Circle() { cout << "Circle析构！"; }
        void show();
        void getCenterpoint()
        {
            cout << "圆心的";
            center.show();
        }
};

// int main(void)
// {
//     Point *p1 = new Point(1,2);
//     Circle *c = new Circle(*p1, 5);
//     c->show();
//     delete p1;
//     delete c;
//     c->getCenterpoint();
//     p1->show();
//     return 0;
// }

int main(void)
{
    Point p(1,2);
    Circle c(p, 5);
    c.show();
    return 0;
}

//构造函数
Circle::Circle(const Point &p, double radius):PI(3.1416),center(p)
{
    this->radius = radius;
    cout << "Circle构造！" << endl;
}
//拷贝构造函数
Circle::Circle(const Circle& c):PI(3.1416)
{
    center = c.center;
    this->radius = radius;
}
void Circle::show()
{
    cout << "圆心";
    center.show();
    cout << "半径：" << radius << endl;
}