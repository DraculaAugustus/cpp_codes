/*
面向对象的三大特征：
    封装，继承，多态
    封装：提取出现实社会事物的公共特点，把事物封装成类，事物的数据封装成属性，事物的动作封装成方法，
        一般把类的属性保护起来设为私有的，类的的方法为公有的提供外部进行操作。这个类的创建过程就叫做封装。
    继承：在创建一个类时可以从现有的类继承过来。被继承的类叫做基类，超类；继承的类叫做子类或派生类。
        单继承：只有一个父类。
        多继承：教师管理人员同时继承教师类和管理人员类，叫做多继承。
        直接继承：教师类是教师管理人员的直接基类，叫直接继承
        间接继承：人类是教师管理人员的间接基类，叫做间接继承

                人类
        教师    管理人员    学生
            教师管理人员
    private, protected, public权限修饰符的作用域。
    继承有公共public，保护继承protected，私有继承private，继承方式的区别？
        public继承：从父类中继承的方法，其权限与父类相同
        protected继承：从父类中继承的方法，其权限均为protected
        private继承：从父类中继承的方法，其权限均为private
    子类的构造器：构造子类时必须先构造父类。
    构造的顺序：先构造父类再构造子类，先析构子类再析构父类，构造和析构的顺序相反。
    重载overload:同一个类中，方法名相同，参数个数或者类型不同，返回值不能区分是否重载。
    隐藏hide:在继承关系中，子类的方法名和父类一样，不管参数列表和返回值是否一样，都是对基类方法的隐藏。
            基类的方法不能使用，只能使用子类新定义的方法。
*/
#include <iostream>
using namespace std;
#include <cstring>

class Animal
{
    private:
        char *name;
    public:
        Animal()
        {
            cout << "动物父类无参构造函数" << endl;
        }
        Animal(const char *n)
        {
            this->name = new char[strlen(n) + 1];
            strcpy(name, n);
            cout << "动物父类构造函数" << endl;
        }
        ~Animal()
        {
            // if(name != nullptr)
            // {
            //     delete name;
            // }
            cout << "动物父类析构函数" << endl;
        }
    private:
        void showPrivat()
        {
            cout << "private动物的名字：" << /*name <<*/ endl;
        }
    protected:
        void showProtected()
        {
            cout << "protected动物的名字：" << /*name <<*/ endl;
        }
    public:
        void showPublic()
        {
            cout << "public动物的名字：" << /*name <<*/ endl;
        }
        void showInfo()
        {
            showPrivat();
            showProtected();
            showPublic();
        }
};

//Dog公有继承Animal
class Dog:public Animal
{
    public:
        //实例化子类对象时必须实例化父类对象
        //用初始化列表的方式先实例化父类
        //如后再给子类的属性赋值
        Dog(const char *n):Animal(n)
        {
            cout << "Dog类构造函数" << endl;
        }
        ~Dog()
        {
            cout << "Dog类析构函数" << endl;
        }
        //子类中能否访问父类的private，protected，public的方法
        void showDog()
        {
            //showPrivat();
            showProtected();
            showPublic();
        }
};

int main01(void)
{
    //验证类外是否能用private, protected, public
    //类外只能访问public，private和protected类外都不能访问
    Animal a("动物");
    a.showPublic();
    a.showInfo();
    cout << "----------" << endl;
    Dog d("狗");
    d.showDog();
    d.showPublic(); //Animal
    return 0;
}