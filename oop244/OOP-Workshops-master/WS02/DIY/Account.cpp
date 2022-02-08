// Workshop 2: 
// Version: 0.9
// Date: 10/4/2020
// By: Matin Hosseini Pour
// Section: NJJ
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#include "iostream"
#include <string.h>
#include "Account.h"
#include "File.h"
using namespace std;
namespace sdds {
    int total_Accs;
    Account* acc;

    //coppied from lab part but edited
    void sort() {
        int i, j;
        Account temp;
        for (i = total_Accs - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (acc[j].balance > acc[j + 1].balance) {
                    temp = acc[j];
                    acc[j] = acc[j + 1];
                    acc[j + 1] = temp;
                }
            }
        }
    }
    bool load(const char data_File[]) {
        bool ok = false;
        int i = 0;
        if (openFile(data_File)) {
            total_Accs = noOfRecords();
            acc = new Account[total_Accs];  
            while (i< total_Accs && load(acc[i]))
            {
                i++;
            }
            ok = true;
        }
        else {
            cout << "Could not open data file: " << data_File;
            ok = false;
        }
        closeFile();
        return ok;
    }
    bool load(Account& acc) {
        bool ok = false;
        if (read(acc.number) && read(acc.balance))
        {
            ok = true;
        }
        return ok;
    }
    void display() {
        sort();
        int i, x = 1;
        cout << "Account#: Balance" << endl;
        for (i = 0; i < total_Accs; i++)
        {
            cout << x << ": ";
            display(acc[i]);
            x++;
        }
    }

    void display(Account acc) {
        cout << acc.number << ":  " << acc.balance << endl;
    }
    void deallocateMemory() {
        delete[] acc;
    }
}