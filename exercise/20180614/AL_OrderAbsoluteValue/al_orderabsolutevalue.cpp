#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
    return abs(a) > abs(b);
}



int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n > 0 && n < 100)
        {
            int a[100];
            int j = 0;
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &a[i]);
            }

            sort(a, a + n, comp);

            for (int i = 0; i < n; i++, j++)
            {
                if (j)
                    printf(" ");
                printf("%d", a[i]);
            }
            printf("\n");
        }

    }
    return 0;
}
