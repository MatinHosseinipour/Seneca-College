#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"
#include "File.h"
using namespace std;
namespace sdds {
   int noOfStudents;
   Student* students;


   void sort() {
      int i, j;
      Student temp;
      for (i = noOfStudents - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (students[j].m_gpa > students[j + 1].m_gpa) {
               temp = students[j];
               students[j] = students[j + 1];
               students[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one student record from the file and loads it into the student reference
   // argument
   bool load(Student& student) {
      bool ok = false;
      char name[128];
      int stNumber;
      double stGPA;
      // if reading of name is successful
      if (read(name)) {
         // allocate memory to the size of the name + 1
         // and keep its address in the name of the Student Reference
          //name[strlen(name) + 1];
          student.m_name[strlen(name+1)];
         // copy the name into the newly allocated memroy
          student.m_name = name;
         // read student number and gpa from the file into the corresponding
          if (read(stNumber))
          {
              student.m_studentNumber = stNumber;
              if (read(stGPA))
              {
                  student.m_gpa = stGPA;
              }
              else {
                  cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
                  return false;
              }
          }
          else {
              cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
              return false;
          }
         // variables in the Student Referenct
         // make sure the "ok" flag is set to true, if all is good
      }
      else {
          cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
          return false;
      }
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
         // set the noOfStudents to the number of recoreds in the file.
          noOfStudents = noOfRecords();
         // dyanamically allocated an array of students into the global
         // Student pointer; "students" to the size of the noOfStudents.
          students[noOfStudents];
         // in a loop load the student records from the file into 
         // the dynamic array.
          while (i < noOfStudents && load(students[i])) {
              i++;
          }
         // if th number of the records does not match the number of reads
         // print an error message
         if (i != noOfStudents){
             cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
         }
         else {
            ok = true;
         }
         closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Student& student) {
       cout << student.m_name << ", " << student.m_studentNumber << " : " << student.m_gpa << endl;
   }
   void display() {
       sort();
       int i;
       for (i = 0; i < noOfStudents; i++)
       {
           cout << (i++) << ": " << students[i].m_name << ", " << students[i].m_studentNumber << " : " << students[i].m_gpa << endl;
       }
   }
   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
       int i;
       for (i = 0; i < noOfStudents; i++)
       {
           students[i].m_name = nullptr;
       }
       students = nullptr;
   }


}