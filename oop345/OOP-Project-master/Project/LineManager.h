// Name:		Matin Hosseini Pour
// Seneca Student ID: 	151267192
// Seneca email:	smmhosseini-pour@myseneca.ca
// Date of completion: April 11th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef LINEMANAGER
#define LINEMANAGER
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
#include "Workstation.h"
#include<iostream>
namespace sdds{

    class LineManager{
        private:
            std::vector<Workstation *> activeLine;
            size_t m_cntCustomerOrder;
            Workstation *m_firstStation;
        public:
            LineManager(const std::string &file, const std::vector<Workstation *> &stations){
                m_firstStation = nullptr;
                fstream input;
                input.open(file, ios::in);
                if(!input)
                    throw "error";
                std::string line;
                m_cntCustomerOrder = pending.size();
                unordered_map<string,int> mp;
                unordered_map<string, Workstation *> mp1;
                for(auto i:stations)
                {
                    mp1[i->item_name] = i;
                }
                while(std::getline(input,line)){
                    std::string str1 = line.substr(0, line.find('|'));
                    std::string str2 = line.substr(line.find('|') + 1);
                    if(str1==str2)
                    {
                        Workstation *w = mp1[line];
                        activeLine.push_back(w);
                        if (mp.find(str1) == mp.end())
                        {
                            mp[str1]++;
                          //  mp[str2]++;
                        }
                        continue;
                    }
                    Workstation *w = mp1[str1];
                    Workstation *w1 = mp1[str2];
                    w->setNextStation(w1);
                    mp[str2]++;
                    if(mp.find(str1)==mp.end()){
                        m_firstStation = w;
                        mp[str1]++;
                        mp[str2]++;
                    }
                    activeLine.push_back(w);
                }
                input.close();
            }
            void linkStations();
            bool run(std::ostream &os);
            void display(std::ostream &os) const;
    };
}
#endif