#ifndef CLASSMAIN_H
#define CLASSMAIN_H

#include <fstream>
using namespace std;

class TLetterStatic;
class TCounter;
void print(TCounter & p, ofstream & fout);

//输入字符串，遍历全部，将所有字符进行统计并根据四个范围进行分类
class TCounter
{
    int other;

public:
    void makeCount(TLetterStatic & a);
    virtual void show(ofstream & fout);
};

//派生类 对符合AN范围的字符进行统计，并打印到指定文件中
class TANCounter : public TCounter
{
    int AN;

public:
    void makeCount(TLetterStatic & a);
    virtual void show(ofstream & fout);
};

//派生类 对符合HZ范围的字符进行统计，并打印到指定文件中
class THZCounter : public TCounter
{
    int HZ;

public:
    void makeCount(TLetterStatic & a);
    virtual void show(ofstream & fout);
};

//获取TCounter类中统计后的数据进行保护和方便操作
class TLetterStatic
{
    int AH;
    int HN;
    int NZ;
    int other;

    friend class TCounter;
    friend class TANCounter;
    friend class THZCounter;

public:
    int cinStr();
    void reset();
};

#endif // CLASSMAIN_H
