#include <stdio.h>

double result(int a)
{
    double sum = 0;
    for (int i = 1; i <= a; i++)
    {
        double j = i;
        if (i % 2)
            sum += 1 / j;
        else
            sum -= 1 / j;
    }
    return sum;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n > 0 && n < 100)
        {
            double a;
            for (int i = 0; i < n; i++)
            {
                scanf("%lf", &a);
                printf("%.2lf\n", result(a));
            }
        }

    }

}
