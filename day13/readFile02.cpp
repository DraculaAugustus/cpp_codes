/*
read(char*, int)读一块连续内存中的数据
write(char*, int)用来读写自定义对象的数据（数组，对象）

写文件的方法
    <<插入操作符，任意类型的数据
    put() 写一个字符
    write(char*, int) 写一个字符串，写一块连续的内存
读文件的方法
    >>提取操作符（以空白符分割）
    get() 只读一个字符（结尾符）
    getline() 按行读
    read(char*, int) 读一块字符空间
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Rect
{
 //一般属性是私有的，只能在类内访问，类外无法访问
 //权限修饰符作用其下所有内容，除非显示修改为其它权限修饰符
 //封装的目的是为了保护数据，限制别人访问，需要在外部访问时给他开启一扇窗（写方法）
private:
 double length;
 double width;
public:
Rect(){}
Rect(double len, double w)
{
    length = len;
    width = w;
}
 //get属性名()  访问属性值
 double getLength()
 {
  return length;
 }
 double getWidth()
 {
  return width;
 }
 //set属性名()  修改|设置属性值
 void setLength(double len=20)
 {
  length = len;
 }
 void setWidth(double w=10)
 {
  width = w;
 }

 //一般类中的方法是公有的，可以在类内访问，也可以在类外访问
 double getArea()
 {
  return length*width;
 }
 //类中的方法可以定义在类内也可以定义在类外
 double getPerimeter();
 //方法的重载
 double getPerimeter(double width, double length);
};

//写对象
void writeRect(const char* url)
{
    Rect r1(10, 7);
    Rect r2(20, 13);
    ofstream out_file(url, ios_base::out);
    out_file.write((char *)&r1, sizeof(r1));
    out_file.write((char *)&r2, sizeof(r2));
    out_file.close();
}
//读对象
void readRect(const char* url)
{
    Rect r1, r2;
    ifstream in_file(url, ios_base::in);
    in_file.read((char *)&r1, sizeof(r1));
    in_file.read((char *)&r2, sizeof(r2));
    in_file.close();
    cout << "面积为：" << r1.getArea() << endl;
    cout << "周长为：" << r1.getPerimeter() << endl;
    cout << "面积为：" << r2.getArea() << endl;
    cout << "周长为：" << r2.getPerimeter() << endl;
}

//写数组
void writeArray(const char* url)
{
    int arr[10] = {11, 2, 4, 33, 6, 8, 5, 3, 9, 13};
    ofstream out_file(url, ios_base::out);
    out_file.write((char *)arr, sizeof(arr));
    out_file.close();
}
//读数组
void readArray(const char* url)
{
    int arr[10];
    ifstream in_file(url, ios_base::in);
    in_file.read((char *)arr, sizeof(arr));
    in_file.close();
    //遍历数组
    for (int i = 0; i < 10;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main01 (void)
{
    const char *url = "file02.txt";
    writeRect(url);
    readRect(url);
    return 0;
}

inline double Rect::getPerimeter()
{
 return 2 * (width + length);
}

double Rect::getPerimeter(double w, double len)
{
 return 2*(w+len);
}