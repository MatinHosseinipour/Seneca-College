// Name:		Matin Hosseini Pour
// Seneca Student ID: 	151267192
// Seneca email:	smmhosseini-pour@myseneca.ca
// Date of completion: April 11th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include"Workstation.h"
#include"CustomerOrder.h"
#include<iostream>
using namespace std;

 namespace sdds{
    deque<sdds::CustomerOrder> completed;
    deque<sdds::CustomerOrder> incomplete ;
    deque<sdds::CustomerOrder> pending ;
    void Workstation::fill(std::ostream &os){
        if (m_orders.size() == 0)
            return;
        m_orders.front().fillItem(*this, os);
    }
    void Workstation::display(std::ostream &os) const{
        if(this->m_pNextStation==nullptr)
        {
            os << this->item_name << " --> " << "End of Line"<< endl;
            return;
        }
        os << this->item_name << " --> " << this->m_pNextStation->item_name << endl;
    }
    bool Workstation::attemptToMoveOrder(){
        if(this->m_orders.size()==0 || !this->m_orders.front().isItemFilled(this->item_name))
            return false;
        CustomerOrder c = std::move(this->m_orders.front());
        m_orders.pop_front();

        if (m_pNextStation != nullptr) {
            m_pNextStation->m_orders.push_back(std::move(c));
        }
        else if (c.isFilled())
        {
            sdds::completed.push_back(std::move(c));
        }
        else {
            sdds::incomplete.push_back(std::move(c));
        }
        return true;
    }
    void Workstation::setNextStation(Workstation* station=nullptr){
        this->m_pNextStation = station;
    }
    const Workstation* Workstation::getNextStation() const{
        return m_pNextStation;
    }
    Workstation& Workstation::operator+=(CustomerOrder&& newOrder){
        this->m_orders.push_back(std::move(newOrder));
        return *this;
    }
}
