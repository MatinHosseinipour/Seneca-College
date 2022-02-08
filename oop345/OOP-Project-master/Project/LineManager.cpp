// Name:		Matin Hosseini Pour
// Seneca Student ID: 	151267192
// Seneca email:	smmhosseini-pour@myseneca.ca
// Date of completion: April 11th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include"LineManager.h"
#include<iostream>
#include<unordered_map>
using namespace std;
namespace sdds{
    void LineManager::linkStations(){
        unordered_map<string, Workstation *> mp;
        for(auto i:activeLine)
        {
            mp[i->item_name] = i->m_pNextStation;
        }
        Workstation *curr = this->m_firstStation;
        this->activeLine.clear();
        while(curr)
        {
            curr->m_pNextStation = mp[curr->item_name];
            activeLine.push_back(curr);
            curr = mp[curr->item_name];
        }
    }
    bool LineManager::run(std::ostream& os){
        static size_t iter = 0;
        iter++;
        os << "Line Manager Iteration: " << iter << endl;
        if(pending.size()>0)
        {
            CustomerOrder c = std::move(pending.front());
            pending.pop_front();
            m_firstStation->m_orders.push_back(std::move(c));
        }
        for(const auto i:activeLine){
            i->fill(os);
        }
        for(const auto i:activeLine) {
            i->attemptToMoveOrder();
        }
        return m_cntCustomerOrder == sdds::completed.size() + sdds::incomplete.size();
    }
    void LineManager::display(std::ostream& os) const{
        for(const auto i:this->activeLine){
            i->display(os);
        }
    }
}
