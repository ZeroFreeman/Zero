#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
//#pragma warning(disable:4996)


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


void init_map(void);
void update_food(void);
void move_snake(void);
int is_alive(void);
void get_speed(void);
void gotoxy(int x, int y);
void menu();

int main()
{
   //menu();
    init_map();  //初始化地图
    while (1)
    {
        update_food();	//产生食物
        get_speed();  //获取速度
        move_snake();  //移动
        Sleep(snake.speed);	//移动速度
        if (!(is_alive()))	//蛇的死活(撞墙或自食)
            break;
    }
    printf("Game Over!");
    getch();


    return 0;
}
//initialize
void init_map()
{
    SetConsoleOutputCP(437); //显示大于127的asc码
    //initial food
    srand(time(NULL));
    food.x = rand() % (frame_height - 2) + 1;
    food.y = rand() % (frame_width - 2) + 1;
    if (food.y % 2 != 0)
        food.y++;
    gotoxy(food.x, food.y);
    printf("%c", 233);
    //initial snake
    snake.x[0] = frame_height / 2;
    snake.y[0] = frame_width / 2;
    gotoxy(snake.x[0], snake.y[0]);
    printf("%c", 254);
    snake.len = 3;
    snake.speed = 200;
    for (k = 1;k<snake.len;k++)
    {
        snake.x[k] = snake.x[k - 1] + 1;
        snake.y[k] = snake.y[k - 1];
        gotoxy(snake.x[k], snake.y[k]);
        printf("%c", 254);
    }
    //initial bar
    for (j = 0;j<frame_width;j+=2)
    {
        gotoxy(0, j);
        printf("%c", 254);
        gotoxy(frame_height - 1, j);
        printf("%c", 254);
    }
    for (i = 1;i<frame_height - 1;i++)
    {
        gotoxy(i, 0);
        printf("%c", 254);
        gotoxy(i, frame_width - 2);
        printf("%c", 254);
    }
}
//generate food
void update_food()
{
    SetConsoleOutputCP(437); //显示大于127的asc码
    if (snake.x[0] == food.x&&snake.y[0] == food.y)
    {
        srand(time(NULL));
        food.x = rand() % (frame_height - 2) + 1;
        food.y = rand() % (frame_width - 2) + 1;
        gotoxy(food.x, food.y);
        printf("%c", 233);


        snake.len++;
        grow = 1;
    }
}

//move snake
void move_snake()
{
    SetConsoleOutputCP(437); //显示大于127的asc码
    char sh = ch;
    if (kbhit())
        ch = getch();

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
    case UP:  snake.x[0]--;break;
    case DOWN:  snake.x[0]++;break;
    case LEFT:  snake.y[0] -= 2;break;
    case RIGHT:  snake.y[0] += 2;break;
    default:
        break;
    }
    gotoxy(snake.x[0], snake.y[0]);
    printf("%c", 254);
    grow = 0;
    gotoxy(frame_height / 2, frame_width / 2 * 3);
}
//is alive
int is_alive(void)
{
    if (snake.x[0] == 0 || snake.x[0] == frame_height - 1 || snake.y[0] == frame_width - 1 || snake.y[0] == 0)
        return 0;
    for (k = 1;k<snake.len;k++)
        if (snake.x[k] == snake.x[0] && snake.y[k] == snake.y[0])
            return 0;
    return 1;
}
//speed up
void get_speed(void)
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
//move cursor
void gotoxy(int x, int y)
{
    HANDLE hout;
    COORD pos;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = y;
    pos.Y = x;
    SetConsoleCursorPosition(hout, pos);
}
//menu promote
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
    system("cls");
}
