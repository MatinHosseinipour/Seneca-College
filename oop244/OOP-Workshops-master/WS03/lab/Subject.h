#ifndef SDDS_SUBJCT_H_
#define SDDS_SUBJCT_H_

namespace sdds {
	
	class Subject {
	char m_code[7]; 
	int m_mark;
	char grade()const;

	public:
		void setEmpty();
		void set(const char* code, int mark);
		float scale4()const;
		bool isValid()const;
		void display()const;
	};
};

#endif