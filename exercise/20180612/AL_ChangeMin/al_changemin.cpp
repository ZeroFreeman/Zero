#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i, m = 0, k = 0;
        int a[100];
        if (n <= 100 && n > 0)
        {
            for (i = 0; i < n; i++)
            {
                scanf("%d", &a[i]);
                if (a[k] > a[i])
                    k = i;
            }

            int tmp;
            tmp = a[k];
            a[k] = a[0];
            a[0] = tmp;

            for (i = 0; i < n; i++)
            {
                if (m)
                {
                    printf(" ");
                }
                printf("%d", a[i]);
                m++;
            }
            printf("\n");
        }
    }
    return 0;
}
