// Workshop 5
// Book
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 21st, 2021
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <iomanip>
#include "SpellChecker.h"
namespace sdds {
	class Book {
		std::string b_author;
		std::string b_title;
		std::string b_country;
		size_t b_year;
		double b_price;
		std::string b_description;
		std::string spaceRemover(std::string input);
		std::string doubleCheck(std::string input);
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& i_Book);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(b_description);
		}
	};
}
#endif