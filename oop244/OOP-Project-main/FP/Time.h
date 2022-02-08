/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.h
Version 1.0
Author	John Doe
Revision History
Matin Hosseini Pour
151267192
smmhosseini-pour@myseneca.ca
-----------------------------------------------------------
Date      Reason
2020/11/13  Preliminary release
2020/11/13  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/


#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
namespace sdds
{
    class Time
    {
        unsigned int m_min;

    public:
    	
        Time &reset();
        Time(unsigned int min = 0);
        std::ostream &write(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);
        operator int() const;
        Time &operator*=(int val);
        Time &operator-=(const Time &D);
        Time operator-(const Time & ROperand);
    };
    std::ostream& operator<<(std::ostream& ostr, const Time& i_Time);
    std::istream& operator>>(std::istream& istr, Time& i_Time);
    // helper operator << and >> prototypes

} // namespace sdds

#endif // !SDDS_TIME_H
