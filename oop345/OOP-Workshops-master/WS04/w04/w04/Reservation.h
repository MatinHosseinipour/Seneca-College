// Workshop 4
// Reservation.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 14th, 2021

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H


#include<iostream>
#include<string>

namespace sdds
{
	class Reservation
	{
		std::string reservationID;
		std::string reservationName;
		std::string email;
		short int noOfPeople;
		short int day;
		short int hour;

		public:
			Reservation();
			Reservation(const std::string& res);
			friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};
}
#endif
