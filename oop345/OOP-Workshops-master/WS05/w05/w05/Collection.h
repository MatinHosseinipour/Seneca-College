// Workshop 5
// Collection
// Matin Hosseini Pour
// 151267192
// smmhosseini-pour
//Feb 21st, 2021
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
namespace sdds {
	template< typename T>
	class Collection {
		std::string c_name{};
		T* collection;
		size_t c_size{};
		void (*c_observer)(const Collection<T>&, const T&);
	public:
		Collection(const std::string& i_name) {
			c_name = i_name;
			collection = nullptr;
			c_size = 0;
			c_observer = nullptr;
		}
		Collection(const Collection& i_Collection) = delete;
		Collection& operator=(const Collection& i_Collection) = delete;
		~Collection() {
			c_name = "";
			collection = nullptr;
			c_size = 0;
			c_observer = nullptr;
		}
		const std::string& name() const {
			return this->c_name;
		}
		size_t size() const {
			return this->c_size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			c_observer = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool Notadd = false;
			size_t i;
			if (c_size > 0) {
				for (i = 0; i < c_size; ++i) {
					if (collection[i].title() == item.title()) {
						return *this;
					}
				}
				if (!Notadd) {
					c_size++;
					T* temp = new T[c_size];
					for (i = 0; i < size() - 1; i++) {
						temp[i] = collection[i];
					}
					delete[] collection;
					collection = nullptr;
					collection = new T[c_size];
					for (i = 0; i < c_size - 1; ++i) {
						collection[i] = temp[i];
					}
					collection[c_size - 1] = item;
				}
			}
			else {
				collection = new T[1];
				collection[0] = item;
				c_size++;
			}
			if (c_observer)
			{
				c_observer(*this, item);
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx >= c_size) {
				std::string err = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_size) + "] items.";
				throw std::out_of_range(err);
			}
			else {
				return collection[idx];
			}
		}
		T* operator[](const std::string& title) const {
			bool search = false;
			size_t searched = 0;
			if (c_size > 0) {
				while (!search && searched < c_size)
				{
					if (collection[searched].title() == title) {
						search = true;
					}
					else {
						searched++;
					}
				}
			}
			if (search) {
				return &collection[searched];
			}
			else {
				return nullptr;
			}
		}
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& i_Collection) {
		for (size_t i = 0; i < i_Collection.size(); i++)
		{
			os << i_Collection[i];
		}
		return os;
	}
};
#endif