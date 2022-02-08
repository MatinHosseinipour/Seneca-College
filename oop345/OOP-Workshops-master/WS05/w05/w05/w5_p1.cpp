// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Book.h"
#include "Book.h"
using namespace std;
using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	if (argc == 2) {
		std::ifstream file(argv[1]);
		std::string strBook;
		size_t loaded = 0;
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			exit(AppErrors::CannotOpenFile);
		}
		do
		{
			getline(file, strBook);
			if (file)
			{
				if (strBook[0] != '#') {
					library[loaded] = strBook;
					loaded++;
				}

			}
		} while (file);
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object

	auto fixPrice = [usdToCadRate, gbpToCadRate](Book& i_Book) {
		if (i_Book.getCountry() == "US")
		{
			i_Book.getPrice() = i_Book.getPrice() * usdToCadRate;
		}
		else if(i_Book.getCountry() == "UK" && i_Book.getYear() >= 1990 && i_Book.getYear() <= 1999)
		{
			i_Book.getPrice() = i_Book.getPrice() * gbpToCadRate;
		}
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	// TODO: iterate over the library and print each book to the screen
	for (size_t i = 0; i < 7; i++)
	{
		cout << library[i];
	}


	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.

	for (size_t i = 0; i < 7; i++)
	{
		fixPrice(library[i]);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	// TODO: iterate over the library and print each book to the screen

	for (size_t i = 0; i < 7; i++)
	{
		cout << library[i];
	}

	std::cout << "-----------------------------------------\n";

	return 0;
}
