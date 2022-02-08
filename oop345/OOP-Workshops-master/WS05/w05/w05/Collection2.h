#ifndef SDDS_COLLECTION2_H
#define SDDS_COLLECTION2_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
namespace sdds {
	template<typename T>
	class Collection {
		std::string m_Colname;
		T* m_Colarray;
		size_t m_Colsize;
		void* Col(const Collection<T>&, const T&) {


		};
	public:
		Collection(const std::string& name) {
			m_Colname = name;
			this->m_Colarray = nullptr;
			m_size = 0;

		};
		//this class doesn't support any copy operations; delete all of them there need to come a method here.
		//Copy constructor
		Collection(const Collection& src) = delete;
		//copy assignment operator
		Collection& operator=(const Collection& src) = delete;


		Collection() {
			m_Colname = " ";
			m_Colarray = nullptr;
			m_Colsize = 0;
		};
		const std::string& name() const {
			return m_Colname;
		};

		size_t size() const {
			return m_Colsize;

		};
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {


		};
		Collection<T>& operator+=(const T& item) {
			bool find = false;
			int i;
			if (m_Colsize > 0) {
				for (i = 0; i < m_Colsize; ++i) {
					find = (m_Colarray[i].title() = item.title());
				}
				if (!found) {
					T temp[m_Colsize + 1];
					for (i = 0; i < m_Colsize; i++) {
						temp[i] == m_Colarray[i];
					}
				}
				m_Colsize++;
				delete[]m_Colarray;
				m_Colarray = nullptr;
				m_Colarray = new T[col_size];
				for (i = 0; i < m_Colsize - 1; ++i) {
					m_Colarray[i] = temp[i];
				}
				m_Colarray[m_Colsize - 1] = item;
			}
			else {
				m_Colarray = new T[1];
				m_Colarray[0] = item;
				m_Colsize++;
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx[i] > m_Colsize) {
				throw std::out_of_range "Bad index [" + to_string(5) + "]. Collection has [" + to_string(5) + "] items";
			}
			else {
				return m_Colarray[idx];
			}
		}
		T* operator[](const std::string& title) const {
			bool found = false;
			int k = 0;
			if (m_Colsize > 0) {
				while (!found && i < m_Colsize)
				{
					if (m_Colarray[i].title() == title) {
						found = true;
					}
					else {
						k++;
					}
				}
			}
			if (found) {
				return &m_Colarray[i];
			}
			else {
				return nullptr;
			}
		};


	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, Collection<T>& cl) {

	}

};

#endif 