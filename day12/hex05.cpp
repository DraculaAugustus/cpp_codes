/*
输出其它进制：默认是十进制
                cout << hex;    十六进制
                cout << oct;    八进制
                cout << dec;    十进制
                设置是永久的，直到被修改。
                无二进制控制符，需要使用bitset库。
        表示十六进制：0x为前缀
        表示八进制：0为前缀
        表示二进制：0b为前缀
*/
#include <iostream>
using namespace std;
#include <cstring>
#include <bitset>
#include <iomanip>

int main(void)
{
    int n1 = 100;
    int n2 = 017;
    int n3 = 0xFF;
    //默认输出十进制
    cout << n1 << ", " << n2 << ", " << n3 << endl;
    //输出十六进制
    cout << hex << "十六进制：" << n1 << ", " << n2 << ", " << n3 << endl;
    //输出八进制
    cout << oct << "八进制：" << n1 << ", " << n2 << ", " << n3 << endl;
    //输出十进制
    cout << dec << "十进制：" << n1 << ", " << n2 << ", " << n3 << endl;
    //输出二进制
    int n4 = 0b10000000;
    cout << n4 << endl;
    cout << "二进制：" << bitset<8>(n1) << "\t" << bitset<8>(n2) << "\t" << bitset<12>(n3) << endl;
    return 0;
}