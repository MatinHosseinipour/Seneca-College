/* Name: Matin Hosseini Pour
 Email: smmhosseini-pour@myseneca.ca
 Student Number: 151267192
 Section: NBB
*/

#ifndef FILE_H
#define FILE_H

#include <iostream>

namespace sdds
{
    bool openFile(const char filename[]);
    void closeFile();
    bool getSchoolCode(char schoolCode[]);
    bool getExt(int* ext);
}

#endif
