#include <stdio.h>

int main()
{
   int n = 0;
   while (scanf("%d", &n) != EOF)
   {
       int i = 1;
       for (int j = 0; j < n - 1; j++)
       {
           i = (i + 1) * 2;
       }
       printf("%d\n", i);
   }
   return 0;
}
