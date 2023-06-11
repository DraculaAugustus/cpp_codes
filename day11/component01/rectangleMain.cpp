/**/
#include <iostream>
#include "Point.cpp"
using namespace std;
//长方形
class Rectangle
{
    private:
        Point center;//中心
        double m_dLength;
        double m_dWidth;
    public:
        //调用嵌套类的无参构造函数实例化嵌套类
        Rectangle(){}
        //初始化列表的方式把Point的对象拷贝过来
        Rectangle(const Point &p, double length, double width):center(p)
        {
            m_dLength = length;
            m_dWidth = width;
        }
        //实例化当前类时先实例化嵌套类
        Rectangle(double x, double y, double length, double width):center(x,y)
        {
            m_dLength = length;
            m_dWidth = width;
        }
        void showRect()
        {
            center.showPoint();
            cout << "长：" << m_dLength << ", 宽：" << m_dWidth << endl;
        }
};

int main(void)
{
    // Point p(2,3);
    // Rectangle rect(p, 10, 5);
    // rect.showRect();

    // Rectangle rect(2,3,10,5);
    // rect.showRect();

    //无参构造
    Rectangle rect;
    return 0;
}