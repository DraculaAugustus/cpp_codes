#pragma once
#include "point.h"
struct Rectangle
{
    Point center;//中心
    double length;//长
    double width;//宽
};

//打印长方形的信息
void showRectangle(struct Rectangle rect);
//计算长方形的面积
double rectArea(struct Rectangle rect);
//计算长方形的周长
double rectPerimeter(struct Rectangle rect);