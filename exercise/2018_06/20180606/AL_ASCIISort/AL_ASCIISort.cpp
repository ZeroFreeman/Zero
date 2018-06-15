#include <stdio.h>
#include <stdlib.h>

void show(char *a)
{

    gets(a);

    for (int p = 0; p < 2; p++)
    {
        int k = p;
        for (int q = 1; q < 3; q++)
        {
            if (a[k] > a[q])
            {
                k = q;
            }
        }
        if (k != p)
        {
            int tmp;
            tmp = a[k];
            a[k] = a[p];
            a[p] = tmp;
        }
    }

    for (int i = 0; i < 3; i++)
        printf("%c ", a[i]);

    printf("\n");
}


int main()
{
    char a[4] = { 0 };
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        show(a);
        printf("%d\n", i);
    }


    system("pause");
    return 0;
}
