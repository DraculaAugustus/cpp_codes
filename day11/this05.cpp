/*
    this:当前的实例对象
    类中的成员函数有几种？
        普通成员函数，常成员函数，构造函数，静态成员函数，
        前三个函数比静态成员函数多一个隐含的的参数this.
        普通成员函数：this是对象指针    stu.setName()
        常成员函数：this的类型是指向对象的常量指针  stu.getName() cosnt
            常量指针：指针的指向可以改变，指向的值不可以变。
        构造函数：构造哪个对象，this就指向哪个对象，Student stu(101,"张三",18);
        静态成员函数是类的函数，没有this指针。

    在哪里使用this？
        构造函数中，属性名和形参一致，用this来区分
            Student(int number, const char *name, int age)
            {
                this->number = number;
                this->age = age;
            }
        成员方法中，属性名和形参一致，也用this来区分
            void setAge(int age)
            {
                this->age = age;
            }
        重载=赋值操作符     return *this;
*/
