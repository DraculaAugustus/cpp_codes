/*
定义Point点
    Point(x, y)

操作符重载：对于已有的操作符重新定义，赋予其新的功能，适应不同的数据类型（包括自定义的数据类型）。
    返回值类型 operator(参数列表){函数体}
*/
#include <iostream>
using namespace std;

class Point
{
    private:
        double m_dx;
        double m_dy;
    public:
        Point() { cout << "Point无参构造！" << endl; }
        Point(double x, double y)
        {
            m_dx = x;
            m_dy = y;
            cout << "Point构造！" << endl;
        }
        ~Point()
        {
            cout << "Point析构！" << endl;
        }
        //两个get方法
        double getX()
        {
            return m_dx;
        }
        double getY()
        {
            return m_dy;
        }
        //打印坐标
        void show()
        {
            cout << "坐标：(" << m_dx << ", " << m_dy << ")" << endl;
        }
        //重载+操作符，实现相应的坐标相加
        Point operator+(const Point &p)
        {
            cout << "当前坐标点：(" << m_dx << ", " << m_dy << ")" << endl;
            cout << "参数坐标点：(" << p.m_dx << ", " << p.m_dy << ")" << endl;
            return Point(m_dx + p.m_dx, m_dy + p.m_dy);
        }
        //重载等号赋值
        Point &operator=(const Point &p)
        {
            if (this == &p)
            {
                return *this;
            }
            m_dx = p.m_dx;
            m_dy = p.m_dy;
            cout << "重载等号赋值操作符！" << endl;
            return *this;
        }
};

int main01(void)
{
    Point p1(1, 2);
    Point p2(2, 3);
    p1.show();
    p2.show();

    Point p3 = p1 + p2;
    p3.show();

    p3 = p1;
    p3.show();
    return 0;
}