#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
      char rocketName[21];
      double* fuelTanks;
      int numOfTanks;
   public:
      Account();
      Account(int number, double balance);
      Account(char& name, double& tanks, int numoftanks);
      std::ostream& display()const;
      operator bool()const;
      operator int()const;
      operator double()const;
      bool operator~()const;
      Account& operator=(const int number);
      Account& operator=(Account& acc);
      Account& operator+=(const double deposit);
      Account& operator-=(const double withdraw);
      double operator+(const Account& acc)const;

   };
   double operator+=(double& total, const Account& acc);
   bool operator==(const Account& a,const Account& b);

}
#endif // SDDS_ACCOUNT_H_