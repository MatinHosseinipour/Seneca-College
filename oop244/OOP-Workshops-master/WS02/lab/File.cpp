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
    //TODO: read functions go here    
   bool read(char m_name[]) {
        return fscanf(fptr, "%[^,],", m_name) == 1;
   }
   bool read(int& m_studentnumber) {
       return fscanf(fptr, "%d,", m_studentnumber) == 1;
   }
   bool read(double& m_gpa) {
       return fscanf(fptr, "%lf\n", m_gpa) == 1;
   }
   
}