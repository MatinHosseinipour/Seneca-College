/* Name: Matin Hosseini Pour
 Email: smmhosseini-pour@myseneca.ca
 Student Number: 151267192
 Section: NBB
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "School.h"

using namespace std;
using namespace sdds;

void flushkeys();
bool yes();

int main() {
   bool done = false;
   char schoolCode[6];
   Tel tel;
   if (!loadTels()) {
       //Error no 1: when file did not opened;
	   cout << "Error! No.1";
	   exit(0);
   }
   cout << "Seneca School Extension search." << endl << endl;

   while (!done) {
      cout << "Enter the School code: ";
      cin >> schoolCode;
      flushkeys();
      if ( findCode(schoolCode, tel) ) {
          displayTels(&tel);
      } else {
          cout << schoolCode << " School code not found!" << endl;
      }
      
      cout << "Do another search? (Y)es: ";
      done = !yes();
      cout << endl;
   }

   cout << "Goodbye!" << endl;
   return 0;
}

// flushes the keyboard
void flushkeys() {
   while (cin.get() != '\n');
}

// returns true if user enter y or Y
bool yes() {
   char ch = cin.get();
   flushkeys();
   return ch == 'y' || ch == 'Y';
}