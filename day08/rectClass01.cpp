/*
类的定义：

*/
#include <iostream>
using namespace std;

// class是类定义时的关键字
// Rect类名遵循大驼峰（所有单词的首字母大写）
// 类体用大括号环绕，最后用 ; 结尾（必须）
class Rect
{
    //一般属性时私有的，只能在类内访问，类外无法访问
    //权限修饰符作用其下所有内容，除非显式修改为其他权限修饰符
    //封装的目的是为了保护数据，限制别人访问,需要访问时给他开启一扇窗（方法）
    private:
        double length;
        double width;
    public:
        //get属性名() 访问属性值
        double getLength()
        {
            return length;
        }
        double getWidth()
        {
            return width;
        }
        //set属性名() 修改|设置属性值
        void setLength(double len = 20)
        {
            length = len;
        }
        void setWidth(double w = 30)
        {
            width = w;
        }

        //一般类中的方法是公有的，可以在类内访问，也可以在类外访问
        double getArea()
        {
            return length * width;
        }
        //类中的方法可以定义在类内也可以定义在类外
        double getPerimeter();
        //方法的重载
        double getPerimeter(double width, double length);
};

int main(void)
{
    //定义一个类类型的指针对象，通过指针对象访问类的方法
    Rect *p1 = new Rect(); //类的数据是存储在堆上的
    //指针访问类的方法用箭头，其它对象访问用.
    p1->setLength(10);
    p1->setWidth(5);
    cout << "面积：" << p1->getArea() << endl;
    cout << "周长：" << p1->getPerimeter() << endl;
    cout << "长：" << p1->getLength() << endl;
    cout << "宽：" << p1->getWidth() << endl;

    delete p1;
    return 0;
}

int main01(void)
{
    //定义Rect类型的变量
    Rect rect;
    rect.setLength(5);
    rect.setWidth(3);

    Rect r1;
    r1.setLength(10);
    r1.setWidth(2);

    //属性值是属于各个对象的，多个对象之间相互不影响
    cout << "长方形的长：" << rect.getLength() << endl;
    cout << "长方形的宽：" << rect.getWidth() << endl;
    cout << "长方形的面积：" << rect.getArea() << endl;
    cout << "长方形的周长：" << rect.getPerimeter() << endl;
    cout << "长方形的周长：" << rect.getPerimeter(100,200) << endl;

    cout << "长方形的长：" << r1.getLength() << endl;
    cout << "长方形的宽：" << r1.getWidth() << endl;
    cout << "长方形的面积：" << r1.getArea() << endl;
    cout << "长方形的周长：" << r1.getPerimeter() << endl;
    cout << "长方形的周长：" << r1.getPerimeter(1000,2000) << endl;

    Rect r2;
    //用方法的默认值来设置属性
    r2.setLength();
    r2.setWidth();
    cout << "长方形的长：" << r2.getLength() << endl;
    cout << "长方形的宽：" << r2.getWidth() << endl;
    cout << "长方形的面积：" << r2.getArea() << endl;
    cout << "长方形的周长：" << r2.getPerimeter() << endl;
    cout << "长方形的周长：" << r2.getPerimeter(1000,2000) << endl;

    return 0;
}

inline double Rect::getPerimeter()
{
    return 2 * (length + width);
}

double Rect::getPerimeter(double w, double len)
{
    return 2 * (w + len);
}