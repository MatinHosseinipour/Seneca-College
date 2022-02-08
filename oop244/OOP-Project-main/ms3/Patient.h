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
#include "Ticket.h"
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
namespace sdds {
    class Patient : public IOAble {
        char* p_name = nullptr;
        int OHIPNo;
        Ticket m_ticket;
        bool IOflag;
        public:
        Patient(int ticket_num = 0, bool flag = false);
        Patient(const Patient& p) = delete;
        Patient& operator=(const Patient& p) = delete;
        ~Patient();
        virtual char type() const = 0;
        bool fileIO() const;
        void fileIO(bool value);

        bool operator==(const char c) const;
        bool operator==(const Patient& P) const;

        void setArrivalTime();
        operator Time() const;
        int number() const;
        std::ostream& csvWrite(std::ostream& ostr) const;
        std::istream& csvRead(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);

    };

}
#endif // !SDDS_PATIENT_H_


