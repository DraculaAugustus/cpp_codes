#pragma once
#include "point.h"
//圆形
struct Circle
{
    Point center; //圆心
    double radius; //半径
};
const double PI = 3.1415926;
//打印圆的信息
void showCircle(struct Circle c);
//计算圆的面积
double circleArea(struct Circle c);
//计算圆的周长
double circlePerimeter(struct Circle c);
