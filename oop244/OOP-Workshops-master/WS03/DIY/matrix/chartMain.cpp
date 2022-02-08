// Workshop 3:
// Version: 0.9
// Date: 10/02/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the BarChart section of your DIY workshop
/////////////////////////////////////////////

#include <iostream>
#include "BarChart.h"
using namespace sdds;
using namespace std;
int main() {
   BarChart bc;
   bc.init("How much students like this lab.", 5, '=');
   bc.add("Best Lab Ever", 10);
   bc.add("Good Lab", 30);
   bc.add("Doable Lab", 40);
   cout << "Premature draw call:"<< endl; 
   bc.draw(); // will not draw; it will print an error instead
   bc.add("Bad Lab", 15);
   bc.add("Worst Lab Ever", 5);
   cout << "Proper draw call after all sampels are entered:" << endl;
   bc.draw();
   bc.deallocate();
   return 0;
}
