// Workshop 6
// Car.cpp
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
#include "Car.h"
using namespace std;
using namespace sdds;

Car::Car() {
	c_maker = "";
	c_condition = "";
	c_topSpeed = 0;
}
Car::Car(std::istream& in){
	string input;
	getline(in, input);
	input = doubleCheck(input);
	input = spaceRemover(input);
	int i = 0;
	//TAG,MAKER,CONDITION,TOP_SPEED
	//Tag is already removed before coming here
	i = input.find(',');
	//if (input.substr(0, i) == "C" || input.substr(0, i) == "c") 
	{
		//Maker
		c_maker = input.substr(0, i);
		input.erase(0, i + 1);
		input = spaceRemover(input);
		i = input.find(',');
		//condition
		c_condition = input.substr(0, i);
		if (c_condition == "n" || c_condition == "" )
		{
			c_condition = "new";
		}
		else if (c_condition == "u")
		{
			c_condition = "used";
		}
		else if (c_condition == "b")
		{
			c_condition = "broken";
		}
		else {
			throw "Invalid record!";
		}
		input.erase(0, i + 1);
		input = spaceRemover(input);
		//Top Speed

		i = input.find(',');
		if (i == -1)
		{
			try
			{
				c_topSpeed = stod(input);
			}
			catch (exception & e)
			{
				c_topSpeed = 0.0;
				throw "Invalid record!";
			}
			
		}
		else {
			try
			{
				c_topSpeed = stod(input.substr(0, i));
			}
			catch (exception & e)
			{
				c_topSpeed = 0.0;
				throw "Invalid record!";
			}
			input.erase(0, i + 1);
			c_booster = stod(input);
			c_topSpeed += c_topSpeed * c_booster;
		}
		
	}
}
std::string sdds::Car::condition() const
{
	/*string ret;
	if (c_condition == "n")
	{
		ret = "new";
	}
	else if (c_condition == "u") {
		ret = "used";
	}
	else {
		ret = "broken";
	}*/
	return c_condition;
}
double sdds::Car::topSpeed() const
{
	return c_topSpeed;
}
void sdds::Car::display(std::ostream& os) const
{
	//| MAKER | CONDITION | TOP_SPEED |
	os << "| ";
	os << setw(10) << right << c_maker << " | ";
	os << setw(6) << left << condition() << " | ";
	os << setw(6) << fixed << setprecision(2) << c_topSpeed << " |";
}
string Car::spaceRemover(string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[0] == ' ')
		{
			input.erase(0, 1);
		}
	}
	return input;
}
string Car::doubleCheck(string input)
{
	std::regex pattern(" ,");
	for (size_t i = 0; i < input.length(); i++) {
		input = std::regex_replace(input, pattern, ",");
	}
	return input;
}
double Car::booster() const
{
	return c_booster;
}