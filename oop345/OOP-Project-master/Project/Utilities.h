// Name:		Matin Hosseini Pour
// Seneca Student ID: 	151267192
// Seneca email:	smmhosseini-pour@myseneca.ca
// Date of completion: April 11th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef UTILITIES
#define UTILITIES
#include<string>
namespace sdds{
    class Utilities{
        public:
        size_t m_widthField;
        static char m_delimiter;

        public:
        Utilities()
        {
            m_widthField = 1;
        } 
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string &str, size_t &next_pos, bool &more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
    };
}
#endif