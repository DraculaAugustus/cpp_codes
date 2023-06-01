#include "circle.h"
#include <iostream>

void showCircle(Circle c)
{
    std::cout << "圆心位置：(" << c.center.x << ", " << c.center.y << ")\n";
}

double circleArea(Circle c)
{
    return PI * c.radius * c.radius;
}

double circlePerimeter(Circle c)
{
    return 2 * PI * c.radius;
}