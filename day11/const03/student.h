#pragma once
//学生类(number, name, age) 构造器，析构，拷贝构造，set, get, show()
//建议，访问属性的方法直接定义为常成员函数。get,show()
class Student
{
    private:
        int number;
        char *name;
        int age;
    public:
        Student(){}
        Student(int number, const char *name, int age);
        virtual ~Student();
        Student(const Student &stu);
        void setNumber(int number);
        void setName(const char *name);
        void setAge(int age);
        int getNumber() const;
        char *getName() const;
        int getAge() const;
        void show() const;
};