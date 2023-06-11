/*
自定义MyString数据类型(封装字符指针)
    使用默认拷贝构造函数只是简单的将参数的属性值复制给新建对象对应的属性，
    这种拷贝称为浅拷贝。
    对于具有指针属性的类，需要把指针指向的内存空间也拷贝一份，叫做深拷贝，
    自定义拷贝构造函数实现。
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString
{
    private:
        char *str;
    public:
        MyString(const char *s = "no data")
        {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        MyString(const MyString &mystring)
        {
            this->str = new char[strlen(mystring.str) + 1];
            strcpy(this->str, mystring.str);          
        }
        MyString& operator=(const MyString& mystring)
        {
            //判断是否把自己赋值给自己
            if(this == &mystring)
            {
                return *this;
            }
            //判断旧空间是否要清空
            if (str != nullptr)
            {
                delete[] str;
            }
            this->str = new char[strlen(mystring.str) + 1];
            strcpy(this->str, mystring.str);
            return *this;
        }
        ~MyString()
        {
            if (str != nullptr)
            {
                delete[] str;
            }
        }
        void print()
        {
            cout << str << endl;
        }
        void setStr(const char *s)
        {
            //delete, new, strcpy
            delete[] str;
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
};

int main(void)
{
    MyString *p = new MyString("A String");
    MyString a1 = *p;
    a1.print();
    delete p;
    a1.print();
    return 0;
}

int main01(void)
{
    MyString s1("A String");
    MyString s2(s1);
    s1.print();
    s2.print();

    //修改s2的属性值
    s2.setStr("B Word");
    s1.print();
    s2.print();
    return 0;
}