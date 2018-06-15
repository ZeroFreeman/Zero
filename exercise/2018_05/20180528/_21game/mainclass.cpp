#include "mainclass.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;


void Menu::gotoxy(int x, int y)
{
    HANDLE hout;
    COORD pos;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y =y;
    SetConsoleCursorPosition(hout, pos);
}

void Menu::menu()
{
    int i = 0;
    gotoxy(6, 6);
    while(i < 80)
    {
        cout << '*';
        i++;
    }

    gotoxy(10, 8);
    cout << "Please switch the input method to the English state" ;
    gotoxy(10, 10);
    cout << "1.Input the number of people playing with you";
    gotoxy(10, 12);
    cout << "2.If you want to get card again, you can push any button, ";
    gotoxy(12, 14);
    cout << "if you want to keep your score, you can push 'n' ";

    gotoxy(6,16);
    i = 0;
    while(i < 80)
    {
        cout << '*';
        i++;
    }


    gotoxy(6, 20);
    system("pause");
    system("cls");

    i = 0;
    gotoxy(6, 6);
    while(i < 80)
    {
        cout << '*';
        i++;
    }

    gotoxy(16, 8);
    cout << "Player 1 is the master. " ;
    gotoxy(16, 10);
    cout << "It means : ";
    gotoxy(16, 12);
    cout << "If there are other people, the score is the same as the owner";
    gotoxy(16, 14);
    cout << "The winner is master ";

    gotoxy(6,16);
    i = 0;
    while(i < 80)
    {
        cout << '*';
        i++;
    }

    gotoxy(6, 20);
    system("pause");

}

int Menu::Choose()
{
    char str;
    cout << endl << endl;
    cout << "Do you want to try again?" << endl;
    cout << "(Yes/press y, No/press n)" << endl;
    while(1)
    {
        //scanf("%c", &str);
        str = getch();
        if (str == 'y' || str == 'n')
        {
            printf("%c\n", str);
            getch();
            break;
        }
    }

    if (str == 'y')
        return 0;
    else
        return 1;
}



mainClass::mainClass()
{
    cout << "\nGame Start!\n";
}

int mainClass::getCard(int *sign, int j, int n)
{
    do{
        myCard[j] = rand() % 13;
    }while(sign[myCard[j]] > 4 || myCard[j] == 0);

    //cout << cardCount[n] << endl;

    cardCount[n] += myCard[j];
    cout << "My " << j + 1 << " card point is : " << myCard[j] << " \n"
         << "My card point count is " << cardCount[n] << endl;
    if (cardCount[n] > 21)
    {
        cardCount[n] = 0;
        return 0;
    }
    return 1;
}

int mainClass::win(int n)
{
    if (cardCount[n] == 21)
        return 1;
    else
        return 0;
}

void mainClass::chooseWinner(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << cardCount[i] << endl;
    }

    int q = 0;
    for (int p = 1; p < n + 1; p++)
    {

        if (cardCount[q] < cardCount[p])
        {
            q = p;
        }
    }



    cout << "The Winner is player " << q + 1 << endl;
}
