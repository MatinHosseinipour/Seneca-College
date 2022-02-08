// Workshop 4
// ConfirmationSender.cpp
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 14th, 2021

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds{
    ConfirmationSender::ConfirmationSender(){
        res = nullptr;
        count = 0;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender& src){
        if(src.res != nullptr){
            res = new Reservation * [src.size()];
            for(size_t i = 0; i< src.size(); i++){
                res[i] = src.res[i];
            }
            count = src.count;
        }
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src){
        if (this != &src){
            count = src.count;
            delete[] res;
            if(src.res != nullptr){
                res = new Reservation * [src.size()];
                for(size_t i = 0; i < src.size(); i++){
                    res[i] = src.res[i];
                }
            }
        } 
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& src){
        if (src.res  != nullptr){
            swap(res, src.res);
            count = src.count;
            src.res = nullptr;
            src.count = 0;
        }
    }


    ConfirmationSender::~ConfirmationSender(){
        delete[] res;
        res = nullptr;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& reserve){
        bool find = false;
        if(count <= 0){
            count++;
            res = new Reservation *[1];
            res[0] = const_cast<Reservation*>(&reserve);;
        } else{
            for(int i = 0; i < count; i++){
                find = (&reserve == res[i]);
            }
            if(!find){
                Reservation* temp[10];
                for(int i = 0; i < count; i++){
                    temp[i] = res[i];
                }
                count++;
                delete[] res;
                res = nullptr;

                res = new Reservation * [count];
                for(int i = 0; i < count -1; i++){
                    res[i] = temp[i];
                }
                res[count - 1] = const_cast<Reservation*>(&reserve);
            }
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& reserve){
        bool ok = false;
        int counter = 0;

        if (res != nullptr){
            while(counter < count && !ok){
                ok = (&reserve == res[counter++]);
            }
            if(ok){
                res[counter - 1] = nullptr;
            }
        }
        return *this;
    }

    size_t ConfirmationSender::size() const{
        return count;
    }

    ostream& operator<<(ostream& os, ConfirmationSender& src){
        if(src.count == 0){
            os << "--------------------------" << endl;
			os << "Confirmations to Send" << endl;
			os << "--------------------------" << endl;
			os << "The object is empty!" << endl;
			os << "--------------------------" << endl;
        } else {
            os << "--------------------------" << endl;
			os << "Confirmations to Send" << endl;
			os << "--------------------------" << endl;
			for (size_t i = 0; i < src.size(); i++)
			{
				if(src.res[i]!=nullptr)
					os << *src.res[i];
			}
			os << "--------------------------" << endl;
        }
        return os;
    }

    
}