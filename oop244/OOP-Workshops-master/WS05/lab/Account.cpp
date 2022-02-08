#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << "Acc#: ";
            if (~(*this))
                cout << "Not Set";
            else
                cout << " " << m_number << " ";
            cout << ", Balance: ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            // I (Fardad) removed the "return cout", this was a mistake
            // (copied and pasted by mistake)
            // and had no effect to the execution of the program.
            // As mentioned before we should have only
            // one return statement in a function.
        }
        else {
            cout << "Invalid Account";
        }
        return cout;
    }
    Account::operator bool() const {
        bool x = false;
        if (m_number != -1) {
            x = true;
        }
        return x;
    }
    Account::operator int() const {
        return m_number;
    }
    Account::operator double() const {
        return m_balance;
    }
    bool Account::operator~() const {
        return m_number == 0;
    }



    Account& Account::operator=(const int number) {
        if (m_number != -1)
        {
            if (number >= 10000 && number <= 99999)
            {
                m_number = number;
            }
            else {
                m_number = -1;
            }
        }
        return *this;
    }
    Account& Account::operator=(Account& acc) {
        if (m_number != -1 && acc.m_number != -1)
        {
            m_balance = acc.m_balance;
            acc.m_balance = 0.0;
        }
        return *this;
    }
    Account& Account::operator+=(const double deposit) {
        if (m_number != -1 && deposit >= 0)
        {
            m_balance += deposit;
        }
        return *this;
    }
    
    double Account::operator+(const Account& acc)const {
        double total = 0.0;
        if (m_number != -1 && acc.m_number != -1)
        {
            total += m_balance;
            total += acc.m_balance;
        }
        return total;
    }
    double operator+=(double& total, const Account& acc) {
        int m_number = int(acc);
        double m_balance = double(acc);
        if (m_number != -1)
        {
            total += m_balance;
        }
        return total;
    }
    bool operator==(const Account& a, const Account& b)
    {
        return false;
    }
    Account::Account(char& name, double& tanks, int numoftanks) {
        if (name && tanks && numoftanks >= 1) //if null is false
        {
            rocketName = new char[strlen(name) + 1];
            strcpy(rocketName, name);
            fuelTanks = new double[numoftanks];
            for (int i = 0; i < numoftanks; i++)
            {
                fuelTanks[i] = tanks[i];
            }
            numOfTanks = numoftanks;
        }
        else {
            rocketName = 'F';
            fuelTanks = nullptr;
            numOfTanks = -1;
        }
    }
    Account::~Account(){
        delete flowerName;
        numOfFlowers = -1;
    }
    Account& Account::operator-=(const double withdraw) {
        if (numOfTanks != -1 && withdraw >= 0.0 && withdraw <= 100.0)
        {
            for (int i = 0; i < numOfTanks; i++)
            {
                fuelTanks[i] -= withdraw;
            }
        }
        return *this;
    }