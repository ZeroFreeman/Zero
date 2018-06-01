#include "classmain.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//进行字符串的输入，各个字符的统计和分类
int TCounter::cinStr()
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

//给分类计数器设置为0
void TCounter::reset()
{
    AH = HN = NZ = other = 0;
}

void TCounter::Show(ofstream& outfile)
{
    cout << "AH = " << AH << endl
         << "HN = " << HN << endl
         << "NZ = " << NZ << endl
         << "other = " << other << endl;
    outfile << "AH = " << AH << endl
            << "HN = " << HN << endl
            << "NZ = " << NZ << endl
            << "other = " << other << endl << endl;
}

void TLetterStatic::showOther(ofstream& outfile)
{
    cout << "Other = " << other << endl;
    outfile << "Other = " << other << endl;
}

//统计AN区间内字符个数
void TANCounter::showAN(TLetterStatic& a, ofstream& outfile)
{
    AN = a.AH + a.HN;
    cout << "AN = " << AN  << endl;
    outfile << "AN = " << AN  << endl;
}

//统计HZ区间内的字符个数
void THZCounter::showHZ(TLetterStatic& a, ofstream& outfile)
{
    HZ = a.HN + a.NZ;
    cout << "HZ = " << HZ << endl;
    outfile << "HZ = " << HZ << endl;
}

TLetterStatic::TLetterStatic(TCounter& a)
{
    this->AH += a.AH;
    this->HN += a.HN;
    this->NZ += a.NZ;
    this->other += a.other;
}

/*
void fileOut()
{
    ofstream outfile;
    outfile.open("result.txt");
    outfile << "AN = " <<
}
*/
