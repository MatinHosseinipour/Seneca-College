// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Cornel - 2020/01/08
// Chris - 2021/01/14

#include <iostream>
#include <fstream>
#include "event.h"
#include "event.h"


int main(int argc, char* argv[]) {
	std::cout << "Command Line:\n";
	for (int i = 0; i < argc; i++)
	{
		std::cout << i + 1 << ": " << argv[i] << std::endl;
	}
	std::cout << std::endl;



	sdds::Event archive[10];
	size_t idxArchive = 0;

	sdds::Event currentEvent;

	const size_t secInDay = 60u * 60u * 24u;// day has 86400 seconds

	for (auto day = 1; day < argc; ++day)
	{

		std::cout << "--------------------\n";
		std::cout << "    Day " << day << '\n';
		std::cout << "--------------------\n";
		std::ifstream in(argv[day]);
		char opcode = '\0';
		size_t time = secInDay + 1;
		in >> opcode >> time;

		for (::g_sysClock = 0u; ::g_sysClock < secInDay; ++::g_sysClock)
		{
			while (time == ::g_sysClock)
			{
				in.ignore();
				in >> opcode;

				if (in.fail())
					break;

				switch (opcode)
				{
				case 'T': 
					in >> time;
					break;
				case 'S': 
					char buffer[1024];
					in.get(buffer, 1024, ',');
					currentEvent.set(buffer);
					break;
				case 'E': 
					currentEvent.set();
					break;
				case 'P': 
					currentEvent.display();
					break;
				case 'A': 
					sdds::Event copy(currentEvent);
					archive[idxArchive++] = copy;
					break;
				}
			}
		}
	}

	std::cout << "--------------------\n";
	std::cout << "    Archive\n";
	std::cout << "--------------------\n";
	for (auto i = 0u; i < idxArchive; ++i)
		archive[i].display();
	std::cout << "--------------------\n";
}
