#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
namespace sdds {
   class Rectangle : public LblShape {
       int m_width;
       int m_height;
   public:
       Rectangle();
       Rectangle(const char* i_label, int i_width, int i_height);
       ~Rectangle() = default;
       void getSpecs(istream& istr);
       void draw(ostream& ostr) const;
   };
}
#endif