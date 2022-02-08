// Workshop 4: DIY
// Date: 10/18/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
using namespace std;
#include "NameTag.h"
namespace sdds
{
	NameTag::NameTag(){
		m_name = nullptr;
		m_ext = 0;
	}
	NameTag::NameTag(const char name[]){
		int length = strlen(name) + 1;

		m_name = new char[length];
		strcpy(m_name, name);
		if (length > 40)
		{
			m_name[40] = '\0';
		}
		m_ext = 0;
	}
	NameTag::NameTag(const char name[], int ext){
		if (name == nullptr) {
			m_name = nullptr;
		}
		else if (!(ext >= 10000 && ext<=99999))
		{
			m_name = nullptr;
		}
		else {
			int length = strlen(name) + 1;
			m_name = new char[length];
			strcpy(m_name, name);
			if (length > 40)
			{
				m_name[40] = '\0';
			}
		}
		m_ext = ext;
	}
	NameTag::~NameTag(){
		delete[] m_name;
	}
	void NameTag::print()const{
		std::streamsize length = 20;
		
		if (m_name == nullptr) {
			cout << "EMPTY NAMETAG!"<<endl;
		}
		else {
			if (strlen(m_name) >= 20) {
				length = 40;
			}
			cout.width(length +4);
			cout.fill('*');
			cout << '*' << endl;
			
			cout << '*';
			cout.fill(' ');
			cout.width(length +3);
			cout << '*' << endl;
		
			cout << "* ";
			cout.width(length);
			cout << left<<m_name;
			cout << " *"<<endl;

			cout << '*';
			cout.fill(' ');
			cout.width(length + 3);
			cout << right<<'*' << endl;


			cout << "* ";
			cout << left<<"Extension: ";
			cout.width(length - 11);
			if (m_ext == 0) {
				cout << "N/A";
			}else{
				cout << m_ext;
			}
			
			cout << " *"<<endl;


			cout << '*';
			cout.fill(' ');
			cout.width(length + 3);
			cout << right<<'*' << endl;

			cout.width(length + 4);
			cout.fill('*');
			cout << '*' << endl;
		}
	}
	void NameTag::flushkeys()
	{
		while (cin.get() != '\n');
			
	}
	NameTag& NameTag::read()
	{
		int ext;
		char yno;
		char name[40 + 1];
		cout << "Please enter the name: ";
		cin.get(name, 41, '\n');
		flushkeys();
		if (m_name == nullptr)
		{
			m_name = new char[41];
		}
		strcpy(m_name, name);
		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
		cin >> yno;
		flushkeys();
		if (yno == 'y')
		{
			cout << "Please enter a 5 digit phone extension: ";
			cin >> ext;
			flushkeys();
			while (!(ext >= 10000 && ext <= 99999))
			{
				cout << "Invalid value [10000<=value<=99999]: ";
				cin >> ext;
				flushkeys();
			}
			m_ext = ext;
		}
		else
		{
			m_ext = 0;
		}
		return *this;
	}
}