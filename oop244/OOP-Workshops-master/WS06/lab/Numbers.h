// Workshop 6: LAB
// Date: 11/06/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
using namespace std;
namespace sdds {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
   public:
      Numbers();
      Numbers(const char* filename);
      double average()const;
      double max()const;
      double min()const;
      ~Numbers();
      Numbers(const Numbers& i_number);
      int numberCount()const;
      bool load();
      void save();
      Numbers& operator= (Numbers& i_number);
      Numbers& operator+= (double i_add);
      ostream& display(ostream& ostr) const;
   };
   ostream& operator<<(ostream& os, const Numbers& number);
   istream& operator>>(istream& istr, Numbers& number);
}
#endif // !SDDS_NUMBERS_H_

