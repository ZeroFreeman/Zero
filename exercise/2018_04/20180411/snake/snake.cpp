#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define frame_height 30 //define map size
#define frame_width 60
#define UP 'w' //define operate key
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'


int i, j, k;
char ch = UP; //initial direction
int grow = 0; //flag: if snake grow


struct Food {
    int x;
    int y;
}food;

struct Snake {
    int x[50];
    int y[50];
    int len;
    int speed;
}snake; //snake[0] is head

void gotoxy(int x, int y)
{
    HANDLE hout;
    COORD pos;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y =y;
    SetConsoleCursorPosition(hout, pos);
}

void menu()
{
    int i = 0;
    gotoxy(6, 6);
    while(i < 80)
    {
        printf("*");
        i++;
    }
    gotoxy(10, 10);
    printf("Please switch the input method to the English state");
    gotoxy(10, 12);
    printf("Operation instructions: W is up, s is down, a is left, D is right.");
    gotoxy(6,16);
    i = 0;
    while(i < 80)
    {
        printf("*");
        i++;
    }
    gotoxy(6, 20);
    system("pause");

}


void init_map()
{
    SetConsoleOutputCP(437); //显示大于127的asc码
    //initial food
    system("cls");
    srand(time(NULL));
    food.x = rand() % (frame_width - 4) + 2;
    food.y = rand() % (frame_height - 2) + 1;
    if (food.x % 2 != 0)
        food.x--;
    gotoxy(food.x, food.y);
    printf("%c", 233);
    //initial snake
    snake.x[0] = frame_width / 2;
    snake.y[0] = frame_height / 2;
    gotoxy(snake.x[0], snake.y[0]);
    printf("%c", 254);
    snake.len = 3;
    snake.speed = 200;

    for (k = 1;k<snake.len;k++)
    {
        snake.x[k] = snake.x[k - 1];
        snake.y[k] = snake.y[k - 1] + 1;
        gotoxy(snake.x[k], snake.y[k]);
        printf("%c", 254);
    }
    for (i = 0; i < frame_width; i += 2)
    {
        gotoxy(i, 0);
        printf("%c", 254);
        gotoxy(i, frame_height - 1);
        printf("%c", 254);
    }
    for (j = 0; j < frame_height; j++)
    {
        gotoxy(0, j);
        printf("%c", 254);
        gotoxy(frame_width - 2, j);
        printf("%c", 254);
    }
    gotoxy(87, 10);
    printf("Your Score : 0");
}

void update_food()
{
    SetConsoleOutputCP(437); //显示大于127的asc码
    if (snake.x[0] == food.x&&snake.y[0] == food.y)
    {
        srand(time(NULL));
        food.x = rand() % (frame_width - 4) + 2;
        food.y = rand() % (frame_height - 2) + 1;
        if (food.x % 2 != 0)
            food.x--;
        gotoxy(food.x, food.y);
        printf("%c", 233);
        snake.len++;
        gotoxy(100, 10);
        printf("%d", snake.len - 3);
        grow = 1;
    }
}

void move_snake()
{
    SetConsoleOutputCP(437); //显示大于127的asc码
    char sh = ch;
    //printf("%c", sh);
    if (kbhit())
        ch = getch();
    if (!(ch == 'w' || ch == 's' || ch == 'a' || ch == 'd'))
    {
        ch = sh;
        //printf("%c", ch);
    }
    if (!grow)
    {
        gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]);
        printf(" ");
    }
    for (k = snake.len - 1;k>0;k--)
    {
        snake.x[k] = snake.x[k - 1];
        snake.y[k] = snake.y[k - 1];
    }
    switch (ch)
    {
    case UP:
        if (sh == 's')
        {
            snake.y[0]++;
            ch = sh;
        }
        else
            snake.y[0]--;
        break;
    case DOWN:
        if (sh == 'w')
        {
            snake.y[0]--;
            ch = sh;
        }
        else
            snake.y[0]++;
        break;
    case LEFT:
        if (sh == 'd')
        {
            snake.x[0] += 2;
            ch = sh;
        }
        else
            snake.x[0] -= 2;
        break;
    case RIGHT:
        if (sh == 'a')
        {
            snake.x[0] -= 2;
            ch = sh;
        }
        else
            snake.x[0] += 2;
        break;
    default:
        break;
    }
    gotoxy(snake.x[0], snake.y[0]);
    printf("%c", 254);
    grow = 0;
    gotoxy(frame_width / 2 * 3, frame_height / 2);
}

void get_speed()
{
    if (snake.len <= 6)
        snake.speed = 200;
    else if (snake.len <= 10)
        snake.speed = 100;
    else if (snake.len <= 20)
        snake.speed = 50;
    else if (snake.len <= 30)
        snake.speed = 30;
    else snake.speed = 20;
}

int is_alive(void)
{
    if (snake.x[0] == 0 || snake.x[0] == frame_width - 2 || snake.y[0] == frame_height - 1 || snake.y[0] == 0)
        return 0;
    for (k = 1;k<snake.len;k++)
        if (snake.x[k] == snake.x[0] && snake.y[k] == snake.y[0])
            return 0;
    return 1;
}

int Choose()
{
    char str;
    gotoxy(80, 12);
    printf("Do you want to try again?");
    gotoxy(80, 13);
    printf("(Yes/press y, No/press n)");
    while(1)
    {
        //scanf("%c", &str);
        str = getch();
        if (str == 'y' || str == 'n')
        {
            printf("%c", str);
            getch();
            break;
        }
    }

    if (str == 'y')
        return 0;
    else
        return 1;
}

int main()
{
    SetConsoleOutputCP(437);
    menu();

    while(1)
    {
        init_map();
        while(1)
        {
            update_food();
            get_speed();
            move_snake();
            Sleep(snake.speed); //移动速度
            if (!(is_alive()))  //蛇的死活(撞墙或自食)
                break;
        }
        printf("Game Over!");
        //getch();
        if (Choose() == 1)
            break;
    }

    //printf("\n");
    //system("pause");
    return 0;
}
