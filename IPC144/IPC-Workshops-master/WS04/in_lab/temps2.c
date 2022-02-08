//==============================================
// Name:           Matin Hosseini Pour
// Student Number: 151267192
// Email:          smmhosseini-pour@myseneca.ca
// Section:        NJJ
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>

int main(void) {
	int high, low, i = 1, days = 15;
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);
	while (days < 3 || days > 10) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
	}
	int dataBase[10][2];
	printf("\n");
	while (i <= days)
	{
		printf("Day %d - High: ", i);
		scanf("%d", &high);
		printf("Day %d - Low: ", i);
		scanf("%d", &low);
		if (high < low || low < -40 || high > 40)
		{
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.");
			i--;
		}
		else {
			dataBase[i - 1][0] = high;
			dataBase[i - 1][1] = low;
		}
		i++;

	}
	printf("\nDay  Hi  Low\n");
	for (i = 0; i < days; i++)
	{
		printf("%d    %d    %d\n",(i+1),dataBase[i][0], dataBase[i][1]);
	}

	return 0;
}

