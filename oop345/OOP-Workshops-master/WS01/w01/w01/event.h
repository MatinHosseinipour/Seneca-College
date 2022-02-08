// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Cornel - 2020/01/08
// Chris - 2021/01/14


#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H
#include <cstring>
extern size_t g_sysClock;
namespace sdds {
	//const int max_d = 129;
	class Event {
		char* i_desc;
		unsigned int t_time;
		unsigned int t_time_h;
		unsigned int t_time_m;
		unsigned int t_time_s;
		void calcT();
		void setEmpt();
	public:
		Event();
		void display()const;
		void set(const char i_desc[] = nullptr);
		~Event();
	};

}

#endif