// Workshop 6: LAB
// Date: 11/06/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {

  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }

   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }

   Numbers::Numbers(const Numbers& i_number){
       m_numbers = new double[i_number.m_numCount];
       for (int i = 0; i < i_number.m_numCount; i++)
       {
           m_numbers[i] = i_number.m_numbers[i];
       }
       m_numCount = i_number.m_numCount;
       m_filename = new char[strlen(i_number.m_filename) + 1];
       strcpy(m_filename, i_number.m_filename);
       m_isOriginal = false;
   }

   int Numbers::numberCount()const{
       std::ifstream file(m_filename);
       int count = 0;
       while (file)
       {
           char ch = file.get();
           if (ch == '\n')
           {
               count++;
           }
       }
       return count;
   }

   bool Numbers::load(){
       int i = 0;
       if (m_numCount <= 0)
           return false;
       m_numbers = new double[m_numCount];
       std::ifstream file(m_filename);
       while (file && i < m_numCount)
       {
           double value;
           file >> value;
           m_numbers[i] = value;
           i++;
       }
       return true;
   }
   
   void Numbers::save() {
       if (!(isEmpty()) && m_isOriginal)
       {
           ofstream file(m_filename);
           for (int i = 0; i < m_numCount; i++)
           {
               file << m_numbers[i] << endl;
           }
       }
   }

   Numbers& Numbers::operator=(Numbers& i_number){
       if (!isEmpty())
       {
           delete[] m_numbers;
           delete[] m_filename;
       }
       m_numbers = new double[i_number.m_numCount];
       for (int i = 0; i < i_number.m_numCount; i++)
       {
           m_numbers[i] = i_number.m_numbers[i];
       }
       m_numCount = i_number.m_numCount;
       m_filename = new char[strlen(i_number.m_filename) + 1];
       strcpy(m_filename, i_number.m_filename);
       if (!m_isOriginal) {
           m_isOriginal = false;
       }
       return *this;
   }

   Numbers& Numbers::operator+=(double i_add){
       double* temp = new double[m_numCount + 1];
       for (int i = 0; i < m_numCount; i++)
       {
           temp[i] = m_numbers[i];
       }
       temp[m_numCount] = i_add;
       delete[] m_numbers;
       m_numbers = temp;
       m_numCount++;
       sort();
       return *this;
   }

   ostream& Numbers::display(ostream& ostr) const{
       if (!isEmpty())
       {
           ostr << "=========================" << endl;
           if (m_isOriginal)
           {
               ostr << m_filename;
           }
           else
           {
               ostr << "*** COPY ***";

           }
           ostr << endl;
           for (int i = 0; i < m_numCount - 1; i++)
           {
               ostr << m_numbers[i] << ", ";
           }
           ostr << m_numbers[m_numCount - 1];
           ostr << endl;
           ostr << "-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)" << endl;
           ostr << "Largest number:  " << max() << endl;
           ostr << "Smallest number: " << min() << endl;
           ostr << "Average :        " << average() << endl;
           ostr << "=========================";
       }
       else
       {
           ostr << "Empty list";
       }
       return ostr;
   }

   ostream& operator<<(ostream& os, const Numbers& number){
       number.display(os);
       return os;
   }

   istream& operator>>(istream& istr, Numbers& number)
   {
       double value;
       istr >> value;
       number += value;
       return istr;
   }
}

