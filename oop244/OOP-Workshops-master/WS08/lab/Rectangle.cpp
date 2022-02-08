#include "Rectangle.h"
#include <cstring>
using namespace std;
namespace sdds {
	Rectangle::Rectangle() {
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* i_label, int i_width, int i_height) : LblShape(i_label) {
		int check = strlen(label() + 2);
		if (i_height>= 3 && i_width >= check)
		{
			m_width = i_width;
			m_height = i_height;
		}
		else {
			m_width = -1;
			m_height = -1;
		}
		
	}
	void Rectangle::getSpecs(istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.get();
		istr >> m_height;
		istr.ignore(256, '\n');
	}
	void Rectangle::draw(ostream& ostr) const {
		if (m_width > 0 && m_height > 0)
		{
			int i;
			for ( i = 0; i < m_height; i++) {
				if (i == 0 || m_height - i == 1) {
					ostr << "+";
					ostr.width(m_width - 1);
					ostr.fill('-');
					ostr << "+";
					if (m_height - i != 1) {
						ostr << endl;
					}
				}
				else if (i == 1) {
					ostr << "|";
					ostr.setf(ios::left);
					ostr.width(m_width - 2);
					ostr.fill(' ');
					ostr << label() << "|" << endl;
					ostr.unsetf(ios::left);


				}
				else {
					ostr << "|";
					ostr.width(m_width - 1);
					ostr << "|" << endl;
				}
			}
		}
	}
}