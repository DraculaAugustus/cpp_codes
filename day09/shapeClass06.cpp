/*
多继承
BaseA(m_a, m_b)
BaseB(m_c, m_d)
Derived继承BaseA，BaseB，（m_e, show()）
多继承构造顺序：class Derived : public BaseB, public Base A
    构造子类时先构造父类，第一个父类的BaseB，先构造BaseB，再构造BaseA，最后构造子类
    析构和构造的过程相反
*/
#include <iostream>
using namespace std;

class BaseA
{
    protected:
        int m_a;
        int m_b;
    public:
        BaseA(int a, int b):m_a(a), m_b(b)
        {
            cout << "A的构造函数！" << endl;
        }
        ~BaseA() { cout << "A的析构函数！" << endl; }
};

class BaseB
{
    protected:
        int m_c;
        int m_d;
    public:
        BaseB(int c, int d):m_c(c), m_d(d)
        {
            cout << "B的构造函数！" << endl;
        }
        ~BaseB() { cout << "B的析构函数！" << endl; }
};

//Derived继承BaseA和BaseB
class Derived:public BaseA, public BaseB
{
    private:
        int m_e;
    public:
        Derived(int a, int b, int c, int d, int e):BaseA(a, b),BaseB(c, d), m_e(e)
        {
            cout << "Derived的构造函数！" << endl;
        }
        ~Derived() { cout << "Derived的析构函数！" << endl; }
        void show()
        {
            cout << m_a << ", " << m_b << ", " << m_c << ", " << m_d << ", " << m_e << endl;
        }
};

int main(void)
{
    Derived *d = new Derived(1, 2, 3, 4, 5);
    d->show();
    delete d;
    return 0;
}