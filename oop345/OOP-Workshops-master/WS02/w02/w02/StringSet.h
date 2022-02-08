// Workshop 2
// StringSet.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Jan 30th, 2021
#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

namespace sdds {
	class StringSet {
		std::string* input{};
		size_t numOfIn{};
	public:
		StringSet();
		~StringSet();
		StringSet(char* i_file);
		size_t size();
		std::string operator[](size_t index);
		StringSet(StringSet&&);
		StringSet(StringSet&);
		StringSet& operator=(StringSet& obj);
		StringSet& operator=(StringSet&&);
	};

}

#endif