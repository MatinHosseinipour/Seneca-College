/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
Version 1.0
Author	John Doe
Revision History
Matin Hosseini Pour
151267192
smmhosseini-pour@myseneca.ca
-----------------------------------------------------------
Date      Reason
2020/11/19  Preliminary release
2020/11/19  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/

#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds
{
    IOAble::~IOAble()
    {
    }

    std::ostream &operator<<(std::ostream &os, const IOAble &IOA)
    {
        IOA.write(os);
        return os;
    }
    std::istream &operator>>(std::istream &is, IOAble &IOA)
    {
        IOA.read(is);
        return is;
    }
} // namespace sdds
