// Workshop 3: DIY
// Date: 10/11/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#ifndef BOX_H
#define BOX_H
#include <iostream>
namespace sdds
{
	class Box
	{
	
	private:
        char* m_contentName;   // the conent name pointer:
                               // this pointer holds the name of the material to be kept in the box
                               // dynamically
        int m_width;           // The dimensions of the box in Inches
        int m_height;
        int m_length;
        int m_contentVolume;   // the content volume:
                               // This variable holds the volume of the material currently in 
                               // the box in Cubic Inches
        void setName(const char* Cstr);
        void setUnusable();
        bool isUnusable()const;
        bool hasContent()const;
	public:
        Box();//constructor
        Box(int sideLength, const char* contentName = nullptr);//constructor
        Box(int width, int height, int length, const char* contentName = nullptr);//constructor
        ~Box();
        int capacity()const;
        int quantity()const;
        Box& setContent(const char* contentName);
        std::ostream& display()const;
        Box& add(int quantity);
        Box& add(Box& B);
	};

}
#endif // !BOX_H

