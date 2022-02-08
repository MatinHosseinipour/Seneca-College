#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Subject.h"

using namespace std;
namespace sdds {
	char Subject::grade() const {
		if (m_mark < 50) {
			return 'F';
		}
		else if (m_mark < 60) {
			return 'D';
		}
		else if (m_mark < 70) {
			return 'C';
		}
		else if (m_mark < 80) {
			return 'B';
		}
		else if (m_mark >= 80) {
			return 'A';
		}
		return '0';
	}
	void Subject::setEmpty() {
		m_mark = -1;
		m_code[0] = '\0';
	}
	void Subject::set(const char* code, int mark) {
		if (mark < 0 || mark > 100) {
			setEmpty();
		}
		else {
			strcpy(m_code, code);
			m_mark = mark;

		}
	}
	float Subject::scale4()const {
		if (m_mark < 50) {
			return 0.0;
		}
		else if (m_mark < 60) {
			return 1.0;
		}
		else if (m_mark < 70) {
			return 2.0;
		}
		else if (m_mark < 80) {
			return 3.0;
		}
		else if (m_mark >= 80) {
			return 4.0;
		}
		return 0;
	}
	bool Subject::isValid()const {
		if (m_mark < 0 || m_mark > 100) {
			return false;
		}
		return true;
	}
	void Subject::display()const {
		if (isValid()) {
			printf("%-15s", m_code);
			printf("%3d", m_mark);
			printf("%10c", grade());
			printf("\n");
		}
	}
};