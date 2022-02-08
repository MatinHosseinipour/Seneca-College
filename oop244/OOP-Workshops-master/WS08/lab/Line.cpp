#include "Line.h"
using namespace std;
namespace sdds {
	Line::Line() {
		m_length = 0;
	}
	Line::Line(const char* i_label, int i_length): LblShape(i_label) {
		m_length = i_length;
	}
	void Line::getSpecs(istream& istr) {
		LblShape::getSpecs(istr);
		int i_length = 0;
		istr >> i_length;
		istr.ignore(256,'\n');
		m_length = i_length;
	}
	void Line::draw(ostream& ostr) const {
		if (label() && m_length > 0)
		{
			ostr << label() << endl;
			ostr.width(m_length);
			ostr.fill('=');
			ostr << "=";
		}
	}

}
