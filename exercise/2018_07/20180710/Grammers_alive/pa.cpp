#include "pa.h"
#include <conio.h>
#include <windows.h>
#include <iostream>

using std::cout;

PA::PA() : ch(0), m(21), n(61), p_m(10), p_n(1)
{
    memset(a, 0, sizeof(a));
}

void PA::gotoxy(int x, int y)
{
    HANDLE hout;
    COORD pos;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y =y;
    SetConsoleCursorPosition(hout, pos);
}

void PA::Init()
{
    for (int i = 0; i < m; i++)
    {
        a[i][0] = 1;
        a[i][n - 1] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        a[0][j] = 1;
        a[m - 1][j] = 1;
    }
}


void PA::Set_map()
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            switch(a[i][j])
            {
            case 1:
                gotoxy(j, i);
                cout << '0';
                break;
            case 2:
                gotoxy(j, i);
                cout << 'M';
                break;
            default:
                break;
            }
        }
    }
}

void PA::move()
{
    if (kbhit())
        ch = getch();


    switch(ch)
    {
    case 'w':
        if (p_m < 20 && p_m > 0)
            p_m--;
        break;
    case 'd':
        if (p_n < 60 && p_n > 0)
            p_n++;
        break;
    case 'a':
        if (p_n < 60 && p_n > 0)
            p_n--;
        break;
    case 's':
        if (p_m < 20 && p_m > 0)
            p_m++;
        break;
    default:
        break;
    }
    a[p_m][p_n] = 2;

    ch = ' ';
}























