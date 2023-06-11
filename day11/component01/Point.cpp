#include <iostream>
using namespace std;
/*定义一个点*/
class Point
{
    private:
        double m_dx;
        double m_dy;
    public:
        Point() { cout << "Point的无参构造！" << endl; }
        Point(double x, double y):m_dx(x),m_dy(y)
        {
            cout << "(" << m_dx << ", " << m_dy << ")" << "Point的有参构造！" << endl;
        }
        Point(const Point& p)
        {
            m_dx = p.m_dx;
            m_dy = p.m_dy;
            cout << "(" << m_dx << ", " << m_dy << ")" << "Point的拷贝构造函数！" << endl;
        }
        ~Point()
        {
            cout << "(" << m_dx << ", " << m_dy << ")" << "Point的析构函数！" << endl;
        }
        void showPoint()
        {
            cout << "点的坐标：(" << m_dx << ", " << m_dy << ")" << endl;
        }
};