#include <stdio.h>

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int a, z = 0, j = 1;
        if (n > 0 && n < 100 && m > 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (z)
                    printf(" ");
                    scanf("%d", &a);
                if (j)
                {
                    if (a < m)
                        printf("%d", a);
                    else
                    {
                        printf("%d %d", m, a);
                        j = 0;
                    }
                }
                else
                    printf("%d", a);
                z++;
            }
            if (j == 1)
                printf(" %d", m);
            printf("\n");
        }
    }
    return 0;

}
