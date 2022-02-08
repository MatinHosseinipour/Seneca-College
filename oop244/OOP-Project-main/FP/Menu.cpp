/* Citation and Sources...
Final Project Milestone 5
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
2020/12/3 Preliminary release
2020/12/3  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Menu.h"
#include <cstring>
using namespace std;
namespace sdds {
	Menu::Menu() {
		menuText = nullptr;
		numOfMenus = -1;
	}
	Menu::Menu(const char i_menuText[], int i_numM) {
		menuText = nullptr;
		menuText = new char[strlen(i_menuText)+1];
		strcpy(menuText, i_menuText);
		numOfMenus = i_numM;
	}
	int Menu::display() {
		int input = -1;
		do
		{
			cout << menuText << endl 
				<< "0- Exit" << endl
				<< "> ";
			cin >> input;
		} while (input == -1 || input > numOfMenus);
		return input;
	}
	Menu::~Menu() {
		delete[] menuText;
		menuText = nullptr;
	}
}