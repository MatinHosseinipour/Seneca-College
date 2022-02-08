/* Name: Matin Hosseini Pour
 Email: smmhosseini-pour@myseneca.ca
 Student Number: 151267192
 Section: NBB
*/

#include "School.h"
using namespace std;

namespace sdds
{
	Tel tel2[TEL_NUMBER];

    bool loadTels() {
        Tel tel;
        int telnum = 0; 
        bool ok = true;
        if (openFile("schools.dat")) {
            while (ok && telnum < TEL_NUMBER) {
                ok = getSchoolCode(tel.schoolCode) && getExt(&tel.extNumber);
                if (ok) {
                    tel2[telnum++] = tel;
                }
            }
            closeFile();
        }
        return telnum == TEL_NUMBER;
    }

    bool findCode(const char schoolCode[], Tel &tel) {
        int i = 0;
        bool found = false;
        while (!found && i <= TEL_NUMBER) {
            if (strcmp(tel2[i].schoolCode, schoolCode) == 0) {
                found = true;
                tel = tel2[i];
            }
            i++;
        } 
        return found;
    }

    void displayTels(const Tel* tel) {
        cout << BASE_num << " x " << tel->extNumber;
        cout << endl;
    }

}
