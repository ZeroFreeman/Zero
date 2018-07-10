#ifndef PA_H
#define PA_H


class PA
{
    char ch;
    int m, n, p_m, p_n;
    int a[20][60];

public:
    PA();
    void Init();

    void Set_map();
    void gotoxy(int x, int y);
    void move();
};

#endif // PA_H
