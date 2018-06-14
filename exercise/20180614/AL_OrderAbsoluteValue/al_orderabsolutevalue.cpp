#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n < 100 && n > 0)
        {
            int Sort[100] = { 0 };
            int sign[100];
            int a, z = 0, j = 0;
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &a);
                if (a < 0)
                {
                    Sort[i] = -a;
                    sign[j] = a;
                    j++;
                }
                else
                    Sort[i] = a;

            }

            sort(Sort, Sort + n);

            for (int i = 0; i < n; i++, z++)
            {
                int q = 0;
                if (z)
                    printf(" ");
                for (int p = 0; p < j; p++)
                {
                    if (Sort[i] == -sign[p])
                        q = 1;
                    if (q)
                        printf("%d", -Sort[i]);
                    else
                        printf("%d", Sort[i]);
                }
            }
        }
    }
    return 0;
}
