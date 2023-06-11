#include <iostream>
#include "city.h"
using namespace std;

int main()
{
    //对象的实例化
    City beijing("北京", 123.55, 45.56);
    beijing.showInfo();
    //拷贝构造
    City shanghai(beijing);
    shanghai.setName("上海");
    shanghai.showInfo();
    City chongqing; //无参构造函数
    chongqing = beijing;//调用等号赋值
    chongqing.setName("重庆");
    chongqing.showInfo();

    return 0;
}