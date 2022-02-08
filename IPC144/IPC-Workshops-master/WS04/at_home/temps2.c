//==============================================
// Name:         
// Student Number:
// Email:         
// Section:        NJJ
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Place your code below

#include <stdio.h>

int main(void) {
	int high, low, i = 1, days = 15, days_avg = 4;
	int highest[2], lowest[2];
	float total;
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
		printf("%d    %d    %d\n", (i + 1), dataBase[i][0], dataBase[i][1]);
	}
	highest[0] = 0;
	highest[1] = dataBase[highest[0]][0];
	lowest[0] = 0;
	lowest[1] = dataBase[lowest[0]][1];
	for (i = 0; i < days; i++)
	{
		if (highest[1] <= dataBase[i][0])
		{
			highest[0] = i + 1;
			highest[1] = dataBase[i][0];
		}
	}
	for (i = 0; i < days; i++)
	{
		if (lowest[1] >= dataBase[i][1])
		{
			lowest[0] = i + 1;
			lowest[1] = dataBase[i][1];
		}
	}
	printf("\nThe highest temperature was %d, on day %d\n", highest[1], highest[0]);
	printf("The lowest temperature was %d, on day %d\n\n", lowest[1], lowest[0]);

	
	printf("Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
	scanf("%d", &days_avg);
	while (days_avg >= 0) {
		while (days_avg > 5 || days_avg == 0) {
			printf("\nInvalid entry, please enter a number between 1 and 5, inclusive: ");
			scanf("%d", &days_avg);
		}
		total = 0;
		for (i = 0; i < days_avg; i++)
		{
			total += dataBase[i][0];
			total += dataBase[i][1];
		}
		total = (total / (days_avg * 2));
		printf("\nThe average temperature up to day %d is: %0.2f\n\n",days_avg, total);
		printf("Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &days_avg);
	}

	printf("\nGoodbye!\n");
	return 0;
}

