// Workshop 9 - Multi-Threading
// SecureData.cpp
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//April 3rd, 2021


#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least four threads
		//         to encrypt/decrypt the text.
		using namespace std::placeholders;
		auto f1 = std::bind(converter,_1, key, _2, Cryptor());
		int size = nbytes / 4;
		if(nbytes<4)
			size = nbytes;
		int size1 = 0;
		char *str1 = new char[size];
		char *str2 = new char[size];
		char *str3 = new char[size];
		char *str4 = new char[nbytes-3*size];
		int k = 0, k1 = 0, k2 = 0, k3 = 0;
		for (int i = 0; i < nbytes; i++)
		{
			if(i<size)
				str1[k++]= text[i];
			else if(i<2*size)
				str2[k1++] = text[i];
			else if(i<3*size)
				str3[k2++] = text[i];
			else{
				size1++;
				str4[k3++] = text[i];
			}
		}
		std::thread t1(f1, str1, size);
		std::thread t2(f1,str2,size);
		std::thread t3(f1,str3,size);
		std::thread t4(f1,str4,size1);
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		k = 0, k1 = 0, k2 = 0, k3 = 0;
		for (int i = 0; i < nbytes; i++)
		{
			if (i < size)
				text[i]=str1[k++];
			else if (i < 2 * size)
				text[i] = str2[k1++];
			else if (i < 3 * size)
				text[i] = str3[k2++];
			else
			{
				size1++;
				text[i]=str4[k3++];
			}
		}
		// converter(text, key, nbytes, Cryptor());

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			fstream input(file, std::ios::out);

			if (!input)
				throw string("\n***Failed to open file ") +
					string(file) + string(" ***\n");
			// TODO: write data into the binary file
			//         and close the file
			for (int i = 0; i < nbytes;i++)
			{
				if(text[i]=='\0')
					break;
				input << text[i];
			}
			input.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		fstream input(file, std::ios::in);

		// TODO: - allocate memory here for the file content
		delete[] text;
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg();
		text = new char[nbytes+1];

		// TODO: - read the content of the binary file
		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes] = '\0';
		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
