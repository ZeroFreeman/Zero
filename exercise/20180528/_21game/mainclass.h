#ifndef MAINCLASS_H
#define MAINCLASS_H

class mainClass
{
    int myCard[5] = { 0 };
    int cardCount[5] = { 0 };

public:
    mainClass();
    int getCard(int *sign, int j, int n);
    int win(int n);
    void chooseWinner(int n);


};


class Menu
{
public:
    void gotoxy(int x, int y);
    void menu();
    int Choose();

};

#endif // MAINCLASS_H
