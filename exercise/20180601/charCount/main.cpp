#include <iostream>
#include <fstream>
#include <time.h>
#include "classmain.h"

using namespace std;

int main()
{
    ofstream fout;
    time_t timer = time(NULL);

    fout.open("result.txt", ios_base::app);
    fout << ctime(&timer);
    cout << "If you want to exit, you can input '#exit'" << endl;
    cout << "Please input string : " << endl;

    TLetterStatic start;
    start.reset();
    while(1)
    {
        if (start.cinStr())
            break;
    }

    TCounter t1;
    TANCounter t2;
    THZCounter t3;
    t1.makeCount(start);
    t2.makeCount(start);
    t3.makeCount(start);

    cout << "------------------------------------------------------"
         << endl;

    print(t1, fout);
    print(t2, fout);
    print(t3, fout);

    fout << endl;
    fout.close();

    return 0;
}
