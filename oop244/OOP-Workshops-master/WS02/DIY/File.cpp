// Workshop 2: 
// Version: 0.9
// Date: 10/4/2020
// By: Matin Hosseini Pour
// Section: NJJ
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   bool read(int& acc_num) {
       return fscanf(fptr, "%d%*c", &acc_num) == 1;
   }
   bool read(double& acc_bal)
   {
       return fscanf(fptr, "%lf%*c", &acc_bal) == 1;
   }
}