// Workshop 2: 
// Version: 0.9
// Date: 10/4/2020
// By: Matin Hosseini Pour
// Section: NJJ
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
namespace sdds {
	struct Account {
		int number;
		double balance;
	};
	void sort();
	bool load(const char dataFile[]);
	bool load(Account& acc);
	void display();
	void display(Account acc);
	void deallocateMemory();

}
#endif // SDDS_ACCOUNT_H_