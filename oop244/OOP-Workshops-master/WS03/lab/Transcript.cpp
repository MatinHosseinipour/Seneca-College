#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Transcript.h"
#include "Subject.h"

using namespace std;
namespace sdds {

    void Transcript::setEmpty() {
        m_studentName = nullptr;
        m_subjects = nullptr;
    }

    bool Transcript::isValid()const {

        if (m_studentName == NULL || m_subjects == NULL || m_subjectsAdded < m_noOfSubjects) {
            return false;
        }

        for (int i = 0; i < m_subjectsAdded; i++) {
            if (!m_subjects[i].isValid()) {
                return false;
            }
        }
        return true;
    }

    void Transcript::title()const {
        cout << m_studentName << endl;
        cout << "-----------------------------" << endl;
    }

    float Transcript::gpa()const {
        double sum = 0;
        for (int i = 0; i < m_subjectsAdded; i++) {
            sum += m_subjects[i].scale4();
        }
        return sum / m_subjectsAdded;
    }

    void Transcript::footer()const {
        cout << "-----------------------------" << endl;
        cout.width(26);
        cout.precision(2);
        cout << "GPA: " << gpa() << endl;
    }

    void Transcript::init(const char* studentName, int noOfSubjects) {
        if (studentName[0] == '\0' || noOfSubjects < 1) {
            m_subjectsAdded = 0;
            m_noOfSubjects = 0;
            m_subjects = nullptr;
            m_studentName[0] = '\0';
        }
        else {
            m_subjectsAdded = 0;
            m_studentName = new char[strlen(studentName) + 1];
            strcpy(m_studentName, studentName);
            m_subjects = new Subject[noOfSubjects];
            m_noOfSubjects = noOfSubjects;
        }
    }

    bool Transcript::add(const char* subject_code, int mark) {
        if (m_subjectsAdded >= m_noOfSubjects) {
            return false;
        }
        else {
            m_subjects[m_subjectsAdded].set(subject_code, mark);
            m_subjectsAdded++;
            return true;
        }
    }

    void Transcript::display()const {
        if (isValid()) {
            title();
            for (int i = 0; i < m_subjectsAdded; i++) {
                m_subjects[i].display();
            }
            footer();
        }
        else {
            cout << "Invalid Transcript!" << endl;
        }
    }

    void Transcript::deallocate() {
        delete[] m_studentName;
        delete[] m_subjects;
    }
};