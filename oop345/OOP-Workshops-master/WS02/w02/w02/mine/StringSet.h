// Workshop 2
// StringSet.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Jan 30th, 2021
#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

namespace sdds {
	class StringSet {
		std::string* input{};
		int numOfIn{};
	public:
		StringSet();
		StringSet(char* i_file);
		size_t size();
		std::string operator[](size_t index);
	};

}

#endif