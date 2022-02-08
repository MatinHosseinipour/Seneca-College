#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;

static int roses = 0;
class Bouquet{
	string* flowerNames;
	unsigned int flowers;
	bool containRose = false;
public:
	Bouquet();
	Bouquet(unsigned int i_flowers, const string* i_flowerNames = nullptr);
	bool operator == (const Bouquet* i_bouquet) const;
	~Bouquet();
};
Bouquet::Bouquet(){
	flowerNames = nullptr;
	flowers = 0;
}
Bouquet::Bouquet(unsigned int i_flowers, const string* i_flowerNames) {
	if (i_flowerNames == nullptr && i_flowers != 0)
	{
		throw "Bad Parameters";
	}
	else {
		flowerNames = new string[i_flowers];
		for (unsigned int i = 0; i < i_flowers; i++)
		{
			flowerNames[i] = i_flowerNames[i];
			if (flowerNames[i] == "Rose")
			{
				containRose = true;
				roses++;
			}
		}
		flowers = i_flowers;
	}
}
bool Bouquet::operator == (const Bouquet* i_bouquet) const {
	bool check = true;
	//If the two Bouquets compared are empty Bouquets, your operator returns false.
	if (flowers == 0 && i_bouquet->flowers == 0)
	{
		return false;
	}
	//if at least one instance contains no flowers, terminate the program with the exit code 20.
	if (flowers == 0 || i_bouquet->flowers == 0)
	{
		throw 20;
	}
	else if(flowers != i_bouquet->flowers){
		throw "Not Equal Amount of Flowers";
	}
	else {
		for (int i = 0; i < flowers; i++)
		{
			if (flowerNames[i] != i_bouquet->flowerNames[i])
			{
				check = false;
			}
			if (flowerNames[i] == "Poison Ivy")
			{
				throw 1;
			}
			if (i_bouquet->flowerNames[i] == "Poisong Ivy")
			{
				throw 2;
			}
		}
	}
	return check;
}
Bouquet::~Bouquet() {
	delete[] flowerNames;
	flowers = 0;
	if (containRose)
	{
		roses--;
	}
}
int main(void) {
	/*
	For example if Bouquet A has 3 flowers [Iris, Rose, Maquia] and
	Bouquet B has 3 flowers [Iris, Rose, Maquia], then they are considered the same.

	However, if Bouquet A has 3 flowers [Iris, Rose, Maquia] and
	Bouquet B has 3 flowers [Iris, Maquia, Rose], then they are considered different,
	since the orders of the flowers in the arrays are different.

	If the two Bouquets compared are empty Bouquets, your operator returns false.

	*/
	//ex1
	string* flowers1 = new string[3];
		flowers1[0] = "Iris";
		flowers1[1] = "Rose";
		flowers1[2] = "Maquia";
		Bouquet A(3, flowers1);
		Bouquet B(3, flowers1);
		return 0;
}


