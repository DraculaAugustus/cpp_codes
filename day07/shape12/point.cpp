#include "point.h"
#include <iostream>
/*
#include ""     #include <>
""是在当前目录下寻找头文件
<>是从库(lib, dll)中找头文件*/

void showPoint(Point p)
{
    std::cout << "点的坐标为：(" << p.x << ", " << p.y << ")" << std::endl;
}