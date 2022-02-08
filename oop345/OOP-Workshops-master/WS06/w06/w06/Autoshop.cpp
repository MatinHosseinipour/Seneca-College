// Workshop 6
// Autoshop.cpp
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//March 13th, 2021
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <algorithm> 
#include "Autoshop.h"
#include "Vehicle.h"
using namespace std;
using namespace sdds;

Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
{
	m_vehicles.push_back(theVehicle);
	return *this;
}

void sdds::Autoshop::display(std::ostream& os) const
{
	/*
	--------------------------------
	| Cars in the autoshop!        |
	--------------------------------
	VEHICLE
	VEHICLE
	...
	--------------------------------
	*/
	os << "--------------------------------" << endl;
	os << "| Cars in the autoshop!        |" << endl;
	os << "--------------------------------" << endl;

	for (auto iter = m_vehicles.begin(); iter != m_vehicles.end(); iter++)
	{
		(*iter)->display(os);
		os << endl;
	}
	os << "--------------------------------" << endl;
}
Autoshop::~Autoshop()
{
	for (auto i : m_vehicles)
	{
		delete i;
	}
}