/*
文件的读写
    各种数据暂时存储在内存中供程序使用，程序执行完成后内存中的数据就不存在了。
    如果想把内存中的数据保存下来，必须将数据以文件的形式保存在硬盘上。
    把数据写到文件中，或者从文件中读取数据，是对文件的输入输出流的操作来实现。
    fstream 读写文件（文件输入输出流）
    ifstream读文件（文件的输入流）
    ofstream写文件（文件输出流）

    对文件的操作：1）打开文件（读方式，写方式，读写方式）->2）操作（读，写）->3）关闭文件
    打开文件的方式：
        open()方法
            ofstream out_file;
            out_file.open(文件地址, 打开的方式);
        构造函数
            ofstream out_file(文件的地址, 打开的方式);
    操作文件：
        使用插入运算符（适用于基本类型的字符串）
        put();将一个字符写入文件，每次只能写一个字符。
        write();将内存中的一块内容写入文件，一般用于输出数组，自定义类型的数据。
            第一个参数：指定输出数据的内存起始地址，该地址为char*类型。
            第二个参数：写入的字节数，是整型。
            out_file.write((char*)&stu, sizeof(stu));
    关闭文件
        out_file.close();
*/
// #include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "../day11/const03/student.h"
using namespace std;

// int main(void)
// {
//     Student stu(101, "张三", 18);
//     Student stu2(102, "李四", 20);
//     ofstream out_file("test06.txt", ios_base::out);
//     out_file.write((char *)&stu, sizeof(stu));
//     out_file.write((char *)&stu2, sizeof(stu2));
//     out_file.close();
//     return 0;
// }

int main03(void)
{
    //用write()写其它类型的数据到文件
    //write((char *), count)
    //第一个参数：输出数据内存的起始地址
    //第二个参数：所写入数据的字节数
    int array[] = {11, 33, 43, 33, 15, 22, 56};
    ofstream out_file("test06.txt", ios_base::out);
    // cout << "array = " << sizeof(array) << " byte" << endl;
    out_file.write((char *)array, sizeof(array));
    out_file.close();
    return 0;
}

int main02(void)
{
    //以构造函数的方式打开文件
    ofstream out_file("test06.txt", ios_base::out);
    const char *a = "hello world!";
    out_file << a << endl;
    out_file.write(a, strlen(a));
    out_file.put('\n');
    //指针遍历字符串
    for (; *a != '\0';a++)
    {
        out_file.put(*a);
    }
    out_file.put('\n');
    out_file.close();
    return 0;
}

int main(void)
{
    //写的方式打开文件
    //定义文件输出流
    ofstream out_file;
    //参数1：要打开文件的地址
    //参数2：以写的方式打开文件
    out_file.open("test06.txt", ios_base::out);
    out_file << "Hello world" << 'A' << 123465 << endl;
    out_file.put('A').put('\n');
    out_file.write("welcome to xian", 14);
    out_file.put('\n');
    out_file.close();
    return 0;
}