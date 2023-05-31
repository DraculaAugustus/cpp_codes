/*
指针参数
*/

#include <iostream>
using namespace std;
#include <cstring>

// 拼接两个字符串
void stringCat(char *pa, char *pb)
{
    int len = strlen(pa);
    pa = pa + len; // 移到最后一个元素的后面位置
    while (*pb != '\0')
    {
        // 复制并移动
        *pa = *pb;
        pa++;
        pb++;
    }
    *pa = '\0';
}

int main(void)
{
    char a[100] = "ABCDEFG";
    char b[20] = "12345abcdefg";
    stringCat(a, b);
    cout << "a = " << a << endl;

    return 0;
}