// Workshop 4
// Restaurant.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 14th, 2021

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"

namespace sdds{
    class Restaurant{
        Reservation* res;
        size_t noOfRes;

        public:
            Restaurant();
            Restaurant(const Reservation* reservations[], size_t cnt);
            Restaurant(const Restaurant& src);
            Restaurant& operator=(const Restaurant& src);
            Restaurant(Restaurant&& src);
            size_t size() const;
            ~Restaurant();

            friend std::ostream& operator<<(std::ostream& os, const Restaurant& rest);
    };
}


#endif