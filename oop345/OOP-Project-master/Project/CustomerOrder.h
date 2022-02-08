// Name:		Matin Hosseini Pour
// Seneca Student ID: 	151267192
// Seneca email:	smmhosseini-pour@myseneca.ca
// Date of completion: April 11th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef CUSTOMERORDER
#define CUSTOMERORDER
#include <string>
#include <vector>
#include "Utilities.h"
#include "Station.h"
namespace sdds
{
    class CustomerOrder
    {
        struct Item
        {
            std::string m_itemName;
            size_t m_serialNumber{0};
            bool m_isFilled{false};

            Item(const std::string &src) : m_itemName(src){};
        };

    public:
        std::string m_name;
        std::string m_product;
        size_t m_cntItem;
        Item **m_lstItem;
        static size_t m_widthField;

    public:
        CustomerOrder(std::string &str);
        CustomerOrder(CustomerOrder &other);
        CustomerOrder& operator=(CustomerOrder &other) = delete;
        CustomerOrder(CustomerOrder &&other) noexcept;
        CustomerOrder& operator=(CustomerOrder && other) noexcept;
        bool isFilled() const;
        bool isItemFilled(const std::string &itemName) const;
        void fillItem(Station &station, std::ostream &os);
        void display(std::ostream &os) const;
    };
}
#endif