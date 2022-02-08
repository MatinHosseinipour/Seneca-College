/* Citation and Sources...
Final Project Milestone ?
Module: Menu
Filename: Menu.cpp
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
#include "utils.h"
#include "Menu.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
    Menu::Menu(const char* text, int NoOfSelections) {
        m_text = nullptr;
        if (text[0] != '\0' && text != nullptr && NoOfSelections > 0) {
            m_noOfSel = NoOfSelections;
            m_text = new char[strlen(text) + 1];
            strcpy(m_text, text);
        }
        else {
            m_text = nullptr;
            m_noOfSel = 0;
        }
    }

    Menu::~Menu() {
        delete[] m_text;
        m_text = nullptr;
    }

    std::ostream& Menu::display(std::ostream& ostr) const {
        if (m_text[0] != '\0' && m_noOfSel > 0) {
            ostr << m_text << endl;
        }
        ostr << "0- Exit" << endl;
        ostr << "> ";
        return ostr;
    }

    int& Menu::operator>>(int& Selection) {
        display();
        Selection = getRandom(0, m_noOfSel);

        return Selection;
    }

}