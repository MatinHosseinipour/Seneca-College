/* Citation and Sources...
Final Project Milestone ?
Module: Utils
Filename: Utils.h
Version 1.0
Author	John Doe
Revision History
Matin Hosseini Pour
151267192
smmhosseini-pour@myseneca.ca
-----------------------------------------------------------
Date      Reason
2020/11/13  Preliminary release
2020/11/13  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
   int getInt();
   int getTime(); // returns the time of day in minutes

   extern bool debug; // this makes bool sdds::debug variable in utils.cpp global to 
                      // all the files which include: "utils.h" 
                      //(you will learn this in detail in oop345)
   int getRandom(int i_min, int i_max);

}
#endif // !SDDS_UTILS_H_

