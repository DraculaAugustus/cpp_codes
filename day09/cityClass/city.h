#pragma once
#include <iostream>
#include <cstring>
//定义类
class City
{
    private:
        char *m_cName;
        double m_dLongtitude;//经度
        double m_dLatitude;//纬度
    public:
        //构造器调用时间：实例化对象时用于属性的初始化
        City();//类中有一个无参构造函数，如果定义有参构造函数后，默认无参不存在
        //构造函数可以重载overload
        City(const char *name);
        City(const char *naem, double longtitude, double latitude);
        //析构函数，销毁对象时调用析构函数，用来回收存在动态内存区的属性值
        //类中默认有一个析构函数，默认的析构函数没有如何操作。
        //析构函数不能重载，一个类中只有一个析构函数
        ~City();
        //拷贝构造：实例化对象时可以不调用构造函数，通过拷贝构造从旧对象中拷贝一份过来
        //属性中有非基本类型的对象时需要用重写拷贝构造
        //参数是常引用的原因：引用实参不用复制实参，提高效率。引用实参能够修改实参，为了保护实参，用const修饰。
        City(const City &city);
        //重载=操作符：赋予操作符特殊的功能
        City &operator=(const City &city);
        //set|get方法，修改和获取属性值
        //因为属性是私有的，在类外不能访问和操作，如果需要在类外访问和操作，提供get|set方法
        char *getName()
        {
            return m_cName;
        }
        void setName(const char *name)
        {
            delete[] m_cName;
            m_cName = new char[strlen(name) + 1];
            strcpy(m_cName, name);
        }
        void showInfo();
};