// Workshop 3
// SetSummable.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 7th, 2021
#ifndef SDDS_SET_SUMMABLE_H
#define SDDS_SET_SUMMABLE_H
#define _CRT_SECURE_NO_WARNINGS
#include "Set.h"
#include <iostream>
namespace sdds {
	template<unsigned int N, typename T>
	class SetSummable : public Set<N,T> {
	public:

		T accumulate(const std::string& filter) const {
			T object(filter);
			for (size_t i = 0; i < this->size(); i++)
			{
				if (object.isCompatibleWith(this->get(i)))
				{
					object += this->get(i);
				}
			}
			return object;
		}
	};
}
#endif