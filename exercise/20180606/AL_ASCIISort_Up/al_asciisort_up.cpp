#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    char s[3] = { 0 };
    while (scanf("%s", s) != EOF)
    {
        sort(s, s + 3);
        printf("%c %c %c\n", s[0], s[1], s[2]);
    }
    return 0;
}
