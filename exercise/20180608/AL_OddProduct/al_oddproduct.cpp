#include <stdio.h>

int main()
{
    int i;
    while (scanf("%d", &i) != EOF)
    {
        int num = 1;
        while (i--)
        {
            int a;
            scanf("%d", &a);
            if (a % 2)
                num *= a;
        }
        printf("%d\n", num);
    }
    return 0;

}
