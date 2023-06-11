#include "city.h"

City::City() { std::cout << "无参数" << std::endl; }

City::City(const char *name)
{
    //开辟内存，复制字符串
    m_cName = new char[strlen(name) + 1];
    strcpy(m_cName, name);
    std::cout << "一个参数" << std::endl;
}

//初始化列表
City::City(const char *name, double longtitude, double latitude):m_dLongtitude(longtitude),m_dLatitude(latitude)
{
    m_cName = new char[strlen(name) + 1];
    strcpy(m_cName, name);
    std::cout << "三个参数" << std::endl;
}

City::~City()
{
    //判断name是否有指向
    if(m_cName != nullptr)
    {
        delete[] m_cName;
    }
    std::cout << "析构函数！" << std::endl;
}

City::City(const City& city)
{
    m_cName = new char[strlen(city.m_cName) + 1];
    strcpy(m_cName, city.m_cName);
    m_dLongtitude = city.m_dLongtitude;
    m_dLatitude = city.m_dLatitude;
    std::cout << "拷贝构造函数！" << std::endl;
}

City& City::operator=(const City &city)
{
    //判断赋值的对象是否当前对象
    if(this==&city) //取city地址，判断是否相等
    {
        return *this;
    }
    if(m_cName != nullptr)
    {
        delete[] m_cName;
    }
    m_cName = new char[strlen(city.m_cName) + 1];
    strcpy(m_cName, city.m_cName);
    m_dLongtitude = city.m_dLongtitude;
    m_dLatitude = city.m_dLatitude;
    std::cout << "=赋值" << std::endl;
    return *this;
}

void City::showInfo()
{
    std::cout << "名称：" << m_cName << ", 经度："
                << m_dLongtitude << ", 纬度："
                << m_dLatitude << std::endl;
}