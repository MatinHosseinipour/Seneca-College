// Workshop 6
// Racecar.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//March 13th, 2021
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include <string>
#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster{};

	public:
		Racecar();
		Racecar(std::istream& in);
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif