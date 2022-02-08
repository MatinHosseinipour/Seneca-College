// Workshop 4: DIY
// Date: 10/18/2020
// Author: Matin Hosseini Pour
// Email: smmhosseini-pour@myseneca.ca
// SenID: 151267192
/////////////////////////////////////////////
#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_
namespace sdds
{
	class NameTag{

		char* m_name;
		int m_ext;

	public:
		NameTag();
		NameTag(const char name[]);
		NameTag(const char name[], int ext);
		~NameTag();
		void print()const;
		NameTag& read();
		void flushkeys();
	};
}
#endif
