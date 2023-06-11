/*
隐藏：hide(重定义)
    在子类中定义和父类方法名完全相同的方法，不管参数列表和返回值是否相同，
    基类函数都会被隐藏。
*/
#include <iostream>
#include "animalClass03.cpp"
using namespace std;

class Cat :public Animal
{
    public:
        void showInfo(int num)
        {
            cout << num << endl;
        }
};

int main(void)
{
    Cat c;
    //c.showInfo();

    return 0;
}