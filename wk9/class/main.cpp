//Pay attention, only include a header in super class, now need to re incude it in main
#include "BigTriangle.h"
#include <iostream>

using namespace std;

int main() {
	Triangle Ob2(1.2, 2.3);
   Ob2.setw(10);
   Ob2.seth(20);
   Ob2.style[0]='T';

   //Ob1.showDim();
   Ob2.showDim();
   cout << Ob2.area() << endl;
   return 0;
}