// Workshop 7: LAB
// Date: 11/13/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////

#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include <iostream>
#include "Vehicle.h"
using namespace std;

namespace sdds {

    class Truck : public Vehicle{
        double max_weight;
        double current_weight;
        public:
        Truck(const char* i_plate, int i_year, double i_capacity, const char* i_current_add);
        bool addCargo(double i_AddCargo);
        bool unloadCargo();
        ostream& write(ostream& ostr) const;
        istream& read(istream& istr);
    };

    ostream &operator<<(ostream &ostr, const Truck &i_Truck);
    istream &operator>>(istream &istr, Truck &i_Truck);
}






#endif
