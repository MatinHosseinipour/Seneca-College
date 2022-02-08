// Workshop 5
// Movie
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
#include "Movie.h"
using namespace std;
namespace sdds {
	Movie::Movie() {
		m_title = "";
		m_description = "";
		m_year = 0;
	}
	const std::string& Movie::title() const {
		return this->m_title;
	}
	Movie::Movie(const std::string& strMovie) {
		m_title = "";
		m_description = "";
		m_year = 0;
		string i_movie = strMovie;
		size_t i = 0;
		//double check
		i_movie = doubleCheck(i_movie);
		//TITLE,YEAR,DESCRIPTION
		i_movie = spaceRemover(i_movie);
		//title
		i = i_movie.find(',');
		m_title = i_movie.substr(0, i);
		i_movie.erase(0, i + 1);
		i_movie = spaceRemover(i_movie);
		//year
		i = i_movie.find(',');
		m_year = stod(i_movie.substr(0, i));
		i_movie.erase(0, i + 1);
		i_movie = spaceRemover(i_movie);
		//description
		i = i_movie.find(',');
		m_description = i_movie;
	}
	string Movie::spaceRemover(string input)
	{
		for (size_t i = 0; i < input.length(); i++)
		{
			if (input[0] == ' ')
			{
				input.erase(0, 1);
			}
		}
		return input;
	}
	string Movie::doubleCheck(string input)
	{
		std::regex pattern(" ,");
		for (size_t i = 0; i < input.length(); i++) {
			input = std::regex_replace(input, pattern, ",");
		}
		return input;
	}
	ostream& operator<<(ostream& os, const Movie& i_Movie) {
		os << setw(40) << i_Movie.m_title << " | ";
		os << setw(4) << i_Movie.m_year << " | ";
		os << i_Movie.m_description << endl;
		return os;
	}
}