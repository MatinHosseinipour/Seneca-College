// Name:		Matin Hosseini Pour
// Seneca Student ID: 	151267192
// Seneca email:	smmhosseini-pour@myseneca.ca
// Date of completion: April 11th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef STATION
#define STATION
#include <string>
#include "Utilities.h"
namespace sdds
{
    class Station
    {
    public:
        int id;
        std::string item_name;
        std::string description;
        size_t serial_no;
        size_t quantity;
        static size_t m_widthField;
        static size_t id_generator;

    public:
        Station(){
            
        }
        Station(const std::string &str)
        {
            id_generator++;
            id = id_generator;
            Utilities u;
            size_t next_pos = 0;
            bool more = true;
            if (more)
                item_name = u.extractToken(str, next_pos, more);
            if (more)
                serial_no = stoi(u.extractToken(str, next_pos, more));
            if (more)
                quantity = stoi(u.extractToken(str, next_pos, more));
            size_t U_fieldWidth = u.getFieldWidth();
            if (U_fieldWidth > m_widthField)
                m_widthField = U_fieldWidth;
            if (more)
                description = u.extractToken(str, next_pos, more);
        }
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream &os, bool full) const;
    };
}

#endif