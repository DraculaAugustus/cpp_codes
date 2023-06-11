#include <iostream>
using namespace std;
#include "Point.cpp"

class Rect
{
    private:
        Point *center;
        double m_dLength;
        double m_dWidth;
    public:
        Rect(){
            center = new Point();
        }
        //把内嵌类的地址赋值给指针
        Rect(Point *p, double length, double width):center(p)
        {
            m_dLength = length;
            m_dWidth = width;
        }
        //实例化当前类时先实例化嵌套类
        Rect(double x, double y, double length, double width):center(new Point(x,y))
        {
            m_dLength = length;
            m_dWidth = width;
        }
        ~Rect()
        {
            if(center != nullptr)
            {
                delete center;
            }
            cout << "Rect的析构函数！" << endl;
        }
        void showRect()
        {
            center->showPoint();
            cout << "长：" << m_dLength << ", 宽：" << m_dWidth << endl;
        }
};

int main(void)
{
    // Point *p = new Point(2,3);
    // Rect rect(p, 10, 5);
    // rect.showRect();
    // delete p;

    // Rect rect(2,3,10,5);
    // rect.showRect();

    Rect rect;
    return 0;
}