// Workshop 2
// StringSet.cpp
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Jan 30th, 2021
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "StringSet.h"
#include "StringSet.h"
using namespace std;
using namespace sdds;

StringSet::StringSet(){

}

StringSet::StringSet(char* i_file){
    numOfIn = 0;
    char abc{};
    ifstream file(i_file);
    while (!file.eof()) {
        file >> abc;
        numOfIn++;
    }
    file.close();

    input = new string[numOfIn + 1];
    int i = 0;
    ifstream file2(i_file);
    while (!file2.eof()) {
        file2 >> input[i];
        i++;
    }
    file.close();
}

size_t StringSet::size()
{
    return numOfIn;
}

std::string sdds::StringSet::operator[](size_t index)
{
    string asked{};
    if (index <= numOfIn)
    {
        asked = input[index];
    }
    return asked;
}
