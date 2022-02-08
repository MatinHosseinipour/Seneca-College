// Workshop 5: DIY
// Date: 10/28/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"
// prefix d is the default
// prefix i is the input
// prefix t is the temp
using namespace std;
namespace sdds {

	void Mark::setEmpty() {
		d_mark = 0;
		d_grade = 'X';
		d_scale = 0.0;
		d_valid = true;
	}
	Mark::Mark() {
		setEmpty();
	}
	Mark::Mark(int i_mark) {
		setEmpty();
		if (checkValid(i_mark))
		{
			d_mark = i_mark;
			setGPA();
			setGrade();
		}
		else {
			setNotValid();
		}
	}
	void Mark::setNotValid() {
		d_mark = -1;
		d_valid = false;
	}
	bool Mark::checkValid(int i_check) {
		bool check = false;
		if (i_check >= 0 && i_check <= 100)
		{
			check = true;
		}
		return check;
	}
	Mark::operator int() const {
		int mark = 0;
		if (d_valid)
		{
			mark = d_mark;
		}
		return mark;
	}
	Mark& Mark::operator+=(const int i_add) {
		if (d_valid) {
			//but we did not check if the input is valid? like if it is not negative or something?
			int t_sum = d_mark + i_add;
			if (t_sum > 100)
			{
				setNotValid();
			}
			else {
				d_mark += i_add;
				setGPA();
				setGrade();
			}
		}
		return *this;
	}
	Mark& Mark::operator = (const int i_set) {
		if (checkValid(i_set)) {
			d_mark = i_set;
			d_valid = true;
			setGPA();
			setGrade();
		}
		else {
			setNotValid();
		}
		return *this;
	}
	Mark::operator double()const {
		double gpa = 0.0;
		if (d_valid)
		{
			gpa = d_scale;
		}
		return gpa;
	}
	void Mark::setGPA() {
		if (d_mark >= 0 && d_mark < 50)
		{
			d_scale = 0.0;
		}
		else if (d_mark >= 50 && d_mark < 60) {
			d_scale = 1.0;
		}
		else if (d_mark >= 60 && d_mark < 70) {
			d_scale = 2.0;
		}
		else if (d_mark >= 70 && d_mark < 80) {
			d_scale = 3.0;
		}
		else
			d_scale = 4.0;
	}
	Mark::operator char()const {
		char grade = 'X';
		if (d_valid)
		{
			grade = d_grade;
		}
		return grade;
	}
	void Mark::setGrade() {
		if (d_mark >= 0 && d_mark < 50)
		{
			d_grade = 'F';
		}
		else if (d_mark >= 50 && d_mark < 60) {
			d_grade = 'D';
		}
		else if (d_mark >= 60 && d_mark < 70) {
			d_grade = 'C';
		}
		else if (d_mark >= 70 && d_mark < 80) {
			d_grade = 'B';
		}
		else
			d_grade = 'A';
	}
	int operator+=(int& sum, const Mark& i_mark) {
		if (i_mark.d_valid)
		{
			sum += int(i_mark);
		}
		return sum;
	}
}