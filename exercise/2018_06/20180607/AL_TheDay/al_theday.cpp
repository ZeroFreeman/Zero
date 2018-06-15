#include <stdio.h>

//注意闰年的限制范围
//普通年（不能被100整除的年份）能被4整除的为闰年。（如2004年就是闰年，1999年不是闰年）；
//世纪年（能被100整除的年份）能被400整除的是闰年。（如2000年是闰年，1900年不是闰年）
int main()
{
    int a, b, c, n;
    while (scanf("%d/%d/%d", &a, &b, &c) != EOF)
    {
        switch (b)
        {
        case 1:
            n = c;
            break;
        case 2:
            n = c + 31;
            break;
        case 3:
            n = c + 59;
            break;
        case 4:
            n = c + 90;
            break;
        case 5:
            n = c + 120;
            break;
        case 6:
            n = c + 151;
            break;
        case 7:
            n = c + 181;
            break;
        case 8:
            n = c + 212;
            break;
        case 9:
            n = c + 243;
            break;
        case 10:
            n = c + 273;
            break;
        case 11:
            n = c + 304;
            break;
        case 12:
            n = c + 334;
        default:
            break;
        }
        if ((a % 4 == 0 && b >= 3 && a % 100 != 0) || a % 400 == 0)
            printf("%d\n", n + 1);
        else
            printf("%d\n", n);
    }
    return 0;
}
