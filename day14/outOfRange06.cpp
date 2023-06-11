/**/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void showString()
{
    try
    {
        string s = "hello world!";
        cout << s.at(15) << endl;
    }
    catch(const out_of_range &e)
    {
        cout << "异常信息：" << e.what() << endl;
    }
    catch(...)
    {
        cout << "捕获所有类型的异常！" << endl;
    }
    cout << "showString()函数结束！" << endl;
}

int main(void)
{
    showString();
    cout << "main()函数结束！" << endl;
    return 0;
}