// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Cornel - 2020/01/08
// Chris - 2021/01/14


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"
size_t g_sysClock = 1;
using namespace std;
namespace sdds {
	Event::Event() {
		setEmpt();
	}
	void Event::display()const {
		unsigned static int counter = 1;
		cout << setw(2) << setfill(' ') << counter << ". ";
		if (i_desc == nullptr)
		{
			cout << "| No Event |" << endl;
		}
		else {
			cout << setw(2) << setfill('0') << t_time_h << ":"
				<< setw(2) << setfill('0') << t_time_m << ":" 
				<< setw(2) << setfill('0') << t_time_s << " => " << i_desc << endl;
		}
		counter++;
	}
	void Event::set(const char i_desc[]) {
		if (i_desc==nullptr || i_desc[0] == '\0')
		{
			setEmpt();
		}
		else {
			int leng = strlen(i_desc) + 1;
			sdds::Event::i_desc = new char[leng];
			strcpy(sdds::Event::i_desc, i_desc);
			calcT();
		}
	}
	void Event::calcT() {
		t_time = g_sysClock;
		t_time_h = t_time / 3600;
		t_time_m = (t_time % 3600) / 60;
		t_time_s = t_time % 60;
	}
	void Event::setEmpt() {
		i_desc = nullptr;
		t_time = 0;
	}
	Event::~Event() {
		i_desc = nullptr;
	}
}