// Workshop 3
// PairSummable.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 7th, 2021
#ifndef SDDS_PAIR_SUMMABLE_H
#define SDDS_PAIR_SUMMABLE_H
#include "Pair.h"
#include <iostream>
#include <iomanip>
namespace sdds {
	template< typename V, typename K>
	class PairSummable : public Pair<V,K> {
		static V initVal;
		static size_t minChar;
	public:
		PairSummable() : Pair<V,K>(){
			minChar = 0;
		}
		PairSummable(const K& key, const V& value = initVal) : Pair<V, K>(key, value) {
			
			if (key.size() > minChar)
			{
				minChar = key.size() + 1;
			}
		}
		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			return (this->key() == b.key()) ? true : false;
			/*bool check = false;
			if (this->key() == b.key() )
			{
				check = true;
			}
			return check;*/
		}
		PairSummable<V,K>& operator+=(const PairSummable& item) {
			*this = PairSummable(item.key(), item.value());
			return *this;
		}
		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(minChar);
			Pair<V,K>::display(os);
			os.unsetf(std::ios::left);
		}
	};

	template< typename V, typename K>
	V PairSummable<V, K>::initVal{};
	template< typename V, typename K>
	size_t PairSummable<V, K>::minChar = 0;

	template<>
	class PairSummable<std::string, std::string> : public Pair<std::string, std::string> {
		static std::string initVal;
		static size_t minChar;
	public:
		PairSummable(): Pair() {
			minChar = 0;
		}
		PairSummable(const std::string& key, const std::string& value = initVal): Pair(key, value) {
			if (key.size() > minChar)
			{
				minChar = key.size();
			}
		}
		bool isCompatibleWith(const PairSummable& b) const {
			return (this->key() == b.key()) ? true : false;

		}
		PairSummable& operator+=(const PairSummable& item) {
			if (this->value() == "")
			{
				*this = PairSummable(this->key(), item.value());
			}
			else {
				*this = PairSummable(this->key(), this->value() + ", " + item.value());
			}
			return *this;
		}
		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(minChar);
			Pair<std::string, std::string>::display(os);
			os.unsetf(std::ios::left);
		}
	};
	std::string PairSummable<std::string, std::string>::initVal = "";
	size_t PairSummable<std::string, std::string>::minChar = 0;
	template<>
	class PairSummable<int, std::string> : public Pair<int, std::string> {
		static int initVal;
		static size_t minChar;
	public:
		PairSummable(): Pair() {
			minChar = 0;
		}
		PairSummable(const std::string& key, const int& value = initVal): Pair(key, value) {
			
			if (key.size() > minChar)
			{
				minChar = key.size();
			}
		}
		bool isCompatibleWith(const PairSummable& b) const {
			return (this->key() == b.key()) ? true : false;

		}
		PairSummable& operator+=(const PairSummable& item) {

				*this = PairSummable(item.key(), item.value() + Pair::value());
			
			return *this;
		}
		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(minChar);
			Pair<int, std::string>::display(os);
			os.unsetf(std::ios::left);
		}
	};
	int PairSummable<int, std::string>::initVal = 0;
	size_t PairSummable<int, std::string>::minChar = 0;
	
}

#endif