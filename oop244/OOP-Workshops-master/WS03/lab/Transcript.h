#ifndef SDDS_TRANSCRIPT_H_
#define SDDS_TRANSCRIPT_H_
#include "Subject.h"

namespace sdds {

	class Transcript {

		char* m_studentName;
		Subject* m_subjects;
		int m_noOfSubjects;
		int m_subjectsAdded;
		void setEmpty();
		bool isValid()const;
		void title()const;
		float gpa()const;
		void footer()const;
	
		public:
			void init(const char* studentName, int noOfSubjects);
			bool add(const char* subject_code, int mark);
			void display()const;
			void deallocate();
	};

};

#endif