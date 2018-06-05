#include "classmain.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//进行字符串的输入，各个字符的统计和分类
int TLetterStatic::cinStr()
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
            AH++;
        else if ((getStr[i] >= 104 && getStr[i] <= 110) || (getStr[i] >= 72 && getStr[i] <= 78))
                HN++;
        else if ((getStr[i] >= 110 && getStr[i] <= 122) || (getStr[i] >= 78 && getStr[i] <= 90))
                NZ++;
        else
            other++;
    }
    return 0;
}

void TLetterStatic::reset()
{
    AH = HN = NZ = other = 0;
}

void TANCounter::makeCount(TLetterStatic & a)
{
    AN = a.AH + a.HN;
}

void TANCounter::show(ofstream & fout)
{
    cout << "AN = " << AN << endl;
    fout << "AN = " << AN << endl;
}

void THZCounter::makeCount(TLetterStatic & a)
{
    HZ = a.HN + a.NZ;
}

void THZCounter::show(ofstream & fout)
{
    cout << "HZ = " << HZ << endl;
    fout << "HZ = " << HZ << endl;
}

void TCounter::makeCount(TLetterStatic & a)
{
    other = a.other;
}

void TCounter::show(ofstream & fout)
{
    cout << "other = " << other << endl;
    fout << "other = " << other << endl;
}

void print(TCounter & p, ofstream & fout)
{
    p.show(fout);
}
