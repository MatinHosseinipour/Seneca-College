// Workshop 3: DIY
// Date: 10/11/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#ifndef SDDS_BAR_H_
#define SDDS_BAR_H_

namespace sdds {
    class Bar {
        char title[21];
        char fill_c[2];
        int value;
        bool validity = true;
    public:
        void setEmpty();
        void set(const char coming_title[21], char coming_fill_c, int coming_value);
        bool valid()const;
        void draw()const;
    };

};

#endif