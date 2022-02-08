
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
namespace sdds {
   class LblShape : public Shape {
       char* m_label = nullptr;
   protected:
       const char* label() const;
   public:
       LblShape();
       LblShape(const char* i_label);
       void setLabel(const char* i_label);
       LblShape(const LblShape &i_lshape) = delete;
       LblShape& operator=(const LblShape& i_lshape) = delete;
       void getSpecs(istream& istr);
       ~LblShape();
   };
}
#endif // !SDDS_LBLSHAPE_H


