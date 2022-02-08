// Workshop 3: DIY
// Date: 10/11/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#ifndef SDDS_BARCHART_H_
#define SDDS_BARCHART_H_
#include "Bar.h"

namespace sdds {
    class BarChart {
        char* chart_title;
        Bar* bar;
        char fill_c;
        int rows = -1;
        int added = -1;

    public:
        bool ifvalid() const;
        void init(const char* title, int noOfSampels, char fill);
        void add(const char* bar_title, int value);
        void draw()const;
        void deallocate();
        void printdash(int length) const;

	};
};

#endif