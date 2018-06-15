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
    TCounter t1;
    TANCounter t2;
    THZCounter t3;
    start.reset();
    while(1)
    {
        if (start.cinStr(t1, t2, t3, start))
            break;
    }

    cout << "------------------------------------------------------"
         << endl;

    t1.show(start, fout);

    fout << endl;
    fout.close();

    return 0;
}
