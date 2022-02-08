// Name:		Matin Hosseini Pour
// Seneca Student ID: 	151267192
// Seneca email:	smmhosseini-pour@myseneca.ca
// Date of completion: April 11th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
namespace sdds
{
    size_t CustomerOrder::m_widthField = 1;
    CustomerOrder::CustomerOrder(CustomerOrder &other)
    {
        throw 1;
    }
    CustomerOrder::CustomerOrder(std::string &str)
    {
        Utilities utilitie;
        size_t next = 0;
        bool more = true;
        if (more)
            this->m_name = utilitie.extractToken(str, next, more);
        if (more)
            this->m_product = utilitie.extractToken(str, next, more);
        std::vector<std::string> arr;
        while (more)
        {
            arr.push_back(utilitie.extractToken(str, next, more));
        }
        m_lstItem = new Item*[arr.size()];
        int k = 0;
        for (auto i : arr)
        {
            Item *temp = new Item(i);
            *(this->m_lstItem+k++) = temp;
        }
        m_cntItem = arr.size();
        m_widthField = m_widthField > utilitie.m_widthField ? m_widthField : utilitie.m_widthField;
    }
    CustomerOrder::CustomerOrder(CustomerOrder &&other) noexcept
    {
        m_lstItem = nullptr;
        m_lstItem = other.m_lstItem;
        m_name = other.m_name;
        m_product = other.m_product;
        m_cntItem = other.m_cntItem;
        other.m_lstItem = nullptr;
    }
    CustomerOrder &CustomerOrder::operator=(CustomerOrder &&other) noexcept
    {
        m_lstItem = nullptr;
        m_lstItem = other.m_lstItem;
        m_name = other.m_name;
        m_product = other.m_product;
        m_cntItem = other.m_cntItem;
        other.m_lstItem = nullptr;
        return *this;
    }
    bool CustomerOrder::isFilled() const
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (!this->m_lstItem[i]->m_isFilled)
                return false;
        }
        return true;
    }
    bool CustomerOrder::isItemFilled(const std::string &itemName) const
    {
        bool ans = true;
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (this->m_lstItem[i]->m_itemName == itemName)
            {
                ans = ans & this->m_lstItem[i]->m_isFilled;
            }
        }
        return ans;
    }
    void CustomerOrder::fillItem(Station &station, std::ostream &os)
    {
        for (size_t i = 0; i < this->m_cntItem; i++)
        {
            if (this->m_lstItem[i]->m_itemName == station.item_name)
            {
                if (station.quantity > 0)
                {
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    station.updateQuantity();
                    os << "    Filled " << this->m_name << ", " << this->m_product << " [" << this->m_lstItem[i]->m_itemName << "]\n";
                }
                else if (m_lstItem[i]->m_isFilled == false)
                {
                    os << "    Unable to fill " << this->m_name << ", " << this->m_product << " [" << this->m_lstItem[i]->m_itemName << "]\n";
                }
            }
        }
    }
    void CustomerOrder::display(std::ostream &os) const
    {
        os << this->m_name << " - " << this->m_product << "\n";

        for (size_t i = 0; i < this->m_cntItem; i++)
        {
            os << "[";
            os << std::setfill('0');
            os << std::setw(6) << this->m_lstItem[i]->m_serialNumber;
            os << std::setfill(' ');
            os << "] ";
            os.setf(std::ios::left);
            os << std::setw(this->m_widthField) << this->m_lstItem[i]->m_itemName;
            os.unsetf(std::ios::left);
            os << " - ";
            if (this->m_lstItem[i]->m_isFilled)
                os << "FILLED";
            else
                os << "TO BE FILLED";
            os << "\n";
        }
    }
}
