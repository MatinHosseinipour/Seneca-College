//==============================================
// Name:           
// Student Number: 
// Email:         
// Section:        NJJ
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications

#include <stdio.h>

// Start your code below:


int main(void) {
	int loonies = 0, quarters = 0, dimes = 0, nickles = 0, pennies = 0;
	float amount = 0.0, gst = 0.0;
	printf("Please enter the amount to be paid: $");
	scanf("%f", &amount);
	gst = amount * 0.13 + 0.005;
	printf("GST: %.2f\n", gst);
	amount += gst;
	printf("Balance owing: $%.2f\n", amount);
	loonies = (int)amount;
	amount -= loonies;
	printf("Loonies required: %d, balance owing $%.2f\n", loonies, amount);
	quarters = (int)(amount * 100) / 25;
	amount = (amount - (quarters * 0.25));
	printf("Quarters required: %d, balance owing $%.2f\n", quarters, amount);
	dimes = (int)(amount * 100) / 10;
	amount = (amount - (dimes * 0.1));
	printf("Dimes required: %d, balance owing $%.2f\n", dimes, amount);
	nickles = (int)(amount * 100) / 5;
	amount = (amount - (nickles * 0.05));
	printf("Nickels required: %d, balance owing $%.2f\n", nickles, amount);
	pennies = (int)(amount * 100);
	amount = (amount - (pennies * 0.01));
	printf("Pennies required: %d, balance owing $%.2f", pennies, amount);

	return 0;
}