// Workshop 7: LAB
// Date: 11/13/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Truck.h"

using namespace std;

namespace sdds {
    Truck::Truck(const char *i_plate, int i_year, double i_capacity,const char* i_current_add) : Vehicle(i_plate, i_year) {
        moveTo(i_current_add);
        max_weight = i_capacity;
        current_weight = 0;
    }

    bool Truck::addCargo(double i_AddCargo){
        bool valid;
        valid = current_weight < max_weight;
        current_weight += i_AddCargo;
        if(current_weight > max_weight){
            current_weight = max_weight;
        }       
        return valid;
    }

    bool Truck::unloadCargo(){
        bool valid = false;
        if(current_weight > 0){
            current_weight = 0;
            valid = true;
        }
        return valid;
    }

    ostream& Truck::write(ostream& ostr) const{
        Vehicle::write(ostr);
        ostr << " | " << current_weight << "/" << max_weight;
        return ostr;
    }

    istream& Truck::read(istream& istr) {
        Vehicle::read(istr);
        cout << "Capacity: ";
        istr >> max_weight;
        cout << "Cargo: ";
        istr >> current_weight;
        return istr;
        

        
    }

    ostream &operator<<(std::ostream &ostr, const Truck &i_Truck){
        i_Truck.write(ostr);
        return ostr;
    }
    istream &operator>>(std::istream &istr, Truck &i_Truck){
        i_Truck.read(istr);
        return istr;
    }
}
