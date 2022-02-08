// Workshop 2: 
// Version: 0.9
// Date: 10/4/2020
// By: Matin Hosseini Pour
// Section: NJJ
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(int& acc_num);
   bool read(double& acc_bal);
}
#endif // !SDDS_FILE_H_
