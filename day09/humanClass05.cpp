#include <iostream>
using namespace std;
#include <cstring>

/*
学生类：属性（姓名，年龄）行为（吃饭，睡觉）
老师类：属性（姓名，年龄，薪水），行为（吃饭，睡觉，教书）
班主任：属性（姓名，年龄，薪水），行为（吃饭，教书，管理）
*/

class Human
{
    private:
        char *m_cName;
        int m_nAge;
    public:
        Human() { cout << "Human类的无参构造！" << endl; }
        Human(const char *name, int age);
        ~Human();
        char *getName()
        {
            return m_cName;
        }
        int getAge()
        {
            return m_nAge;
        }
        void eat();
        void sleep();
};

//Student类继承Human类，没有自己的数据和方法
class Student :public Human
{
    public:
        Student() { cout << "学生无参构造函数！" << endl; }
        Student(const char *name, int age) : Human(name, age){}
        ~Student() { cout << "学生的析构函数！" << endl; }
};

//定义Teacher继承Human，有自己的salary，teach()
class Teacher :public Human
{
    private:
        double m_dSalary;
    public:
        Teacher(){}
        Teacher(const char *name, int age, double salary);
        ~Teacher() { cout << "Teacher的析构函数！" << endl; }
        void teach();
};

//定义Admin，继承Teacher类，有自己的方法manner()
class Admin :public Teacher
{
    public:
        Admin(){}
        Admin(const char *name, int age, double salary);
        ~Admin() { cout << "Admin的析构函数！" << endl; }
        void manner();
};

int main(void)
{
    Admin *a = new Admin("寇老师", 20, 10000);
    a->eat();
    a->sleep();
    a->teach();
    a->manner();
    delete a;
    return 0;
}

int main02(void)
{
    Teacher t("张老师", 28, 10000);
    t.eat();
    t.sleep();
    t.teach();
    return 0;
}

int main01(void)
{
    Student *coco = new Student("可可", 8);
    coco->eat();
    coco->sleep();
    delete coco;
    return 0;
}

Human::Human(const char *name, int age)
{
    m_cName = new char[strlen(name) + 1];
    strcpy(m_cName, name);
    m_nAge = age;
    cout << "Human的构造函数" << endl;
}
Human::~Human()
{
    if(m_cName != nullptr)
    {
        delete[] m_cName;
    }
    cout << "Human的析构函数" << endl;
}
void Human::eat()
{
    cout << "所有人类都要吃饭！" << endl;
}
void Human::sleep()
{
    cout << "所有人类都要睡觉！" << endl;
}

Teacher::Teacher(const char *name, int age, double salary):Human(name, age), m_dSalary(salary)
{
    cout << "Teacher的构造函数！" << endl;
}
void Teacher::teach()
{
    cout << "老师在教书！" << endl;
}

Admin::Admin(const char *name, int age, double salary): Teacher(name, age, salary)
{
    cout << "Admin的构造函数！" << endl;
}
void Admin::manner()
{
    cout << "班主任在开班会！" << endl;
}