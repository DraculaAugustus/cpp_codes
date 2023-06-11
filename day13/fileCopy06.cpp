/*
复制文件
    需求：把当前目录下的readFile01.cpp复制到其它路径下
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(void)
{
    fstream in_file("readFile01.cpp", ios_base::in);
    fstream out_file("../temp.cpp", ios_base::out);
    if (in_file.fail())
    {
        cout << "找不到文件！";
        return 0;
    }
    char arr[200];
    while(!in_file.eof())
    {
        in_file.getline(arr, 200);
        cout << arr << endl;
        out_file.write(arr, strlen(arr));
        out_file.put('\n');
    }
    in_file.close();
    out_file.close();
    return 0;
}

int main01(void)
{
    fstream out_file("readFile01.cpp", ios_base::in);
    if(out_file.fail())
    {
        cout << "没有打开文件！" << endl;
        return 0;
    }

    //读取文件大小
    out_file.seekg(0, ios_base::end);
    streampos fileSize = out_file.tellg();
    out_file.seekg(0, ios_base::beg);

    //读文件
    char *buffer = new char[fileSize];
    out_file.read(buffer, fileSize);
    out_file.close();

    //写文件
    fstream in_file("../../file06.cpp", ios_base::out);
    if(in_file.fail())
    {
        cout << "打开失败！" << endl;
        return 0;
    }
    in_file.write(buffer, fileSize);
    in_file.close();

    delete[] buffer;
    return 0;
}
