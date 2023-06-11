/*
内存问题
*/
#include <iostream>
#include <fstream>
#include <cstring>c
using namespace std;

int main(void)
{
    char *pCtmp = new char[10];
    strcpy(pCtmp, "0123456789");
    delete[] pCtmp;

    char temp[] = "this is a test";
    char *p1 = new char[strlen(temp0) + 1];
    strcpy(p1, temp);
    delete[] p1;

    char tmp1[] = "this is a test";
    //sizeof() 内存空间的字节数
    char *p2 = new char[sizeof(tmp1)];
    
    return 0;
}