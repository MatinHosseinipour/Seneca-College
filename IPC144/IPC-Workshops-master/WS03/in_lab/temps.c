//==============================================
// Name:           Matin Hosseini Pour
// Student Number: 151267192
// Email:          smmhosseini-pour@myseneca.ca
// Section:        NJJ
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#define nums 3
#include <stdio.h>

int main(void) {
	int high, low, total = 0, i = 1;
	
	float avg = 0.0;
	printf("---=== IPC Temperature Analyzer ===---");
	while(i<=nums)
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
			total += high + low;
		}
		i++;
	}
	avg = (float)total / (nums*2);
	printf("\nThe average (mean) temperature was: %.2f\n", avg);
	return 0;
}