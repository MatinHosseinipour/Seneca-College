// Workshop 5: DIY
// Date: 10/28/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

// prefix d is the default
// prefix i is the input
namespace sdds{

	class Mark {
		int d_mark;
		double d_scale;
		char d_grade;

	public:
		bool d_valid;
		void setEmpty();
		Mark();
		Mark(int i_mark);
		void setNotValid();
		bool checkValid(int i_check);
		operator int()const;
		Mark& operator += (const int i_add);
		Mark& operator = (const int i_set);
		operator double()const;
		void setGPA();
		operator char()const;
		void setGrade();
	};
	int operator += (int& sum, const Mark& i_mark);
}
#endif