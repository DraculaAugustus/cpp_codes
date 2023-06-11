/*
一种异常一个类
定义异常类：除数不能为0
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class DivException
{
    public:
        DivException(int id, const char *msg):errId(id), errMsg(msg)
        {}
        int getErrId() const
        {
            return errId;
        }
        const string& what() const
        {
            return errMsg;
        }
    private:
        int errId;
        string errMsg;
};

