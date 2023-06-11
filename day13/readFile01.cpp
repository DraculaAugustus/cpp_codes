/*
读文件：
    1）打开文件ios_base::in,
    2)读的操作；
    3）关闭文件
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//getline()按行读
int main(void)
{
    char buf[100];
    //打开文件
    ifstream in_file("file01.txt");
    // while(!in_file.eof())
    // {
    //     in_file.getline(buf, 100);
    //     cout << buf << endl;
    // }
    in_file.close();
    return 0;
}

//用get()读文件,按照字符读取，文件中有什么就能读出什么字符
//用get()读文件多读一个字符：文件中的结束标识符当做正常的文件内容读了，读下一个字符时才可以修改EOF标志，才判断出结尾。
int main02(void)
{
    char buf[100];
    char c; //每次读一个字符
    int index = 0; //定义下脚标
    //打开文件
    ifstream in_file("file01.txt");
    // while (in_file.peek() != EOF)
    // {
    //     in_file.get(c);
    //     buf[index++] = c;
    // }
    while (!in_file.eof())
    {
        in_file.get(c);
            if(!in_file.eof())
                buf[index++] = c;
    }
    in_file.close();
    buf[index] = '\0';
    cout << "读到的字符串为：" << buf << endl;
    return 0;
}

//提取操作符>>,(不能提取空白符，以空白符分割)
int main01(void)
{
    int buf[100]; //存放读取的数据
    int a; //每次读取的数据
    int index = 0; //数组的下脚标
    //打开文件
    ifstream in_file("file01.txt", ios_base::in);
    while (!in_file.eof()) //in_file.eof()如果读到结尾返回true
    {
        in_file >> a;
        buf[index++] = a;
    }
    in_file.close();
    //遍历数组，打印内容
    for (int i = 0; i < index; i++)
    {
        cout << buf[i] << " ";
    }
    cout << endl;
    return 0;
}