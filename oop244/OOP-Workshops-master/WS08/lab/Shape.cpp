#include "Shape.h"
namespace sdds {
	Shape::Shape() {

	}
	Shape::~Shape() {

	}
    ostream& operator<<(ostream& ostr, const Shape& i_Shape) {
        i_Shape.draw(ostr);
        return ostr;
    }
    istream& operator>>(istream& istr, Shape& i_Shape) {
        i_Shape.getSpecs(istr);
        return istr;
    }
}