// Workshop 2
// TimedEvents.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Jan 30th, 2021
#ifndef SDDS_TIMEEVENTS_H
#define SDDS_TIMEEVENTS_H
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

namespace sdds {
	class TimedEvents {
		struct Event{
			std::string eventName{};
			std::string timeUnit{};
			/*char* eventName{};
			char* timeUnit{};*/
			/*char eventName{};
			char* timeUnit{};*/
			std::chrono::steady_clock::duration durationT{};
		};
		Event events[10];
		std::chrono::steady_clock::time_point startT{};
		std::chrono::steady_clock::time_point stopT{};
		int numOfRec{};
	public:
		TimedEvents();
		~TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const std::string &i_title);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& i_events);
	};
}

#endif