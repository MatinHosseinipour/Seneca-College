/* Name: Matin Hosseini Pour
 Email: smmhosseini-pour@myseneca.ca
 Student Number: 151267192
 Section: NBB
*/

#define _CRT_SECURE_NO_WARNINGS
#include "File.h"

namespace sdds
{
    FILE* fptr;
    // opens the data file and returns true is successful
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    // closes the data file
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    bool getSchoolCode(char schoolCode[]) {
        return fscanf(fptr, "%s", schoolCode) == 1;
    }
    bool getExt(int* ext) {
        return fscanf(fptr, "%d)", ext) == 1;
    }
}