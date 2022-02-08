// Workshop 6
// Autoshop.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//March 13th, 2021
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <string>
#include <vector>
#include<list>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;

	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto i : m_vehicles)
			{
				if (test(i))
					vehicles.push_back(i);
			}
		}
	};
}

#endif