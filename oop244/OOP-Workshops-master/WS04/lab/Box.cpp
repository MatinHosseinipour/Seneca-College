// Workshop 3: DIY
// Date: 10/11/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Box.h"
using namespace std;
namespace sdds
{
	void Box::setName(const char* Cstr)
	{
		if (Cstr != nullptr)
		{
			if (m_contentName != nullptr)
			{
				delete[] m_contentName;
			}
			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(m_contentName, Cstr);
		}

	}
	void Box::setUnusable()
	{
		if (m_contentName != nullptr)
			delete[] m_contentName;
		m_contentName = nullptr;
		 m_width = -1;           // The dimensions of the box in Inches
		 m_height = -1;
		 m_length = -1;
		 m_contentVolume = -1;
	}
	bool  Box::isUnusable()const
	{
		if (m_width == -1)
			return true;
		return false;

	}
	bool Box::hasContent()const
	{
		//  int quantity()const;
		//This function return the content volume member variable.
		if (quantity() > 0)
			return true;
		return false;
	}

	Box::Box()
	{
		m_contentName = nullptr;

		m_width = 12;
		m_height = 12;
		m_length = 12;
		m_contentVolume = 0;
	}
	Box::Box(int sideLength, const char* contentName )
	{
		m_contentName = nullptr;
		if (!(sideLength >= 5 && sideLength <= 36))
		{
			setUnusable();
		}
		else
		{
			m_width = sideLength;
			m_height = sideLength;
			m_length = sideLength;
			m_contentVolume = 0;
			setName(contentName);
		}


	}
	Box::Box(int width, int height, int length, const char* contentName )
	{
		m_contentName = nullptr;
		if ((!(width >= 5 && width <= 36)) || (!(height >= 5 && height <= 36)) || (!(length >= 5 && length <= 36)))
		{
			setUnusable();
		}
		else
		{
			m_width = width;
			m_height = height;
			m_length = length;
			m_contentVolume = 0;
			setName(contentName);
		}

	}
	Box::~Box()
	{
		delete[] m_contentName;
	}
	int Box::capacity()const
	{
		return m_width * m_height * m_length;
	}
	int Box::quantity()const
	{
		return m_contentVolume;
	}
	Box& Box::setContent(const char* contentName)
	{
		if (hasContent())
		{
			setUnusable();
		}
		else
		{
			setName(contentName);
		}
		return *this;

	}
	std::ostream& Box::display()const
	{
		if (isUnusable())
		{
			cout << "Unusable box, discard the content, and recycle.";
			return cout;
		}
		if (m_contentName == nullptr)
		{
			cout.width(30);
			cout.fill('.');
			cout << std::left<<"Empty box";
		}
		else
		{
			cout.width(30);
			cout.fill('.');
			cout << std::left << m_contentName;
		}

		cout << "  ";
		cout.width(2);
		cout.fill('0');
		cout << std::right;
		cout << m_width;
		cout << 'x' ;
		cout.width(2);
		cout << std::right;
		cout.fill('0');
		cout << m_height;
		cout << 'x';
		cout.width(2);
		cout << std::right;
		cout.fill('0');
		cout << m_length;		
		//printf("%2dx", &m_width);
		//printf("%02dx", &m_height);
		//printf("%02d", &m_length);
		cout << ' ';
		
		int result = quantity();	
		cout.width(7);
		cout << std::right;
		cout.fill(' ');
		
		cout << result;
		
		cout << '/';
		cout << capacity();
		cout << " C.I.";
		return cout;
	}
	Box& Box::add(int quantity) 
	{
		if (quantity > 0 && m_contentVolume + quantity <= capacity())
		{
			m_contentVolume += quantity;
			return *this;
		}
		setUnusable();
		return *this;
	}
	Box& Box::add(Box& B)
	{
		if (m_contentName == nullptr || quantity() == 0) {
			setContent(B.m_contentName);
		}
		if (strcmp(m_contentName, B.m_contentName) == 0) {
			if (quantity() + B.quantity() <= capacity()) {
				add(B.quantity());
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
				m_contentVolume = capacity();
			}
		}
		else {
			if (quantity() + B.quantity() <= capacity()) {
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
			}
			setUnusable();
		}
		return *this;
	}


}