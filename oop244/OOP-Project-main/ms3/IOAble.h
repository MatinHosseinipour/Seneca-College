/* Citation and Sources...
Final Project Milestone 3
Module: IOAble
Filename: IOAble.h
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

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
namespace sdds
{
    class IOAble
    {
    public:
        virtual std::ostream &csvWrite(std::ostream &ostr) const = 0;
        virtual std::istream &csvRead(std::istream &istr) = 0;
        virtual std::ostream &write(std::ostream &ostr) const = 0;
        virtual std::istream &read(std::istream &istr) = 0;

        virtual ~IOAble();
    };

    std::ostream &operator<<(std::ostream &os, const IOAble &IOA);
    std::istream &operator>>(std::istream &is, IOAble &IOA);
} // namespace sdds
#endif // !SDDS_IOABLE_H_
