// Name:		Matin Hosseini Pour
// Seneca Student ID: 	151267192
// Seneca email:	smmhosseini-pour@myseneca.ca
// Date of completion: April 11th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef WORKSTATION
#define WORKSTATION
#include<deque>
#include"CustomerOrder.h"
using namespace std;
namespace sdds{
    extern deque<sdds::CustomerOrder> completed;
    extern deque<sdds::CustomerOrder> incomplete;
    extern deque<sdds::CustomerOrder> pending;
    class Workstation: public Station 
    {
    public:
        deque<sdds::CustomerOrder> m_orders;
        Workstation *m_pNextStation;

    public:
        Workstation(const std::string &str1) : Station(str1){
            m_pNextStation = nullptr;
        }
        Workstation(Workstation &) = delete;
        Workstation(Workstation &&) = delete;
        void fill(std::ostream &os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation *station);
        const Workstation *getNextStation() const;
        void display(std::ostream &os) const;
        Workstation &operator+=(CustomerOrder &&newOrder);
    };
}

#endif