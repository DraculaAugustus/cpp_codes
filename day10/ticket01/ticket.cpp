#include "ticket.h"
#include <iostream>
using namespace std;
// 虚函数分文件写时，只需要在头文件用virtual修饰
void Person::saleTicket()
{
        cout << "普通人全价票！" << endl;
}

void Student::saleTicket()
{
        cout << "学生半价票！" << endl;
}

void Solder::saleTicket()
{
        cout << "军人优先票！" << endl;
}