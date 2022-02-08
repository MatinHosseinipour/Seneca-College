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
		if (i_desc != nullptr)
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
	void Event::set(const char desc[]) {
		if (desc==nullptr || desc[0] == '\0')
		{
			setEmpt();
		}
		else {
			int leng = strlen(desc) + 1;
			sdds::Event::i_desc = new char[leng];
			strcpy(sdds::Event::i_desc, desc);
			calcT();
			len++;
		}
	}
	void Event::calcT() {
		t_time = g_sysClock;
		t_time_h = t_time / 3600;
		t_time_m = (t_time % 3600) / 60;
		t_time_s = t_time % 60;
	}
	void Event::setEmpt() {
		t_time = 0;
	}

	Event::Event(const Event& src) {
		if (src.len != 0) {
			i_desc = new char[src.len];
			for (size_t i = 0; i < len; i++) {
				i_desc[i] = src.i_desc[i];
			}
			len = src.len;
		}
	}

	Event& Event::operator=(const Event& src) {
		if (this != &src) {
			len = src.len;
			i_desc = src.i_desc;
			

		}
		return *this;

	}

	Event::Event(Event&& src) {
		if (src.len != 0) {
			i_desc = src.i_desc;
			len = src.len;
		}
	}
	Event::~Event() {
		len = 0;
		//delete[] i_desc; i constantly get an error for deallocation
		i_desc = nullptr;
	}
}