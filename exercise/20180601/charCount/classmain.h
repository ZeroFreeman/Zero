#ifndef CLASSMAIN_H
#define CLASSMAIN_H

#include <fstream>
using namespace std;

class TLetterStatic;

//输入字符串，遍历全部，将所有字符进行统计并根据四个范围进行分类
class TCounter
{
protected:
    int AH;
    int HN;
    int NZ;
    int other;

    friend class TLetterStatic;

public:
    void Show(ofstream& outfile);
    int cinStr();
    void reset();

    //void classify(char *getStr, int len);
};

//派生类 对符合AN范围的字符进行统计，并打印到指定文件中
class TANCounter : public TCounter
{
    int AN = 0;

public:
    void showAN(TLetterStatic& a, ofstream& outfile);
};

//派生类 对符合HZ范围的字符进行统计，并打印到指定文件中
class THZCounter : public TCounter
{
    int HZ = 0;

public:
    void showHZ(TLetterStatic& a, ofstream& outfile);
};

//获取TCounter类中统计后的数据进行保护和方便操作
class TLetterStatic
{
    int AH = 0;
    int HN = 0;
    int NZ = 0;
    int other = 0;

    friend class TANCounter;
    friend class THZCounter;

public:
    TLetterStatic(TCounter& a);
    void showOther(ofstream& outfile);
};

//void fileOut();

#endif // CLASSMAIN_H
