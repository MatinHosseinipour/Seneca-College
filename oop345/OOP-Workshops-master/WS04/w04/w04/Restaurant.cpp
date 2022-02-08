// Workshop 4
// Restaurant.cpp
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 14th, 2021

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Restaurant.h"

using namespace std;


namespace sdds{
    int number = 0;
    
    Restaurant::Restaurant(){
        res = nullptr;
        noOfRes = 0;
    }

    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt){
        noOfRes = 0;
        res = new Reservation[cnt];
        for(size_t i = 0; i < cnt; i++){
            res[i] = *reservations[i];
        }
        noOfRes = cnt;
    }

    Restaurant::Restaurant(Restaurant&& src){
        if(src.res != nullptr){
            res = src.res;
            noOfRes = src.noOfRes;
            src.noOfRes = 0;
            src.res = nullptr;
        }
    }

    Restaurant& Restaurant::operator=(const Restaurant& src){
        if (this != & src){
            noOfRes = src.noOfRes;

            delete[] res;
            if(src.res != nullptr){
                res = new Reservation[src.size()];
                for(size_t i = 0; i < src.size(); i++){
                    res[i] = src.res[i];
                }
            } else {
                res = nullptr;
            }
            
        }
        return *this;

    }

    Restaurant::Restaurant(const Restaurant& src){
        if(src.res != nullptr){
            res = new Reservation[src.size() + 1];
            for(size_t i = 0; i < src.size(); i++){
                res[i] = src.res[i];
            }
            noOfRes = src.noOfRes;
        }
    }


    Restaurant::~Restaurant(){
        delete[] res;
        res = nullptr;
    }

    size_t Restaurant::size() const {
        return noOfRes;
    }

    ostream& operator<<(ostream& os, const Restaurant& rest){
        number++;
        if (rest.noOfRes == 0){
            os << "--------------------------" << endl;
			os << "Fancy Restaurant (" << number << ")" << endl;
			os << "--------------------------" << endl;
			os << "This restaurant is empty!" << endl;
			os << "--------------------------" << endl;
        } else {
            os << "--------------------------" << endl;
			os << "Fancy Restaurant (" << number << ")" << endl;
			os << "--------------------------" << endl;
            for (size_t i = 0; i < rest.noOfRes; i++){
                os << rest.res[i];
                
            }
            os << "--------------------------" << endl;
        }

        return os;
    }
}