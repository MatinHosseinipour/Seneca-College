// Workshop 3
// Set.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 7th, 2021
#ifndef SDDS_SET_H
#define SDDS_SET_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
namespace sdds {
	template< unsigned int N, typename T>
	class Set {
		 T collection[N];
		 size_t length{0};
	public:
		size_t size() const {
			return length;
		}
		const T& get(size_t idx) const {
			return collection[idx];
		}
		void operator+=(const T& item) {
			if (length < N)
			{
				//get(length++) = item;
				collection[length++] = item;
			}
		}
	};
}

#endif