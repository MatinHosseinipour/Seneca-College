//==============================================
// Name:           Matin Hosseini Pour
// Student Number: 151267192
// Email:          smmhosseini-pour@myseneca.ca
// Section:        NJJ
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Start your code below:


int main(void) {
	int loonies = 0, quarters = 0;
	float amount = 0.0;
	printf("Please enter the amount to be paid: $");
	scanf("%f",&amount);
	loonies = (int)amount;
	amount -= loonies;
	printf("Loonies required: %d, balance owing $%.2f\n", loonies, amount);
	quarters = (int)(amount*100) / 25;
	amount = (amount - (quarters * 0.25));
	printf("Quarters required: %d, balance owing $%.2f\n", quarters, amount);
	return 0;
}