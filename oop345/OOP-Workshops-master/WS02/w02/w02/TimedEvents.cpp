// Workshop 2
// TimedEvents.cpp
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Jan 30th, 2021
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "TimedEvents.h"
#include "TimedEvents.h"
using namespace std;

namespace sdds {
	TimedEvents::TimedEvents() {
		numOfRec = 0;
	}

	TimedEvents::~TimedEvents() {

	}

	void TimedEvents::startClock() {
		startT = chrono::steady_clock::now();
	}
	void TimedEvents::stopClock() {
		stopT = chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const std::string &i_title) {
		/*events[numOfRec]->eventName = new char[strlen(i_title) + 1];
		strcpy(events[numOfRec]->eventName, i_title);
		events[numOfRec]->timeUnit = new char[12];
		strcpy(events[numOfRec]->timeUnit, "nanoseconds");*/
		events[numOfRec].eventName = i_title;
		events[numOfRec].timeUnit = "nanoseconds";
		events[numOfRec].durationT = chrono::duration_cast<chrono::nanoseconds>(stopT - startT);
		numOfRec++;
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& i_events) {
		os << "--------------------------\nExecution Times:\n--------------------------" << endl;
		for (int i = 0; i < i_events.numOfRec; i++) {
			os << setw(21) << left << i_events.events[i].eventName
				<< setw(13) << right << i_events.events[i].durationT.count()
				<< " " << i_events.events[i].timeUnit << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}
}