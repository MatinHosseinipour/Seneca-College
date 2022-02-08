// Workshop 3: DIY
// Date: 10/11/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "BarChart.h"
using namespace std;
namespace sdds {


	bool BarChart::ifvalid() const {
		int i;
		bool v = true;
		if (added < rows)
			v = false;
		else {
			for (i = 0; i < added; i++)
			{
				if (!bar[i].valid())
				{
					v = false;
				}
			}
		}
		return v;
	}
	void BarChart::init(const char* title, int noOfSampels, char fill) {
		chart_title = new char[strlen(title) + 1];
		strcpy(chart_title, title);
		rows = noOfSampels;
		fill_c = fill;
		bar = new Bar[rows];
		added = 0;
	}
	void BarChart::add(const char* bar_title, int value) {
		if (added < rows) {
			bar[added++].set(bar_title, fill_c, value);
		}
		else {
			cout << "You've added enough so far" << endl;
		}
	}
	void BarChart::draw()const
	{
		if (ifvalid())
		{
			cout << chart_title << endl;
			printdash(71);
			for (int i = 0; i < added; i++)
				bar[i].draw();
			printdash(71);
		}
		else {
			cout << "Invalid Chart!" << endl;
		}
	}

	void BarChart::deallocate()
	{
		delete[] bar;
		delete[] chart_title;
	}

	void BarChart::printdash(int length) const{
		for (int i = 0; i < length; i++) {
			cout << '-';
		}
		cout << endl;
	}

};