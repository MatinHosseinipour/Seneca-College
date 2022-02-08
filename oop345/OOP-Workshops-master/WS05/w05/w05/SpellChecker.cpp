// Workshop 5
// SpellChecker
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 21st, 2021
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstring>
#include <regex>
#include "SpellChecker.h"

using namespace std;
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		std::string strWords;
		size_t loaded = 0;
		size_t i;
		if (!file)
		{
			throw "Bad file name!";
		}
		else {
			do
			{
				getline(file, strWords);
				if (file)
				{
					i = strWords.find(' ');
					m_badWords[loaded] = strWords.substr(0, i);
					strWords.erase(0, i);
					while (strWords[0] == ' ') {
						strWords.erase(0, 1);
					}
					m_goodWords[loaded] = strWords;
					loaded++;
				}
			} while (file);
		}
	}
	void SpellChecker::operator()(std::string& text){
		size_t wordNum = 0;
		int loc = -1;
		while (wordNum != 6) {
			while ( (int)text.find(m_badWords[wordNum]) != -1) {
				loc = text.find(m_badWords[wordNum]);
				text.replace(loc, m_badWords[wordNum].length(), m_goodWords[wordNum]);
				countReplace[wordNum]++;
				loc = -1;
			}
			wordNum++;
		}
	}
	void SpellChecker::showStatistics(std::ostream& os) const {
		size_t wordNum = 0;
		os << "Spellchecker Statistics" << endl;
		while (wordNum != 6) {
			os << setw(15) << right << m_badWords[wordNum] << ": " << countReplace[wordNum] << " replacements" << endl;
			wordNum++;
		}
	}
}