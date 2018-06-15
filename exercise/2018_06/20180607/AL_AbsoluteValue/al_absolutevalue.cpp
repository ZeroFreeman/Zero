#include <stdio.h>

int main()
{
    double num;
    while (scanf("%lf", &num) != EOF)
    {
        if (num >= 0)
            printf("%.2lf\n", num);
        else
            printf("%.2lf\n", -num);
    }
    return 0;
}
