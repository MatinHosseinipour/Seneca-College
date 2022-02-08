/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
Version 1.0
Author	John Doe
Revision History
Matin Hosseini Pour
151267192
smmhosseini-pour@myseneca.ca
-----------------------------------------------------------
Date      Reason
2020/11/19  Preliminary release
2020/11/19  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds
{
    bool debug = false;
    int getTime()
    {
        int mins = -1;
        if (debug)
        {
            Time t(0);
            cout << "Enter current time: ";
            do
            {
                cin.clear();
                cin >> t;
                if (!cin)
                {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else
                {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else
        {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    int getInt()
    {
        int value;
        bool badEntry;
        char nextChar;
        do
        {
            badEntry = false;
            cin >> value;
            if (cin.fail())
            {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(3000, '\n');
                badEntry = true;
            }
            else
            {
                nextChar = cin.get();
                if (nextChar != '\n')
                {
                    cout << "Only enter an integer, try again: ";
                    cin.ignore(3000, '\n');
                    badEntry = true;
                }
            }
        } while (badEntry);
        return value;
    }

    int getIntInRange(int min, int max)
    {
        int valid, flag = 0;

        do
        {
            valid = getInt();
            if (valid < min || valid > max)
                printf("Invalid value enterd, retry[%d <= value <= %d]: ", min, max);
            else
                flag = 1;
        } while (flag != 1);

        return valid;
    }
} // namespace sdds
