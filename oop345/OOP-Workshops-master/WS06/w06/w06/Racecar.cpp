// Workshop 6
// Racecar.cpp
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//March 13th, 2021
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <regex>
#include "Racecar.h"
#include "Car.h"
using namespace std;
using namespace sdds;

sdds::Racecar::Racecar()
{
	m_booster = 0;
}

sdds::Racecar::Racecar(std::istream &in) : Car(in)
{
	//TAG,MAKER,CONDITION,TOP_SPEED,BOOSTER
	m_booster = Car::booster();

}
void Racecar::display(std::ostream& out) const
{
    Car::display(out);
    cout << "*";
}
double Racecar::topSpeed() const
{
    return Car::topSpeed();
}
