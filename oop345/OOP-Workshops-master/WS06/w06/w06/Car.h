// Workshop 6
// Car.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//March 13th, 2021
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string c_maker{};
		std::string c_condition{};
		double c_topSpeed{};
		double c_booster{};

	public:
		Car();
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		double booster() const;
		void display(std::ostream& out) const;
		std::string spaceRemover(std::string input);
		std::string doubleCheck(std::string input);
		~Car() {};
	};
}

#endif