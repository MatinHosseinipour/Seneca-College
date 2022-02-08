// Workshop 7: LAB
// Date: 11/13/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////


#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include<iostream>
using namespace std;

namespace sdds
{

    class Vehicle
    {
        char license_plate[10];
        char address[65];
        int year;

    public:
        Vehicle(const char *i_plate, int i_year);
        void moveTo(const char *i_address);
        ostream &write(ostream &ostr) const;
        istream &read(istream &istr);
    };

    ostream &operator<<(ostream &ostr, const Vehicle &i_Vehicle);
    istream &operator>>(istream &istr, Vehicle &i_Vehicle);

} // namespace sdds

#endif
