/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author	John Doe
Revision History
Matin Hosseini Pour
151267192
smmhosseini-pour@myseneca.ca
-----------------------------------------------------------
Date      Reason
2020/12/3 Preliminary release
2020/12/3  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "PreTriage.h"
#include "Patient.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	PreTriage::PreTriage(const char* dataFilename): m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		m_averCovidWait = 15;
		m_averTriageWait = 5;
		load();
	}
	PreTriage::~PreTriage() {
		ofstream output(m_dataFilename);
		cout << "Saving Average Wait Times," << endl
			<< "   COVID Test: ";
		m_averCovidWait.write(cout);
		cout << endl << "   Triage: ";
		m_averTriageWait.write(cout);
		cout << endl;
		m_averCovidWait.write(output);
		output << ",";
		m_averTriageWait.write(output);
		output << endl;
		int i, x = 1;
		cout << "Saving m_lineup..." << endl;
		for (i = 0; i < m_lineupSize; i++)
		{
				cout << x++ << "- ";
				m_lineup[i]->csvWrite(cout);
				m_lineup[i]->csvWrite(output);
				cout << endl;
				output << endl;
		}
		delete[] m_dataFilename;
		m_dataFilename = nullptr;
		for (i = 0; i < m_lineupSize; i++)
		{
			delete m_lineup[i];
		}
		cout << "done!" << endl;
	}
	void PreTriage::run(void)
	{
		int menu = -1;
		do
		{
			menu = m_appMenu.display();
			if (menu == 1)
			{
				reg();
			}
			else if (menu == 2)
			{
				admit();
			}
		} while (menu != 0);

	}
	void PreTriage::reg()
	{
		if (m_lineupSize == 100)
		{
			cout << "Line up full!" << endl;
		}
		else {
			int menu = m_pMenu.display();
			if (menu != 0)
			{
				if (menu == 1)
				{
					m_lineup[m_lineupSize] = new CovidPatient;
				}
				else if (menu == 2)
				{
					m_lineup[m_lineupSize] = new TriagePatient;
				}
				m_lineup[m_lineupSize]->setArrivalTime();
				cout << "Please enter patient information: " << endl;
				m_lineup[m_lineupSize]->fileIO(false);
				cin >> *m_lineup[m_lineupSize];
				cout << endl << "******************************************" << endl;
				cout << *m_lineup[m_lineupSize];
				cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]);
				cout << endl << "******************************************" << endl << endl;
				m_lineupSize++;
			}
		}
	}
	void PreTriage::admit()
	{
		char tp = 'x';
		int menu = m_pMenu.display();
		if (menu != 0)
		{
			if (menu == 1)
			{
				tp = 'C';
			}
			else if (menu == 2)
			{
				tp = 'T';
			}
			int index = indexOfFirstInLine(tp);
			if (index != -1)
			{
				cout << endl << "******************************************" << endl;
				m_lineup[index]->fileIO(false);
				cout << "Calling for ";
				m_lineup[index]->write(cout);
				cout << "******************************************" << endl << endl;
				setAverageWaitTime(*m_lineup[index]);
				removePatientFromLineup(index);
			}
		}
	}
	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		int i, count = 0;
		char tp = p.type();
		for (i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == tp)
			{
				count++;
			}
		}
		int total;
		if (tp == 'C')
		{
			total = m_averCovidWait * count;
		}
		else {
			total = m_averTriageWait * count;
		}
		Time t(total);
		return t;
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		/*
		CT: Current Time
		PTT: Patient's Ticket Time
		AWT: Average Wait Time (Covid or Triage)
		PTN: Patient's Ticket Number
		AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN
		*/
		char tp = p.type();
		int CT = getTime();
		Time PTT_tim(p);
		int PTT = PTT_tim;
		int AWT;
		if (tp == 'C')
		{
			AWT = m_averCovidWait;
		}
		else {
			AWT = m_averTriageWait;
		}
		int PTN = p.number();

		AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;

		if (tp == 'C')
		{
			m_averCovidWait = AWT;
		}
		else {
			m_averTriageWait = AWT;
		}
	}
	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}
	void PreTriage::load()
	{
		cout << "Loading data..." << endl;
		ifstream input(m_dataFilename);
		m_averCovidWait.read(input);
		input.ignore(2000, ',');
		m_averTriageWait.read(input);
		input.ignore(2000, '\n');
		int i;
		char type = 'x';
		Patient* p = nullptr;
		for (i = 0; i < maxNoOfPatients; i++)
		{
			if (input.get(type))
			{
				input.ignore(2000, ',');
					if (type == 'C')
					{
						p = new CovidPatient;
						p->fileIO(true);
						input >> *p;
						p->fileIO(false);
						m_lineup[i] = p;
						m_lineupSize++;
						p = nullptr;
					}
					else if (type == 'T') {
						p = new TriagePatient;
						p->fileIO(true);
						input >> *p;
						p->fileIO(false);
						m_lineup[i] = p;
						m_lineupSize++;
						p = nullptr;
					}
					input.ignore(2000, '\n');
			}
			else {
				i = 100;
			}
		}
		char test = '\0';
		input.get(test);
		if (m_lineupSize == 0)
		{
			cout << "No data or bad data file!" << endl;
		}
		else if (test != '\0')
		{
			cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
			cout << m_lineupSize << " Records imported..." << endl;
		}
		else {
			cout << m_lineupSize << " Records imported..." << endl;
		}
		cout << endl;
	}
	int PreTriage::indexOfFirstInLine(char type) const
	{
		int index = -1;
		int i = 0;
		do {
			if (m_lineup[i]->type() == type)
			{
				index = i;
			}
			i++;
		} while (i < m_lineupSize && index == -1);
		return index;
	}
}