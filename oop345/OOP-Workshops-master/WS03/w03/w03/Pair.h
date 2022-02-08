// Workshop 3
// Pair.h
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 7th, 2021
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
namespace sdds {
	template< typename V, typename K>
	class Pair {
		V Val;
		K Key;
	public:
		Pair() {
		}
		Pair(const K& key, const V& value) {
			Val = value;
			Key = key;
		}
		const V& value() const {
			return this->Val;
		}
		const K& key() const {
			return this->Key;
		}
		virtual void display(std::ostream& os) const {
			os << this->key() << " : " << this->value() << std::endl;
		}
	};
	template< typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}
}
#endif