/*
多态：一个对象有多个形态（多个类型）
    创建一个类就是创建了一种数据类型。
    一个对象既是子类类型又是父类类型，叫做多态。
    Animal(char *name, int age) bark()run()
    Dog() protectHouse()

1)父类没有，子类中独有的方法，父类类型无法调用，只能用子类类型来调用。
2)子类重新定义父类的方法，父类类型调父类的方法，子类类型调子类的方法。
C++的静态多态，是调子类的方法还是父类的方法，看对象的类型，在编译期决定的。 Animal *d;  Dog *d;
C++动态多态，调用时用virtual修饰，在运行时查看该对象是父类对象还是子类对象（在运行期决定）。new Dog(), new Animal()
    子类重写父类的方法，父类必须用virtual修饰，

多态：父类类型指向子类对象，子类重写父类的方法，父类用virtual修饰。

重写（override）：子类和父类的方法名，参数列表，和返回值一致，并且父类用virtual修饰。

virtual修饰的函数叫做虚函数。父类的虚函数被子类重写后，子类的方法默认是虚函数，可以用virtual也可以不用.

虚函数实现动态多态的机制是什么？
    编译器为每个包含虚函数的类创建一个虚函数表，并为每个对象设置一个虚函数指针（虚指针），
    用虚指针指向这个类的虚函数表，使用基类指针对函数调用时，通过这个虚函数指针，
    在虚函数表中找出虚函数的地址，从而调用不同的虚函数。

overload重载
override重写（覆盖）：子类重写父类的虚函数，方法名相同，参数列表和返回值相同
hide隐藏    子类的方法和父类的方法，方法名相同，不管参数列表和返回值是否相同，子类都覆盖了父类的方法。
*/
#include <iostream>
using namespace std;
#include <cstring>

class Animal
{
    private:
        char *m_cName;
        int m_nAge;
    public:
        Animal() { cout << "Animal无参构造！" << endl; }
        Animal(const char *name, int age): m_nAge(age)
        {
            m_cName = new char[strlen(name) + 1];
            strcpy(m_cName, name);
            cout << "Animal的有参构造！" << endl;
        }
        //纯虚函数
        virtual void bark() = 0;
        // {
        //     cout << "动物在叫！" << endl;
        // }
        void run()
        {
            cout << "动物在跑！" << endl;
        }
        char *getName()
        {
            return m_cName;
        }
};

class Dog: public Animal
{
        int type;

    public:
        Dog() { cout << "Dog的无参构造！" << endl; }
        Dog(const char *name, int age, int t): Animal(name, age)
        {
            type = t;
            cout << "Dog的有参构造！" << endl;
        }
        //父类的bark方法，狗类不适用，要重新实现
        void bark()
        {
            cout << getName() << "在狂吠!" << endl;
        }
        void run()
        {
            cout << getName() << "在狂奔！" << endl;
        }
        void protectHouse()
        {
            if(type == 0)
            {
                cout << "藏獒" << getName() << "正在看家！" << endl;
            }
            else
            {
                cout << "其它狗" << getName() << "正在看家！" << endl;
            }
        }
};

int main(void)
{
    //用父类的指针类型指向子类的对象（实现了动态）
    //多态：一个对象有多个类型，d既是Dog类型，又是Animal类型
    Animal *d = new Dog("小黑", 2, 0);
    d->bark();
    d->run();
    cout << "d的大小：" << sizeof(*d) << endl;
    // //调用子类方法时
    // d->protectHouse();
    delete d;
    return 0;
}