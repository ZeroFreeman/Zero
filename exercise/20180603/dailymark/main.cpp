#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main()
{
    ofstream a;
    time_t timer = time(NULL);
    a.open("Sign_In.txt", ios_base::app);
    a << ctime(&timer);

    a.close();

    return 0;
}