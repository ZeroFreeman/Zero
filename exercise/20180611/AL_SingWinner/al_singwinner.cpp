#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n > 2 && n <= 100)
        {
            int i = 0, j = 0, m = 0;
            double sum = 0;
            for (int p = 0; p < n; p++)
            {
                scanf("%d", &m);
                if (p == 0)
                    i = j = m;
                if (m < j)
                    j = m;
                if (m > i)
                    i = m;
                sum += m;
            }
            printf("%.2lf\n", (sum - i - j) / (n - 2));
        }
    }
    return 0;
}
