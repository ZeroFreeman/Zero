#include <stdio.h>

int main()
{
    int a;
    while (scanf("%d", &a) != EOF)
    {
        if (!a)
            break;
        int zero = 0, positive = 0, complex = 0;
        while (a--)
        {
            double num;
            scanf("%lf", &num);
            if (num > 0)
                positive++;
            else
            {
                if (num < 0)
                    complex++;
                else
                    zero++;
            }
        }
        printf("%d %d %d\n", complex, zero, positive);
    }
    return 0;
}
