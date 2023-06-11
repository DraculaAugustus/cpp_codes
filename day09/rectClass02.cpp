/*
this:当前对象的指针
*/
#include <iostream>
using namespace std;

class Rect
{
    private:
        int length;
        int width;
    public:
        //this是调用该构造函数生成的对象
        //this在构造函数中可写可不写
        //当属性名和构造函数的形参同名时，this必须写，用于区分参数和属性
        Rect(int length, int width)
        {
            // Rect r(5,2 ); this=&r
            this->length = length;
            this->width = width;
        }

        void setLength(int length)
        {
            this->length = length;
        }

        void showInfo()
        {
            // r.showInfo(); this==&r
            cout << "长：" << this->length << ", 宽：" << this->width << endl;
        }
};

int main(void)
{
    Rect r(5, 2);

    return 0;
}