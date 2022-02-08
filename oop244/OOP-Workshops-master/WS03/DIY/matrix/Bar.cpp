// Workshop 3: DIY
// Date: 10/11/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Bar.h"

using namespace std;
namespace sdds {
	void Bar::setEmpty() {
		strcpy(title, "\n");
		strcpy(fill_c, "\n");
		value = -1;
	}

	void Bar::set(const char coming_title[21],char coming_fill_c, int coming_value){
		if (coming_value < 0 || coming_value > 100)
		{
			validity = false;
			value = -1;
		}
		else {
			strcpy(title, coming_title);
			strcpy(fill_c, &coming_fill_c);
			value = coming_value;
		}
	}

	bool Bar::valid() const{
		bool val = validity;
		if (value < 0 || value > 100)
		{
			val = false;
		}
		return val;
	}
	void Bar::draw() const {
		if (valid())
		{
			int spaces = (20 - (strlen(title)+1));
			int print_value = value / 2;
			cout << title;
			int i;
			for (i = 0; i < spaces; i++)
			{
				cout << ".";
			}
			cout << "|";
			for (i = 0; i < print_value; i++)
			{
				cout << fill_c;
			}
			cout << endl;
		}
		else {

		}	
	}

	

};