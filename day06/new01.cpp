/*
动态内存分配：多个变量
    new---delete
    单个变量：int *p=new int(10);   delete p;   p=nullptr;
    定义数组：int *p=new int[10];   delete [] p;    p=nullptr;
    malloc---free
    int *p=(int*)malloc(num); free(p)
*/
#include <iostream>
using namespace std;
int main1()
{
    //堆中分配连续10int类型的内存空间
    int *p = (int *)malloc(sizeof(int) * 10);
    //初始化
    for (int i = 0; i < 10; i++)
    {
        *(p + i) = i * 10;
    }
    //打印
    for (int i = 0; i < 10; i++)
    {
        cout << *(p + i) << "   ";
    }
    cout << endl;
    //释放内存
    free(p);
    p = nullptr;

    system("pause");
    return 0;
}
int main2()
{
    //malloc()分配内存的大小有参数决定
    //malloc()返回值为任意指针类型void*，需要在内存中存放什么数据类型，就转什么类型
    //指针变量p指向新开辟的内存，如果内存开辟失败，p指向null
    int *p = (int *)malloc(sizeof(int));
    if(p==NULL)
    {
        cout << "can not get memory!" << endl;
    }

    *p = 5;
    cout << "值：" << *p << " ，地址：" << p << endl;
    free(p);
    p = nullptr;
    system("pause");
    return 0;
}
int main01()
{
    int *p = new int[10];

    for (int i = 0; i < 10;i++)
    {
        *(p + i) = i + 1;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    delete[] p;
    p = nullptr;

    system("pause");
    return 0;
}