#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
namespace sdds {
   class Line : public LblShape{
       int m_length;
   public:
       Line();
       Line(const char* i_label, int i_length);
       ~Line() = default;
       void getSpecs(istream& istr);
       void draw(ostream& ostr) const;
   };
}
#endif // !SDDS_LINE_H

