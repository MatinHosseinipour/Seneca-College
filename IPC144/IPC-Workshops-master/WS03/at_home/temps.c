//==============================================
// Name:         
// Student Number: 
// Email:          
// Section:        NJJ
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#define nums 4
#include <stdio.h>

int main(void) {
	int high, low, total = 0,totalLOW = 0, totalHIGH = 0, lowest, lowest_D, highest, highest_D, i = 1;
	int dataBase[4][2];
	float avg = 0.0;
	printf("---=== IPC Temperature Analyzer ===---");
	while (i <= nums)
	{
		printf("\nEnter the high value for day %d: ", i);
		scanf("%d", &high);
		printf("\nEnter the low value for day %d: ", i);
		scanf("%d", &low);
		if (high < low || low < -40 || high > 40)
		{
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			i--;
		}
		else {
			dataBase[i - 1][0] = high;
			dataBase[i - 1][1] = low;
		}
		i++;
		
	}
	for (i = 0; i < nums; i++)
	{
		totalLOW += dataBase[i][1];
	}
	avg = (float)totalLOW / (nums);
	printf("\nThe average (mean) LOW temperature was: %.2f", avg);
	for (i = 0; i < nums; i++)
	{
		totalHIGH += dataBase[i][0];
	}
	avg = (float)totalHIGH / (nums);
	printf("\nThe average (mean) HIGH temperature was: %.2f", avg);
	for (i = 0; i < nums; i++)
	{
		total += dataBase[i][0];
		total += dataBase[i][1];
	}
	avg = (float)total / (nums * 2);
	printf("\nThe average (mean) temperature was: %.2f", avg);
	highest = dataBase[0][0];
	highest_D = 1;
	lowest = dataBase[0][1];
	lowest_D = 1;
	for (i = 0; i < nums; i++)
	{
		if (highest < dataBase[i][0])
		{
			highest = dataBase[i][0];
			highest_D = i + 1;
		}
		else {

		}
	}
	printf("\nThe highest temperature was %d, on day %d", highest, highest_D);
	for (i = 0; i < nums; i++)
	{
		if (lowest > dataBase[i][1])
		{
			lowest = dataBase[i][1];
			lowest_D = i + 1;
		}
		else {

		}
	}
	printf("\nThe lowest temperature was %d, on day %d\n", lowest, lowest_D);

	
	return 0;
}