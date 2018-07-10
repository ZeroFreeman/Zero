#include <iostream>
#include "pa.h"

using namespace std;

int main()
{
    PA pa;
    while(1)
    {
        pa.move();
        pa.Init();
        pa.Set_map();
        system("cls");
    }

//    //pa.move();
//    pa.Init_map();
//   // system("cls");
    return 0;
}
