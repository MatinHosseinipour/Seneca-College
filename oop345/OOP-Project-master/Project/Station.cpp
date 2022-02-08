// Name:		Matin Hosseini Pour
// Seneca Student ID: 	151267192
// Seneca email:	smmhosseini-pour@myseneca.ca
// Date of completion: April 11th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<iostream>
#include<iomanip>
#include<string>
#include"Station.h"
namespace sdds{
    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;
    const std::string& Station::getItemName() const{
        return this->item_name;
    }
    size_t Station::getNextSerialNumber(){
        this->serial_no++;
        return this->serial_no-1;
    }
    size_t Station::getQuantity() const{
        return this->quantity;
    }
    void Station::updateQuantity(){
        if(this->quantity!=0)
            this->quantity--;
    }
    void Station::display(std::ostream &os, bool full) const{
        os << "[";
        os <<std::setfill('0')<< std::setw(3)<<this->id;
        os<<std::setfill(' ');
        os << "] Item: ";
        os.setf(std::ios::left);
        os << std::setw(Station::m_widthField) << this->item_name;
        os.unsetf(std::ios::left);
        os << " [";
        os <<std::setfill('0')<<std::setw(6)<< this->serial_no;
        os << "]";
        if(full==false)
        {
            os << "\n";
            return;
        }
        os<<std::setfill(' ');
        os << " Quantity: ";
        os.setf(std::ios::left);
        os << std::setw(Station::m_widthField) << this->quantity;
        os.unsetf(std::ios::left);
        os << " Description: "<<this->description;
        os <<"\n";
    }
}
