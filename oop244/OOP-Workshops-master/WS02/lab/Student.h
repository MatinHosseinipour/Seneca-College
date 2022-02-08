#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

#define DATAFILE "students.csv"
namespace sdds {
    struct Student {
        char* m_name;
        int m_studentNumber;
        double m_gpa;
    };
    //sorts the dynamic array of students based on the GPA of the students.
    void sort();
    // loads a student structue with its values from the file
    bool load(Student& student);
    // allocates the dyanmic array of students and loads all the file
    // recoreds into the array
    bool load();

    // TODO: Declare the prototype for the display function that
    // displays a student record on the screen:
    void display(const Student& student);
    // TODO: Declare the prototype for the display function that 
    // first sorts the students then displays all the students on the screen
    void display();
    // TODO: Declare the prototype for the deallocateMemory function that
    // first will deallocate all the names in the student elements
    // then it will deallocate the student array 
    void deallocateMemory();
}
#endif SDDS_STUDENT_H_