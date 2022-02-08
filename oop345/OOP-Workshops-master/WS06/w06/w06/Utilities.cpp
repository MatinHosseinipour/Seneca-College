// Workshop 6
// Utilities.cpp
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//March 13th, 2021
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"
using namespace std;
using namespace sdds;
Vehicle* sdds::createInstance(std::istream& in)
{
	string inputS;
	getline(in, inputS, ',');
	char input = -1;
	for (size_t i = 0; i < inputS.length(); i++)
	{
		if (inputS[i] != ' ')
		{
			input = inputS[i];
			break;
		}
	}
	if (input == 'C' || input == 'c')
	{
		Car* c = new Car(in);
		return c;
	}
	else if (input == 'R' || input == 'r') {
		Racecar* rc = new Racecar(in);
		return rc;
	}
	else if (input == -1){
		return nullptr;
	}
	else {
		getline(in, inputS);
		throw input;
	}
}
