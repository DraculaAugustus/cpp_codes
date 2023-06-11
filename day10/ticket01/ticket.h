#pragma once
//定义Person基类，Student，Solder子类
class Person
{
    public:
        //实现卖票的虚函数
        virtual void saleTicket();
};
class Student: public Person
{
    public:
        void saleTicket();
};

class Solder: public Person
{
    public:
        void saleTicket();
};