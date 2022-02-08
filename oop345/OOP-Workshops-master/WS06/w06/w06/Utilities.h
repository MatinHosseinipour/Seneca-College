// Workshop 6
// Utilities.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//March 13th, 2021
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}

#endif