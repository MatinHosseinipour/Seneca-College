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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Patient::Patient(int ticket_num, bool flag) :m_ticket(ticket_num){
        
        IOflag = flag;
    }

    Patient::~Patient(){
        delete[] p_name;
        p_name = nullptr;
    }
    bool Patient::fileIO() const{
        return IOflag;
    }
    void Patient::fileIO(bool value){
        IOflag = value;
    }

    bool Patient::operator==(const char c) const{
        return c == type();

    }
    bool Patient::operator==(const Patient &P) const{
        return this->type() == P.type();
    }

    void Patient::setArrivalTime(){
        m_ticket.resetTime();
    }
    Patient::operator Time() const{
    return Time(m_ticket);
    }
    int Patient::number() const{
        return m_ticket.number();
    }
    std::ostream& Patient::csvWrite(std::ostream &os) const{
        os << type() << "," << p_name << "," << OHIPNo << ",";
        m_ticket.csvWrite(os);
        return os;
    }
    std::istream& Patient::csvRead(std::istream &is){
        char arr[51];
        is.get(arr, 51, ',');
        if (p_name != nullptr){
            delete[] p_name;
            p_name = nullptr;
        }
        p_name = new char[51];
        strncpy(p_name, arr, 50);
        p_name[50] = '\0';
        is.ignore(2000, ',');
        is >> OHIPNo;
        is.ignore();
        m_ticket.csvRead(is);
        return is;
    }
        std::ostream& Patient::write(std::ostream & os) const{
            m_ticket.write(os);
            os << endl;
            os << p_name << ", OHIP: " << OHIPNo;
            return os; 
        }
        std::istream& Patient::read(std::istream & is){
            char arr[51];
            cout << "Name: ";
            is.get(arr, 51, '\n');
            if (p_name != nullptr)
            {
                delete[] p_name;
                p_name = nullptr;
            }
            p_name = new char[51];
            strncpy(p_name, arr, 50);
            p_name[50] = '\0';
            is.ignore(2000, '\n');
            cout << "OHIP: ";
            OHIPNo = getIntInRange(100000000, 999999999);
            return is;
        }
}
