/*
纯虚函数，抽象类
纯虚函数：没有定义函数体的虚函数叫做纯虚函数。
            virtual 返回值 函数名(参数列表)=0;
抽象类：拥有纯虚函数的类叫做抽象类。
        抽象类是用来定义规范，让子类来重写它。
        子类如果没有重写抽象类的所有纯虚函数，或者子类中有新的纯虚函数，那么子类也被叫做抽象类，也不能被实例化
        子类重写了抽象类的所有纯虚函数，子类就是非抽象类（普通的类）

Animal(char *m_sName, run())
    run()方法不同的动物实现的方式不一样，有两条腿跳，四条腿的跑，无腿的
    父类不清楚如何定义时，把方法定义为纯虚函数，让子类来定义
*/
#include <iostream>
using namespace std;
#include <cstring>

class Animal
{
    private:
        char *m_sName;
    public:
        Animal(const char *name)
        {
            m_sName = new char[strlen(name) + 1];
            strcpy(m_sName, name);
        }
        ~Animal()
        {
            if (m_sName != nullptr)
            {
                delete[] m_sName;
            }
        }
        //父类不清楚方法如何定义时，定义为纯虚函数，让子类来定义它
        virtual void run() = 0;
};

class Cat: public Animal
{
    public:
        Cat(const char*name):Animal(name){}
        virtual void run()
        {
            cout << "四条腿的猫在跑！" << endl;
        }
};

int main(void)
{
    //1)抽象类不能被实例化
    // Animal a;
    // Animal *a = new Animal("小黑");

    //2)抽象类是用来定义规范，让子类来重写它。
    //子类如果没有重写抽象类的所有纯虚函数，或者子类中有新的纯虚函数，那么子类也被叫做抽象类，
    //也不能被实例化
    //子类重写了抽象类的所有纯虚函数，子类就是非抽象类（普通的类）
    Cat c("花花");
    c.run();
    return 0;
}