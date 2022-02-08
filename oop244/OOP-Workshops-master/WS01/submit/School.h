/* Name: Matin Hosseini Pour
 Email: smmhosseini-pour@myseneca.ca
 Student Number: 151267192
 Section: NBB
*/

#ifndef SCHOOL_H
#define SCHOOL_H

#include <iostream>
#include <cstring>
#include "File.h"

#define TEL_NUMBER 24
#define BASE_num "416 491 5050"

namespace sdds
{
    struct Tel {
        char schoolCode[6];
        int extNumber;
    };

    bool loadTels();
    bool findCode(const char schoolCode[], Tel &tel);
    void displayTels(const Tel* tel);
}

#endif
