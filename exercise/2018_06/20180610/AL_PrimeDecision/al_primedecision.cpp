#include <stdio.h>
#include <math.h>

int a(int n)
{
    int sign = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            sign++;
    }
    if (sign)
        return 1;
    return 0;
}

int main()
{
    int x, y;
    while(scanf("%d %d", &x, &y) != EOF)
    {
        int n = 1;
        if (!(x == 0 && y == 0))
        {
            if (x >= -39 && y <= 50 && x < y)
            {
                for (int i = x; i <= y; i++)
                {
                    if (a(i * i + i + 41))
                    {
                        printf("Sorry\n");
                        n = 0;
                        break;
                    }
                }
                if (n)
                    printf("OK\n");
            }
        }
    }
    return 0;

}


//It is the better
int main00()
{
    int x,y,num,flag,n;

    while(scanf("%d%d",&x,&y)!=EOF)
    {
        int t;
        flag=1;

        for(n=x;n<=y && flag;n++)
        {
            t=n*n+n+41;
            printf("%d\n", t);

            for(num=2;num<=sqrt(t);num++)
            {
                if((t)%num==0)
                {
                    flag=0;
                    break;
                }
            }

        }
        if(flag==0)
            printf("Sorry\n");
        if(flag &&(x!=0 || y!=0))
            printf("OK\n");

    }

    return 0;
}
