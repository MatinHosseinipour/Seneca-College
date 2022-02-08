/* Name: Matin Hosseini Pour
 Email: smmhosseini-pour@myseneca.ca
 Student Number: 151267192
 Section: NBB
*/

#ifndef FILE_H
#define FILE_H

#include <iostream>

namespace sdds
{
    bool openFile(const char filename[]);
    void closeFile();
    bool readTitle(char title[]);
    bool readYear(int* year);
    bool readMovieRating(char rating[]);
    bool readDuration(int* duration);
    bool readGenres(char genres[][11]);
    bool readConsumerRating(float* rating);
}

#endif
