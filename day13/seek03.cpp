/*
流指针
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "readFile02.cpp"
//读文件，只读文件中的第二个对象
//移动读指针seekg()
int main(void)
{
    Rect r;//存放读到的对象
    //打开文件
    ifstream in_file("file02.txt", ios_base::in);
    streampos pos1 = in_file.tellg();
    cout << "移动之前的位置：" << pos1 << endl;
    in_file.seekg(sizeof(r), ios_base::beg);//从文件的头向后移动多少个字节
    streampos pos2 = in_file.tellg();
    cout << "移动之后的位置：" << pos2 << endl;

    in_file.read((char *)&r, sizeof(r));
    in_file.close();
    cout << "长方形的面积：" << r.getArea() << endl;
    cout << "长方形的周长：" << r.getPerimeter() << endl;

    return 0;
}