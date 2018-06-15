#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        if (n > 0 && m > 0)
        {
            int a[n][m];
            int k = 0, p = 0, q = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    scanf("%d", &a[i][j]);

                    if (abs(a[i][j]) > abs(k))
                    {
                        k = a[i][j];
                        p = i;
                        q = j;
                    }
                }
            }
            printf("%d %d %d\n", p + 1, q + 1, k);
        }
    }
    return 0;
}
