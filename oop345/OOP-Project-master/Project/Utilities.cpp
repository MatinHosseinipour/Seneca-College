// Name:		Matin Hosseini Pour
// Seneca Student ID: 	151267192
// Seneca email:	smmhosseini-pour@myseneca.ca
// Date of completion: April 11th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<string>
#include "Utilities.h"
#include<math.h>
namespace sdds{
    char Utilities::m_delimiter = ' ';
    void Utilities::setFieldWidth(size_t newWidth)
    {
        this->m_widthField = newWidth;
    }
    size_t Utilities::getFieldWidth() const
    {
        return this->m_widthField;
    }
    std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more){
        std::string temp = "";
        size_t i;
        for (i = next_pos; i < str.size(); i++)
        {
            if(str[i]==Utilities::m_delimiter)
                break;
            temp += str[i];
        }
        if(temp==""){
            more = false;
            throw 1;
        }
        more = true;
        if(i>=str.size()-1){
            more = false;
        }
        if(temp.size()>this->m_widthField)
            this->m_widthField = temp.size();
        next_pos = i + 1;
        return temp;
    } 
    void Utilities::setDelimiter(char newDelimiter)
    {
        Utilities::m_delimiter = newDelimiter;
    }
    char Utilities::getDelimiter(){
        return Utilities::m_delimiter;
    }

}