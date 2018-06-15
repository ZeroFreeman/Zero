#include <stdio.h>

int main()
{
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        //printf("(");
        int j = 0;
        for (int i = m; i <= n; i++)
        {
            if (i == ((i / 100) * (i / 100) * (i / 100) + (i % 10) * (i % 10) * (i % 10) + (i % 100 /10) * (i % 100 /10) * (i % 100 /10)))
            {
                if (j > 0)
                    printf(" ");
                printf("%d", i);
                j++;
            }
        }
        if (j == 0)
            printf("no");
        printf("\n");

    }
    return 0;
}

