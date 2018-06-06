#ifndef CLASSMAIN_H
#define CLASSMAIN_H

#include <fstream>
using namespace std;

class TLetterStatic;
class TCounter;
void Count(TCounter & p, TLetterStatic & start);

//输入字符串，遍历全部，将所有字符进行统计并根据四个范围进行分类
class TCounter
{
public:

    void show(TLetterStatic & a, ofstream & fout);
    virtual void makeCount(TLetterStatic & a);
};

//派生类 对符合AN范围的字符进行统计，并打印到指定文件中
class TANCounter : public TCounter
{
public:
    virtual void makeCount(TLetterStatic & a);
};

//派生类 对符合HZ范围的字符进行统计，并打印到指定文件中
class THZCounter : public TCounter
{
public:
    virtual void makeCount(TLetterStatic & a);
};

//获取TCounter类中统计后的数据进行保护和方便操作
class TLetterStatic
{
    int AN;
    int HZ;
    int other;

    friend class TCounter;
    friend class TANCounter;
    friend class THZCounter;

public:
    int cinStr(TCounter & t1, TCounter & t2, TCounter & t3, TLetterStatic & start);
    void reset();
};

#endif // CLASSMAIN_H
