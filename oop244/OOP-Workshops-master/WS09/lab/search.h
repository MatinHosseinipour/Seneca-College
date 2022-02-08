#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_
#include <iostream>
#include "Collection.h"
namespace sdds {
	/*
	template must be an array of characters
	array must be at least 1
	pattern must have value
	template must be copy-able
	returns true or false
	*/
	template <class type>
	bool search(type i_data[], int i_size, const char pattern[], Collection<type>& i_coll) {
		bool found = false;
		for (int i = 0; i < i_size; i++)
		{
			if (i_data[i] == pattern)
			{
				found = true;
				i_coll.add(i_data[i]);

			}
		}
		return found;
	}
}
#endif