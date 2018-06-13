#include <stdio.h>

int cow(int n)
{
    if(n <= 4)
        return n;
    else
        return cow(n-1) + cow(n-3);
}

int main(void)
{
    int n;

    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)
            break;
        printf("%d\n", cow(n));
    }

    return 0;
}
