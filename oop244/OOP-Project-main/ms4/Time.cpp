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

#include "Time.h"
#include "utils.h"
using namespace std;

namespace sdds
{


    Time &Time::reset()
    {
        m_min = getTime();
        return *this;
    }

    Time::Time(unsigned int min)
    {
        m_min = min;
    }

    ostream &Time::write(ostream &ostr) const
    {
        ostr.width(2);
        ostr.fill('0');
        int r=m_min/60;
        ostr << r ;
        ostr << ":";
        ostr.width(2);
        int x= m_min % 60;
        ostr << x;
        return ostr;
    }

    istream &Time::read(istream &istr)
    {
        int h, m;
        char c = ' ';
        istr >> h >> c >> m;
        ;
        if (c != ':')
        {
            istr.setstate(ios::failbit);
        }
        else{
        	 m_min = h * 60 + m;
		}
      
        return istr;
    }

    Time::operator int() const
    {
        return m_min;
    }

    Time &Time::operator*=(int val)
    {
        m_min *= val;
        return *this;
    }

    Time &Time::operator-=(const Time &D)
    {
        if (D < int(m_min))
        {
            m_min -= D;
        }
        else
        {
            m_min += 1440;
            m_min -= D;
        }
        return *this;
    }

    ostream &operator<<(ostream &os, const Time &T)
    {
        T.write(os);
        return os;
    }

    istream &operator>>(istream &in, Time &T)
    {
        T.read(in);
        return in;
    }

} // namespace sdds
