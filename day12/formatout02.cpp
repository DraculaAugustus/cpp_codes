/*
格式化输出
    设置域宽，填充字符，输出精度。
1）流扩展字符setw，setfill，setprecision    头文件iomanip
2）成员函数width()   fill()  precision()

1.设置域宽setw(6) width
    如果输出的数据宽度小于设置的域宽，将以默认右对齐的方式输出数据，
    左边默认用空格填充。
    如果输出的数据宽度大于设置的域宽，输出所有数字。
    只对下一次的输出有效（一次性设置）

    int w = width(6);
    返回上次设置的域宽，默认的域宽是0；
*/
#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

// int main(void)
// {
//     const char *str[3] = {"abc", "abcde", "abcdefgh"};
//     //右对齐输出字符串数组中的元素，域宽设置为8即可
//     for (int i = 0; i < 3; i++)
//     {
//         cout.width(8);
//         cout << str[i] << endl;
//     }
//         return 0;
// }

int main(void)
{
    cout << 1234567890 << endl;
    int w = cout.width(6);
    cout << "返回上一次设置的域宽：" << w << endl;
    cout.width(6);
    cout << 123 << endl;
    cout << 256 << endl;
    cout.width(6);
    w = cout.width(6);
    cout << "返回上一次设置的域宽：" << w << endl;
    cout << 1234567 << endl;
    return 0;
}

int main01(void)
{
    cout << 1234567890 << endl;
    //输出字符宽度为6
    cout << setw(6) << 4.5 << endl;
    cout << setw(6) << 12345678 << endl;//如果输出的数字宽度大于设置的域宽，输出所有数字
    cout << 33 << endl;//setw()只对下一次的输出有效（一次性的设置）
    return 0;
}