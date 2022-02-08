#ifndef SOURCE_H
#define SOURCE_H
#include <iostream>

using namespace std;

extern double g_value = 0;;

class Foo {

	Foo* m_theBigFoo{};
};
/*
template <typename T>
T swap(T& input, T change, T to_be, T length) {
	T changed = 0;
	for (int i = 0; i < length; i++)
	{
		if (input[i] == change)
		{
			changed++;
			input[i] = to_be;
		}
	}
	return changed;
}
int swap(string& input, string change, string to_be, int length) {
	int changed = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (input[i].substr(0, 1) == change.substr(0, 1))
		{
			changed++;
			input[i].replace(input.begin(),input.end(),to_be);
		}
	}
	return changed;

}
*/
#endif