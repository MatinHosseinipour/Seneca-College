// Workshop 7: LAB
// Date: 11/13/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Vehicle.h"
using namespace std;

namespace sdds {



    Vehicle::Vehicle(const char *i_plate, int i_year){
        strcpy(license_plate, i_plate);
        this->year = i_year;
        strcpy(address, "Factory");
    }

    void Vehicle::moveTo(const char* i_address){
        if (this->address != i_address){
            cout << "|";
            cout.width(8);
            
            cout << license_plate;
            cout << "| |";
            cout.width(20);
            cout << this->address;
            cout << " ---> ";
            cout.width(20);
            cout.setf(ios::left);
            cout << i_address << "|" << endl;
            cout.unsetf(ios::left);
            strcpy(this->address, i_address);
        }
    }

    ostream& Vehicle::write(ostream& ostr) const {
        ostr << "| " << year << " | ";
        ostr << license_plate << " | ";
        ostr << address;
        return ostr;
    }

    istream& Vehicle::read(istream& istr){
        cout << "Built year: ";
        istr >> year;
        cout << "License plate: ";
        istr >> license_plate;
        cout << "Current location: ";
        istr >> address;
        return istr;
    }

    ostream &operator<<(ostream &ostr, const Vehicle &i_Vehicle){
        i_Vehicle.write(ostr);
        return ostr;
    }
    istream &operator>>(istream &istr, Vehicle &i_Vehicle){
        i_Vehicle.read(istr);
        return istr;
    }
}
