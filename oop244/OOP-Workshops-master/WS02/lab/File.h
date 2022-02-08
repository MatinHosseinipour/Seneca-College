#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   bool read(char m_name[]);
   bool read(int& m_studentnumber);
   bool read(double& m_gpa);

}
#endif SDDS_FILE_H_
