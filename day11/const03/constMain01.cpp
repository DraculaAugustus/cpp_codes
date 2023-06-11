/*
const修饰常量：常量的值不可以修改
常引用（形参）：保证引用的对象不被修改。
常对象：属性值不能修改的对象叫做常对象
    const 对象类型  对象名;     或者    对象类型 const 对象名;
    常对象只能访问常成员函数
常常成员函数：只能访问属性的值，不能修改属性的值。
    函数类型 函数名(形参列表) const;//函数的声明
    函数类型 函数名(形参列表) const{}//函数的定义

const是函数的一部分，可以根据const来实现函数的重载，函数名，参数列表都一致。
常对象只能调用常成员函数。
普通对象既能调用普通成员函数，也能调用常成员函数，优先调用普通成员函数。




*/
#include <iostream>
using namespace std;

class A
{
    private:
        float x, y;
    public:
        A(float a, float b)
        {
            x = a;
            y = b;
        }
        void setX(float a)
        {
            x = a;
        }
        void setY(float b)
        {
            y = b;
        }
        float getX()
        {
            return x;
        }
        float getY()
        {
            return y;
        }
        //用const修饰的成员函数叫做常成员函数
        //常成员函数，函数体内不能修改属性值
        void output()const
        {
            cout << "常成员函数：" << x << ", " << y << endl;
        }
        // void output()
        // {
        //     cout << "普通成员函数：" << x << ", " << y << endl;
        // }
};

int main(void)
{
    //const修饰的对象叫做常对象，常对象的属性值不能被修改
    //常对象不能调用普通成员函数(因为普通成员函数可以修改属性值)
    // const A a(2,3);
    A const a(2,3);
    a.output();
    //a.setX(10);
    a.output();

    //实例化对象
    A b(7, 5);
    b.output();
    return 0;
}
