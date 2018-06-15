#include "classmain.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//进行字符串的输入，各个字符的统计和分类
int TLetterStatic::cinStr(TCounter & t1, TCounter & t2, TCounter & t3, TLetterStatic & start)
{
    string str;
    //cout << "Please input a string : " << endl;
    getline(cin, str);
    if (strcmp(str.c_str(), "#exit") == 0)
        return 1;
    char getStr[strlen(str.c_str() + 1)];
    strcpy(getStr, str.c_str());
    for (unsigned int i = 0; i < strlen(getStr); i++)
    {
        if ((getStr[i] >= 97 && getStr[i] <= 104) || (getStr[i] >= 65 && getStr[i] <= 72))
            Count(t2, start);
        else
        {
            if ((getStr[i] >= 104 && getStr[i] <= 110) || (getStr[i] >= 72 && getStr[i] <= 78))
            {
                Count(t2, start);
                Count(t3, start);
            }
            else
            {
                if ((getStr[i] >= 110 && getStr[i] <= 122) || (getStr[i] >= 78 && getStr[i] <= 90))
                    Count(t3, start);
                else
                    Count(t1, start);
            }
        }
    }
    return 0;
}

void TLetterStatic::reset()
{
    AN = HZ = other = 0;
}

void TANCounter::makeCount(TLetterStatic & a)
{
    a.AN++;
}

void THZCounter::makeCount(TLetterStatic & a)
{
    a.HZ++;
}

void TCounter::makeCount(TLetterStatic & a)
{
    a.other++;
}


void Count(TCounter & p, TLetterStatic & start)
{
    p.makeCount(start);
}

void TCounter::show(TLetterStatic & a, ofstream & fout)
{
    cout << "AN = " << a.AN << endl
         << "HZ = " << a.HZ << endl
         << "other = " << a.other << endl;
    fout << "AN = " << a.AN << endl
         << "HZ = " << a.HZ << endl
         << "other = " << a.other << endl;
}
