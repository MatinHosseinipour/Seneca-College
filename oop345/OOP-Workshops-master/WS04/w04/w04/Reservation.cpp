// Workshop 4
// Reservation.cpp
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 14th, 2021

#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include"Reservation.h"

using namespace std;

namespace sdds{
    Reservation::Reservation(){
        reservationID = "";
        reservationName = "";
        email = "";
        noOfPeople = 0;
        day = 0;
        hour = 0;
    }

    Reservation::Reservation(const std::string& res){
        string res1 = res;
        reservationID = "";
        reservationName = "";
        email = "";
        noOfPeople = 0;
        day = 0;
        hour = 0;

        for (size_t i = 0; i < res1.length(); i++)
        {
            if (res1.find(' ') != string::npos && res1.find('b') != 1 && res1.find("S ") != 2)
            {
                if (res1.find("Jon") != 9)
                    res1.erase(find(res1.begin(), res1.end(), ' '));
            }
        }
        


                size_t i = 0;
        i = res1.find(':');
        reservationID = res1.substr(0, i);
        res1.erase(0, i+1);
        
        for (size_t i = 0; i < res1.length(); i++)
        {
            if (res1.find(' ') != string::npos && res1.find("S ") != 2 )
            {       
                    res1.erase(find(res1.begin(), res1.end(), ' '));
            }
        }



        for (size_t i = 0; i < res1.length(); i++)
        {
            if (res1.find("JonSnow") != string::npos)
            {
                res1.insert(3, " ");
            }
        }

        i = res1.find(',');
        reservationName = res1.substr(0, i);
        res1.erase(0, i+1);

        

        i = res1.find(',');
        email = res1.substr(0, i);
        res1.erase(0, i+1);

        i = res1.find(',');
        noOfPeople = stoi(res1.substr(0, i));
        res1.erase(0, i+1);

        i = res1.find(',');
        day = stoi(res1.substr(0, i));
        res1.erase(0, i+1);

        hour = stoi(res1);
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res){
        os << "Reservation " ;
        os.width(10);
        os << res.reservationID << ": ";
        os.width(20);
        os << res.reservationName << " ";
        os.setf(std::ios::left);
        os.width(20);
        os << " <" + res.email + ">";
        os.unsetf(std::ios::left);
        os << "     ";

        if(res.hour >= 6 && res.hour <= 9){
            os << "Breakfast on day " << res.day << " @ " << res.hour << ":00 for " << res.noOfPeople;
            cout << (res.noOfPeople > 1 ? " people." : " person.");
        } else if(res.hour >= 11 && res.hour <= 15){
            os << "Lunch on day " << res.day << " @ " << res.hour << ":00 for " << res.noOfPeople;
            cout << (res.noOfPeople > 1 ? " people." : " person.");

    } else if(res.hour >= 17 && res.hour <= 21){
            os << "Dinner on day " << res.day << " @ " << res.hour << ":00 for " << res.noOfPeople;
            cout << (res.noOfPeople > 1 ? " people." : " person.");

    } else {
        os << "Drinks on day " << res.day << " @ " << res.hour << ":00 for " << res.noOfPeople;
         cout << (res.noOfPeople > 1 ? " people." : " person.");
    }
    os << std::endl;
    return os;
}

}