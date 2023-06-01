#pragma once    //避免重复引用
/*
#ifndef POINT_H
#define POINT_H
#endif
避免重复引用，和pragma once作用一样，用一个即可
*/

/*
点
*/
struct Point
{
    int x; //横坐标
    int y; //纵坐标
};

void showPoint(struct Point p);