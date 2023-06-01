#include <iostream>
#include "rectangle.h"
#include "point.h"

void showRectangle(Rectangle rect)
{
    std::cout << "长方形的中心：";
    showPoint(rect.center);
    std::cout << "长：" << rect.length << ", 宽：" << rect.width << std::endl;
}

double rectArea(Rectangle rect)
{
    return rect.length * rect.width;
}

double rectPerimeter(Rectangle rect)
{
    return 2 * (rect.length + rect.width);
}