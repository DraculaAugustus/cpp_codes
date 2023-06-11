/*
文件输出流：ofstream
    ios_base::out
        打开一个输出文件，
        如果打开的文件已存在，删除原有的内容
        如果打开的文件不存在，创建这个文件
        ofstream对象的默认打开方式
    ios_base::app
        打开一个输出文件，用于在文件末尾添加数据，不删除文件原有内容
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(void)
{
    ofstream out("test07.txt",ios_base::app);//append
    out << "hello world!" << endl;
    out.close();
    return 0;
}