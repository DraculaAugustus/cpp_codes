/*
静态成员
    普通属性叫做成员属性，归对象所有，每个对象之间相互不影响。
        使用时仅限于使用对象来访问它，对象.属性名，对象->属性名
    static修饰的属性叫做静态属性，不属于某个对象，而是所有对象共享，是类的属性，一个类只有一份。
        使用时可以用对象来访问，也可以用类名来访问（推荐）类名::属性名  Student::count
    静态属性的初始化只能在类外定义和初始化。

    静态成员函数：用static修饰的函数
        类外访问：可以用类名访问也可以用对象访问（静态属性一样），类名::函数名()    对象.函数名()
        静态成员函数函数体内，不能访问成员属性，能访问静态属性。
                            不能调用普通成员函数，能调用静态成员函数。
    普通的成员函数只能用对象来访问。

    总结：static的就是类的，所有对象共享，能用类访问也能用对象访问。
        static修饰的比对象早，static中不能访问非static的东西，非static的方法能访问static的东西。

    构造函数能用static修饰吗？
        不能，构造函数是用来构造实例对象的。

    需求：定义Student的类（static count,number,name,age) show()
    统计有多少个学生？
*/
#include <iostream>
using namespace std;
#include <cstring>

class Student
{
    private:
        int number;
        char *name;
        int age;
    public: 
        //静态数据成员count, 用于统计对象的个数
        static int count;

        Student(){
            count++;
        }
        Student(int num, const char *name, int age)
        {
            count++;
            this->number = num;
            this->name = new char[strlen(name)+1];
            strcpy(this->name, name);
            this->age = age;
        }
        Student(const Student& stu)
        {
            count++;
            this->number = stu.number;
            this->name = new char[strlen(stu.name) + 1];
            strcpy(this->name, stu.name);
            this->age = stu.age;
        }
        ~Student()
        {
            if(name != nullptr)
            {
                delete[] name;
            }
            cout << "Student析构函数！" << endl;
        }
        void show()
        {
            cout << "学号：" << number << ", 姓名：" << name << ", 年龄：" << age << endl;
        }
        static void staticShow()
        {
            cout << "静态成员函数！" << endl;
        }
        //打印有几名学生
        //static修饰的函数叫做静态成员函数，（静态方法）
        static void getCount()
        {
            cout << "当前有：" << count << "名学生！" << endl;
            //静态成员函数只能访问静态属性，不能访问成员属性
            // cout << "普通属性：学号：" << number << endl;
            staticShow();
        }

};
//静态数据成员（静态属性）在类外初始化
int Student::count = 0;

int main(void)
{
    Student stu(1,"张三",18);
    stu.show();
    stu.getCount();

    // Student stu2;
    // stu2.getCount();
    Student *stu3 = new Student(2, "李四", 19);
    stu3->show();
    stu3->getCount();

    Student stu4(stu);
    stu4.show();
    stu4.getCount();

    cout << "类的静态属性可以用对象访问，也可以用类名访问：" << Student::count << endl;
    //静态成员函数可以用类名访问
    Student::getCount();
    delete stu3;
    return 0;
}