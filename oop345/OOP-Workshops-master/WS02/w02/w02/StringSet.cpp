// Workshop 2
// StringSet.cpp
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Jan 30th, 2021
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include "StringSet.h"
#include "StringSet.h"
using namespace std;

namespace sdds {
    StringSet::StringSet() {

    }

    StringSet::~StringSet() {
        delete[] input;
    }
    StringSet::StringSet(char* i_file) {
        numOfIn = 0;
        string abc = "";
        ifstream file(i_file);
        while (!file.eof()) {
            getline(file, abc, ' ');
            numOfIn++;
        }
        file.close();
        input = new string[numOfIn];
        int i = 0;
        ifstream file2(i_file);
        while (!file2.eof()) {
            getline(file2, input[i], ' ');
            i++;
        }
        file2.close();
    }

    size_t StringSet::size()
    {
        return numOfIn;
    }

    std::string StringSet::operator[](size_t index)
    {
        string asked{};
        if (index < numOfIn)
        {  
            asked = input[index];
        }
        return asked;
    }

    StringSet::StringSet(StringSet&& obj) {
        this->numOfIn = obj.size();
        this->input = obj.input;
        obj.input = nullptr;
        obj.numOfIn = 0;
    }

    StringSet& StringSet::operator=(StringSet&& obj)
    {
        if (&obj == this)
        {
            return *this;
        }
        this->numOfIn = obj.size();
        this->input = obj.input;
        obj.input = nullptr;
        obj.numOfIn = 0;
        return *this;
    }
    StringSet& StringSet::operator=(StringSet& obj)
    {
        if (&obj == this)
        {
            return *this;
        }
        this->numOfIn = obj.numOfIn;
        this->input = new string[numOfIn];
        for (size_t i = 0; i < obj.numOfIn; i++) {
            input[i] = obj.input[i];
        }
        return *this;
    }
    StringSet::StringSet(StringSet& obj) {
        this->numOfIn = obj.numOfIn;
        this->input = new string[numOfIn];
        for (size_t i = 0; i < obj.numOfIn; i++) {
            this->input[i] = obj.input[i];
        }
    }
}