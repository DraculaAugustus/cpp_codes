#pragma once
class Person
{
    private:
        char *m_sName;
        int m_nAge;
    public:
        Person(const char *name, int age);
        virtual ~Person();
        void showPerson();
};

class Student: public Person
{
    private:
        char *m_sMajor;//专业
    public:
        Student(const char *name, int age, const char *major);
        ~Student();
        void showStudent();
};

class Teacher: public Person
{
    private:
        char *m_sTitle;//职称
    public:
        Teacher(const char *name, int age, const char *title);
        ~Teacher();
        void showTeacher();
};