#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <cstring>

using namespace std;
namespace sdds {
	const char* LblShape::label() const
	{
		return m_label;
	}
	LblShape::LblShape() {

	}
	LblShape::LblShape(const char* i_label) {
		if (m_label != nullptr) {
			delete[] m_label;
			m_label = nullptr;
		}
		m_label = new char[21];
		strncpy(m_label, i_label, 20);
		m_label[20] = '\0';
	}
	void LblShape::setLabel(const char* c) {
		if (m_label != nullptr) {
			delete[] m_label;
			m_label = nullptr;
		}
		m_label = new char[21];
		strncpy(m_label, c, 20);
		m_label[20] = '\0';
	}
	void LblShape::getSpecs(istream& istr){
		char i_c[21]{};
		istr.get(i_c, 21, ',');
		setLabel(i_c);
		istr.ignore(256, ',');


	}
	LblShape::~LblShape() {
		delete m_label;
	}
}