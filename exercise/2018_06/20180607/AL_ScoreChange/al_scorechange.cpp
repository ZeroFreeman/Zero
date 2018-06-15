#include <stdio.h>

int main()
{
    int score;
    while (scanf("%d", &score) != EOF)
    {
        if (score >= 90 && score <= 100)
            printf("A\n");
        else
            if (score >= 80 && score <= 89)
                printf("B\n");
            else
                if (score >= 70 && score <= 79)
                    printf("C\n");
                else
                    if (score >= 60 && score <= 69)
                        printf("D\n");
                    else
                        if (score >= 0 && score <= 59)
                            printf("E\n");
                        else
                            printf("Score is error!\n");
    }

    return 0;
}
