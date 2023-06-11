#include <iostream>
#include "Point.cpp"
using namespace std;

/*
组合类和嵌套类的构造顺序和析构顺序
    构造组合类时先构造内嵌类，内嵌类的构造顺序和属性的声明顺序有关；
    析造组合类和构造组合类的顺序相反。
*/
class Triangle
{
    private:
        Point p3;
        Point p1;
        Point p2;
    public:
        //类内实例化内嵌类
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3):p1(x1,y1),p2(x2,y2),p3(x3,y3)
        {
            cout << "Triangle的构造函数！先实例化嵌套类。" << endl;
        }
        //让内嵌类传递过来
        Triangle(const Point& p1, const Point& p2, const Point& p3):p1(p1),p2(p2),p3(p3)
        {
            cout << "Triangle的构造函数！传递内嵌类对象！" << endl;
        }
        void showTriangle()
        {
            p1.showPoint();
            p2.showPoint();
            p3.showPoint();
        }
        ~Triangle()
        {
            cout << "Triangle的析构函数！" << endl;
        }
};

int main(void)
{
    Point *p1 = new Point(1, 1);
    Point *p2 = new Point(2, 2);
    Point *p3 = new Point(3, 3);
    Triangle *t = new Triangle(*p1, *p2, *p3);
    t->showTriangle();
    delete t;
    delete p1;
    delete p2;
    delete p3;
    return 0;
}

int main01(void)
{
    Triangle *t = new Triangle(1,1,2,2,3,3);
    t->showTriangle();
    delete t;
    return 0;
}