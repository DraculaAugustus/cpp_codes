/*
学生练习Student,
属性（学号m_nNumber, 姓名*m_cNname, 年龄m_nAge, 成绩m_fScore)
方法(无参构造，有参构造, show())

析构函数：
    销毁对象时自动调用析构函数，用来释放动态内存区存储的类属性。
    什么时候需要写析构函数：凡是在类的构造函数中有使用new,malloc的。
    没有定义析构函数的类，类中默认有一个析构函数，没有任何操作。
    析构函数不能重载，只有一个。
    自动析构时，析构顺序和构造顺序相反，先构造的最后析构。

拷贝构造函数：
    类中有一个拷贝构造函数，实现的是浅拷贝（把基本数据类型和指针类型的地址拷贝给新对象）
    旧对象----拷贝构造函数----新对象
    程序结束时，由于旧对象和新对象的指针指向同一块空间，程序重复析构，报错
    解决方法：自己重写拷贝构造函数，实现深拷贝

    Student(const Student &stu);Student s4(s3);
    s3是实参，stu是形参，如果不是&引用类型，就是值传递，需要把s3复制一份给stu.
    需要创建参数对象，然后再复制，在空间和时间上都有一定的开销，所以我们的参数使用引用。
    stu引用和实参s3是同一个对象，如果不是const类型，不能保证s3对象的安全（有可能被不小心修改了），
    如果声明为const，在函数中修改实参的行为就被禁止了。
    因此，拷贝构造函数的参数声明为常引用对象。
*/
#include <iostream>
using namespace std;
#include <cstring>

class Student
{
    private:
        int m_nNumber;//学号
        char *m_cName;//姓名
        int m_nAge;//年龄
        float m_fScore;//成绩
    public:
        //析构函数，释放内存时自动调用析构函数
        ~Student();
        //拷贝构造函数
        Student(const Student &stu);
        Student();
        Student(int number, const char *name, int age, float score);
        //重写=操作符：想把操作符赋予新功能时可以重写，重写最多的操作符有=,[]
        //opterator=是重写赋值操作符的固定格式，重写[]这样定义：operator[]
        //作用：把stu旧对象赋值给新对象，并返回新对象
        Student &operator=(const Student &stu);
        void show();//打印学生信息
        //修改学生的姓名
        void setName(const char *name)
        {
            //释放原来的名字空间，重新分配新空间，然后再复制
            delete[] m_cName;
            m_cName = new char[strlen(name) + 1];
            strcpy(m_cName, name);
        }
        //获取学生的姓名
        char * getName()
        {
            return m_cName;
        }
};

int main(void)
{
    Student s1(2023001, "可可", 10, 100);
    // s1.show();
    // Student s2(2023002, "莉莉", 13, 90);
    // s2.show();
    // Student s3(2023006, "皮卡丘", 8, 95);
    // s3.show();

    // //s4是由s3拷贝过来
    // //拷贝构造函数不用显示调用，在拷贝对象时自动调用
    // Student s4(s3);
    // s4.show();

    //调用默认构造函数
    Student s5;
    s5 = s1; //赋值运算符 = 需要重载，因无法对类对象进行直接赋值
    cout << "第一个学生的姓名：" << s1.getName() << endl;
    cout << "第五个学生的姓名：" << s5.getName() << endl;
    //修改第一个学生的姓名
    s1.setName("新同学");
    cout << "第一个学生的姓名：" << s1.getName() << endl;
    cout << "第五个学生的姓名：" << s5.getName() << endl;
    s5.show();
    return 0;
}

int main01(void)
{
    Student *st = new Student(2023001, "Rick", 23, 89.8);
    st->show();
    delete st;
    return 0;
}
Student::~Student()
{
    //释放指针属性的内存空间
    if(m_cName != nullptr)
    {
        cout << m_cName << "要退学！" << endl;
        delete[] m_cName;
    }
    else
    {
        cout << "有一个同学要退学！" << endl;
    }
}
Student::Student(){}
Student::Student(int number, const char *name, int age, float score)
{
    m_nNumber = number;
    m_cName = new char[strlen(name) + 1];
    strcpy(m_cName, name);
    m_nAge = age;
    m_fScore = score;
    cout << m_cName << "新进班啦！" << endl;
}
void Student::show()
{
    cout << "学号：" << m_nNumber << endl;
    cout << "姓名：" << m_cName << endl;
    cout << "年龄：" << m_nAge << endl;
    cout << "成绩：" << m_fScore << endl;
}

//拷贝构造函数实现：把stu对象中的属性都拷贝给新对象
Student::Student(const Student &stu)
{
    m_nNumber = stu.m_nNumber;
    m_cName = new char[strlen(stu.m_cName) + 1];
    strcpy(m_cName, stu.m_cName);
    m_nAge = stu.m_nAge;
    m_fScore = stu.m_fScore;
}
Student& Student::operator=(const Student &stu)
{
    //当前对象和参数对象不是同一个对象时才赋值
    //this是当前对象的指针
    if(this!= &stu)
    {
        m_nNumber = stu.m_nNumber;
        m_cName = new char[strlen(stu.m_cName) + 1];
        strcpy(m_cName, stu.m_cName);
        m_nAge = stu.m_nAge;
        m_fScore = stu.m_fScore;
    }
    cout << "=赋值" << stu.m_cName << endl;
    //当前对象指针的解引用
    return *this;
}