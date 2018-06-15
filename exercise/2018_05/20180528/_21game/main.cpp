#include <iostream>
#include <time.h>
#include <conio.h>
#include "mainclass.h"
using namespace std;

int main()
{

    Menu m;
    m.menu();

    system("cls");

    while (1)
    {


        srand(time(NULL));
        int sign[13] = { 0 };
        int person = 1;
        cout << "\nPlease input How many Player if you want to add: ";
        cin >> person;

        mainClass player;
        int n = 0;
        while (n < person)
        {

            cout << "\nPlayer" << n + 1 << endl;

            for (int j = 0; j < 5; j++)
            {

                if (!player.getCard(sign, j, n))
                {
                    cout << "You had Boom!" << endl;
                    break;
                }
                if (player.win(n))
                    break;
                char ch = getch();
                if (ch == 'n')
                    break;
                else
                    continue;

            }
            n++;

        }

        cout << endl;
        player.chooseWinner(n);



        if (m.Choose() == 1)
            break;
    }


    return 0;
}
