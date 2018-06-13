#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        cin.ignore();
        string str;
        while (n--)
        {
            int num = 0;
            getline(cin, str);
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] >= 48 && str[i] <= 57)
                    num++;
            }
            cout << num << endl;
        }
    }
    return 0;
}

//#include <stdio.h>

//#define MAXSIZE 4096

//int main(void)
//{
//    int n, count;
//    char s[MAXSIZE], *t;

//    scanf("%d", &n);
//    while(n--) {
//        // 计数清零
//        count = 0;

//        // 读入字符串
//        scanf("%s", s);

//        // 统计数字字符个数
//        t = s;
//        while(*t) {
//            if('0' <= *t && *t <= '9')
//                count++;
//            t++;
//        }

//        // 输出结果
//        printf("%d\n", count);
//    }

//    return 0;
//}
