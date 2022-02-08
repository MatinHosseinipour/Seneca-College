// Workshop 5
// SpellChecker
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 21st, 2021
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <iomanip>
namespace sdds {
	class SpellChecker {
		std::string m_badWords[6]{};
		std::string m_goodWords[6]{};
		size_t countReplace[6]{};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& os) const;
	};

}

#endif