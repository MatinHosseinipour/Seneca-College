#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
using namespace std;
namespace sdds {
   class Shape {
   public:
       Shape();
       virtual void draw(ostream& ostr) const = 0;
       virtual void getSpecs(istream& istr) = 0;
       virtual ~Shape();
   };
   ostream& operator<<(ostream& ostr, const Shape& i_Shape);
   istream& operator>>(istream& istr, Shape& i_Shape);
}

#endif // !SDDS_SHAPE_H

