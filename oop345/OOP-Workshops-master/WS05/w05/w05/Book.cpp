// Workshop 5
// Book
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 21st, 2021
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstring>
#include <regex>
#include "Book.h"
using namespace std;
namespace sdds {

	Book::Book(){ 
		b_author = "";
		b_title = "";
		b_country = "";
		b_year = 0;
		b_price = 0.0;
		b_description = "";
	}
	const string& Book::title() const {
		return this->b_title;
	}
	const string& Book::country() const {
		return this->b_country;
	}
	const size_t& Book::year() const {
		return this->b_year;
	}
	double& Book::price() {
		return this->b_price;
	}
	Book::Book(const string& strBook) {
		string i_Book = strBook;
		//remove first and last spaces
		//i_Book.erase(find(i_Book.begin(), i_Book.end(), ' '));
		i_Book = doubleCheck(i_Book);
		b_author = "";
		b_title = "";
		b_country = "";
		b_year = 0;
		b_price = 0.0;
		b_description = "";
		size_t i = 0;
		//AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
		i_Book = spaceRemover(i_Book);
		//author
		i = i_Book.find(',');
		b_author = i_Book.substr(0, i);
		i_Book.erase(0, i + 1);
		i_Book = spaceRemover(i_Book);
		//title
		i = i_Book.find(',');
		b_title = i_Book.substr(0, i);
		i_Book.erase(0, i + 1);
		i_Book = spaceRemover(i_Book);
		//country
		i = i_Book.find(',');
		b_country = i_Book.substr(0, i);
		i_Book.erase(0, i + 1);
		i_Book = spaceRemover(i_Book);
		//price
		i = i_Book.find(',');
		b_price = stod(i_Book.substr(0, i));
		i_Book.erase(0, i + 1);
		i_Book = spaceRemover(i_Book);
		//year
		i = i_Book.find(',');
		b_year = stoi(i_Book.substr(0, i));
		i_Book.erase(0, i + 1);
		i_Book = spaceRemover(i_Book);
		//description
		b_description = i_Book;
	}
	ostream& operator<<(ostream& os, const Book& i_Book) {
		
		/*
		os.width(20);
		os << i_Book.author << " | ";
		os.width(22); 
		os << i_Book.title << " | ";
		os.width(5);
		os << i_Book.country << " | ";
		os.width(4);
		os << i_Book.year << " | ";
		os.width(6);
		os.fixed;
		os.precision(2);
		os << i_Book.price << " | ";
		os << i_Book.description << endl;
		*/
		os << setw(20) << i_Book.b_author << " | ";
		os << setw(22) << i_Book.b_title << " | ";
		os << setw(5) << i_Book.b_country << " | ";
		os << setw(4) << i_Book.b_year << " | ";
		os << setw(6) << fixed << setprecision(2) << i_Book.b_price << " | ";
		os << i_Book.b_description << endl;
		
		return os;
	}
	string Book::spaceRemover(string input)
	{
		/*
			std::regex pattern(", ");
			for(size_t i = 0; i < input.length(); i++){
				input = std::regex_replace(input, pattern, ",");
			}
		*/
		for (size_t i = 0; i < input.length(); i++)
		{
			if (input[0] == ' ')
			{
				input.erase(0, 1);
			}
		}
		return input;
	}
	string Book::doubleCheck(string input)
	{
		std::regex pattern(" ,");
		for(size_t i = 0; i < input.length(); i++){
			input = std::regex_replace(input, pattern, ",");
		}
		return input;
	}
}