#include <stdio.h>

int main()
{
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF)
    {
        if (x > y)
        {
            int tmp;
            tmp = x;
            x = y;
            y =tmp;
        }
        long sum2 = 0, sum3 = 0;
        for (int i = x; i <= y; i++)
        {
            if (i % 2)
                sum3 += i * i * i;
            else
                sum2 += i * i;
        }
        printf("%ld %ld\n", sum2, sum3);
    }
    return 0;
}
