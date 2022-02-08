// Workshop 5
// Movie
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 21st, 2021
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <iomanip>
#include "SpellChecker.h"
namespace sdds {
	class Movie {
		std::string m_title{};
		std::string m_description{};
		size_t m_year{};
		std::string spaceRemover(std::string input);
		std::string doubleCheck(std::string input);
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}
		friend std::ostream& operator<<(std::ostream& os, const Movie& i_Movie);
	};
}

#endif