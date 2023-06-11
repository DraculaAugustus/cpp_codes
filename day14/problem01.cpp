/*
C++开发中的常见问题
    粗心的问题
    内存问题
    语法错误
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//6.while循环的循环变量没有修正
//sum的变量再次使用时没有清零
//拼写错误，把cout拼写为count
int main(void)
{
    int nCount = 0;
    int sum = 0;
    while (nCount <= 10)
    {
        sum += nCount;
        nCount++;
    }
    // count << "1-10的和为：" << nCount << endl;
    return 0;
}

//5.类定义结束时，缺少一个分号
// class Myclass
// {
//     private:
//         m_mydata;
//     public:
//         int myFun();
// }
//4.在if分支，for, while循环时很容易出现大括号不匹配的问题
//层次分不清

//3.读文件时，打开文件，读写操作完毕后，忘记关闭文件，
//造成文件被占用后面的程序不能操作文件
int main03(void)
{
    ofstream out("D:\\temp.txt");
    char arr[] = "Hello World!";
    out.write(arr, strlen(arr));
}

//2.数组下角标越界的问题
int main02(void)
{
    int nArray[10];
    for (int i = 0; i < 10; i++)
    {
        nArray[i] = i;
    }
    for (int i = 0; i <= 10;i++)//i<=10错误
    {
        cout << nArray[i];
    }
        return 0;
}

/*
粗心问题1：把数字0写成o，把l当成1，
    中文下的分号，中文下的逗号，小括号。
*/
int main01(void)
{
    // int nTemp1 = o;
    // int nTemp2 = o;
    // cout << nTemp1 << endl;
    
    return 0;
}