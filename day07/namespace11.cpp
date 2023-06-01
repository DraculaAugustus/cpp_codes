/*
   C++的标准库都包含在一个单一的命名空间std中。

   多文件：
      头文件存放的是结构体的定义，函数的声明，全局变量|常量，后面学到的类；（.h结尾）
	  把函数的实现，类中方法的实现都放在源文件中。(.cpp)
   
   处理平面图形的案例：
       设计一个点Point(int, int)表示坐标
	   Circle(Point圆心，double半径）
	   Rectangle(Point图形的中心， double长， double宽)
	   打印图形的信息，计算两个图形的面积和周长。
*/
#include<iostream>
// using namespace std;
using std::endl;
int main(void)
{
    std::cout << "Hello World!" << endl;
    return 0;
}