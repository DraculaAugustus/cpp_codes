/*
1.流：一种抽象的形态，计算机中的数据从一个对象流向另一个对象。
    按照流出的方向来分类：
        输入流：cin,数据从硬盘（文件）或者键盘流向内存。
        输出流：cout,数据从内存流向硬盘（文件），显示器等输出设备。
            ios_base所有流对象的基类
        istream输入流     ostream输出流
                iostream(既有输入，又有输出)    8个对象cin, cout, cerr, clog

        istream(iostream, ifstream文件输入流)
        ostream(iostream, ofstream文件输出流)
        iostream(fstream读写文件)
2.cout输出
    cout<<""<<"";
    cout不是关键字，它是ostream中的对象
    <<插入运算符，将数据插入到一个输出流对象中，是ostream类重载过的操作符。
3.<<可以输出字符，字符串，表达式
    cout.put() 用于输出一个字符
    cout.write("", len)用于输出一个字符串，第二个参数用于指定输出字符串的长度
4.cin输入，不是关键字，是istream中的一个对象
    >> 提取运算符，从输入流对象中提取出数据来
5.>> 提取int, char, float, 提取字符串，不能提取空格符，制表符，回车符
    get()   提取一个字符    可以是普通字符，空格符，制表符，回车符
    获取一行，以回车符分割叫做一行（无法提取回车符）
    getline(char *, int);int表示输入字符串的长度
    第三个参数自定义分割符，默认以回车符为分割符
    getline(char *, int, char);char表示自定义分割符
*/
#include <iostream>
using namespace std;
#include <cstring>

int main(void)
{
    //回车分割一行，提取空格，tab, \n
    char str[20];
    cin.getline(str, 10, '@');
    cout << str << endl;
    return 0;
}

int main03(void)
{
    // char c0;
    // cin.get(c0);     //能提取普通字符，制表符，空格符，回车符
    // cout << "提取的字符为：" << c0 << endl;

    //用循环的方式提取字符串
    char str[100];
    int n = 0;
    char c;
    cin.get(c);
    str[n++] = c;
    //碰到回车符，不再提取
    while(c!='\n')
    {
        cin.get(c);//读控制台的字符
        str[n++] = c;//
    }
    str[--n] = '\0';
    cout << "输入的的字符串为：" << str << endl;
    return 0;
}

int main02(void)
{
    //>>提取运算符，可以提取int, char, 也可以提取字符串
    int a;
    cin >> a;
    cout << "整型：" << a << endl;

    char buf[100];
    cin >> buf;
    buf[strlen(buf) + 1] = '\0';
    cout << "字符串：" << buf << endl;
    return 0;
}

int main01(void)
{
    //输出一个字符
    cout.put('A').put('B').put('\n');

    //插入操作符既可以输出字符，也可以是字符串，还可以是表达式
    cout << 'A' << "B" << endl;
    cout << "AB" << endl;

    //输出一个字符串
    //第二个参数：是输出字符串的长度
    cout.write("hello world", 5).put('\n');
    cout.write("hello world", strlen("hello world")).put('\n');
    return 0;
}