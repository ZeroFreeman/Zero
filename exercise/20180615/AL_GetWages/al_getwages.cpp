#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int m, sum = 0;
        int a[5] = {100, 50, 10, 5, 2};
        if (n > 0 && n < 100)
        {
            while (n--)
            {
                scanf("%d", &m);
                for (int i = 0; i < 5; i++)
                {
                    if (m / a[i])
                    {
                        sum += (m / a[i]);
                        m %= a[i];
                    }
                }
                sum += m;
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
