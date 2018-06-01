#include <iostream>
#include <fstream>
#include "classmain.h"
using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("result.txt");
    cout << "If you want to exit, you can input '#exit'" << endl;
    cout << "Please input string : " << endl;

    TANCounter t1;
    THZCounter t2;
    t1.reset();

    while(1)
    {
        if (t1.cinStr())
            break;
    }
    TLetterStatic total(t1);

    t1.Show(outfile);
    cout << endl << "------------------------------\n" << endl;
    t1.showAN(total, outfile);
    t2.showHZ(total, outfile);
    total.showOther(outfile);

    outfile.close();
    cout << "The data has been successfully imported into the 'result.txt'" << endl;

   // ofstream outfile;
   // outfile.open("result.txt");

    //void fileOut();

    return 0;
}
