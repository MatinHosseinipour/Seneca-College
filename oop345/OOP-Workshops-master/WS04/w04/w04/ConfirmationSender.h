// Workshop 4
// ConfirmationSender.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 14th, 2021


#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include <iostream>
#include "Reservation.h"

namespace sdds{
    class ConfirmationSender{
        Reservation** res;
        int count;
        public:
            ConfirmationSender();
            ConfirmationSender(ConfirmationSender& src);
            ConfirmationSender& operator=(const ConfirmationSender& src);
            ConfirmationSender(ConfirmationSender&& src);
            ConfirmationSender& operator+=(const Reservation& reserve);
            ConfirmationSender& operator-=(const Reservation& reserve);
            ~ConfirmationSender();
            size_t size() const;
            friend std::ostream& operator<<(std::ostream& os, ConfirmationSender& src);

    };
}


#endif