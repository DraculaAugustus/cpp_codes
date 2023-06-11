/*
复制图片 ios_base::binary
    读文件的大小
        1）seekg(0,end);
        2）streampos size=流.tellg();
        3）把指针设置为初始状态     seekg(0, beg)
    流对象状态
        1）判断是否文件的结尾
            in_file.of() 如果是文件的结尾返回true，否则返回false
            in_file==EOF    如果是文件的结尾就是true
            in_file.peek()==EOF
        2）判断文件打开的操作是否失败
            in_file.fail()  如果存在失败，返回true
        3）判断状态是否正常
            in_file.good()  如果状态正常返回true
        4）clear()
            清除流对象的所有状态
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(void)
{
    //先读图片，以二进制流的方式打开读文件
    ifstream in_file("../../photo/temp.png", ios_base::binary | ios_base::in);
    // if(in_file.fail())
    // {
    //     cout << "没有打开文件！";
    //     return 0;
    // }
    if(!in_file)
    {
        cout << "没有打开文件！";
        return 0;
    }
    //获取文件的大小（先把指针移动到最后，获取指针的位置）
    in_file.seekg(0, ios_base::end);//移动到文件末尾
    streampos pos = in_file.tellg();//存储文件字节大小
    in_file.seekg(0, ios_base::beg);//移动到文件开头

    //初始化char类型的数组，存储在堆内
    char *buffer = new char[pos];
    in_file.read(buffer, pos);
    in_file.close();

    //写文件
    ofstream out_file("file04.png", ios_base::binary | ios_base::out);
    if(in_file.fail())
    {
        cout << "打开文件失败！";
        return 0;
    }
    out_file.write(buffer, pos);
    out_file.close();

    delete[] buffer;
    return 0;
}