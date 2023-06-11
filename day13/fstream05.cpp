/*
用输入输出文件流fstream
需求：在同一个文件中复制文件的内容
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(void)
{
    //以读写的方式打开文件
    fstream in_out("file05.txt", ios_base::in | ios_base::out);
    if(in_out.fail())
    {
        cout << "打开文件失败！" << endl;
        return 0;
    }

    //读取文件的大小
    in_out.seekg(0, ios_base::end); //移动读指针到文件尾
    streampos fileSize = in_out.tellg();
    in_out.seekg(0, ios_base::beg); //移动读指针到文件头

    char *buffer = new char[fileSize];
    in_out.read(buffer, fileSize); //读文件
    cout << "读到的内容为：" << buffer << endl;

    //写文件
    in_out.seekp(0, ios_base::end); //移动写指针到文件末尾
    in_out.write(buffer, fileSize);
    in_out.close();
    delete[] buffer;
    return 0;
}