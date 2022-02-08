/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
Version 1.0
Author	John Doe
Revision History
Matin Hosseini Pour
151267192
smmhosseini-pour@myseneca.ca
-----------------------------------------------------------
Date      Reason
2020/11/25  Preliminary release
2020/11/25  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
using namespace std;
#include <string.h>
namespace sdds {
   int nextTriageTicket = 1;
 
   TriagePatient::TriagePatient() : Patient(nextTriageTicket) {
       i_symptoms = nullptr;
       nextTriageTicket++;
   }
   char TriagePatient::type() const {
       return 'T';
   }
   std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const {
       Patient::csvWrite(ostr);
       ostr << ",";
       ostr << i_symptoms;
       return ostr;
   }
   std::istream& TriagePatient::csvRead(std::istream& istr) {
       if (i_symptoms != nullptr)
       {
           delete[] i_symptoms;
           i_symptoms = nullptr;
       }
       Patient::csvRead(istr);
       istr.ignore(2000, ',');
       char l_symp[511];
       istr.get(l_symp, 511, '\n');
       int last = strlen(l_symp) + 1;
       i_symptoms = new char[last];
       strcpy(i_symptoms, l_symp);
       //i_symptoms[last] = '\0';
       nextTriageTicket = number() + 1;


       return istr;
   }
   std::ostream& TriagePatient::write(std::ostream& ostr) const {
       if (fileIO())
       {
           csvWrite(ostr);
       }
       else {
           ostr << "TRIAGE" << endl;
           Patient::write(ostr);
           ostr << endl;
           ostr << "Symptoms: " << i_symptoms << endl;
       }
       return ostr;
   }
   std::istream& TriagePatient::read(std::istream& istr) {
       if (fileIO())
       {
           csvRead(istr);
       }
       else {
           if (i_symptoms!= nullptr)
           {
               delete[] i_symptoms;
               i_symptoms = nullptr;
           }
           Patient::read(istr);
           cout << "Symptoms: ";
           char l_symp[511];
           istr.get(l_symp, 511, '\n');
           istr.ignore(2000, '\n');
           int last = strlen(l_symp) + 1;
           i_symptoms = new char[last];
           strcpy(i_symptoms, l_symp);
           //i_symptoms[last] = '\0';
       }
       return istr;
   }
   TriagePatient::~TriagePatient() {
       delete[] i_symptoms;
   }
}