#include <stdio.h>
#include <iostream>
using namespace std;

void pbits(int bits[]);

void main() {
	int bits[50] = { 0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,2 };
	int framing[] = { 0,1,1,1,1,1,1,0,2 };
	const int b_length = sizeof(bits) / sizeof(bits[0]);
	bool flag = false, flag2 = true;
	cout << "Before stuffing: ";
	pbits(bits);
	int i, j, counter = 0;
	//stuffing
	for (i = 0; bits[i] != 2; i++)
	{
		if (bits[i] == 1)
		{
			counter++;
			if (counter == 5)
			{
				int bits2[b_length] = { '\0' };
				for (j = 0; flag2; j++)
				{
					if (i >= j)
					{
						bits2[j] = bits[j];
					}
					else
					{
						if (!flag)
						{
							bits2[j] = 0;
							flag = true;
						}
						else {
							bits2[j] = bits[j - 1];
						}
					}
					if (bits[j-1] == 2)
					{
						flag2 = false;
						bits2[j] = 2;
					}
				}
				flag2 = true;
				flag = false;
				for (j = 0; flag2; j++)
				{
					bits[j] = bits2[j];
					if (bits2[j] == 2)
					{
						flag2 = false;
					}
				}
				flag2 = true;
			}
		}
		else if (bits[i] == 0) {
			counter = 0;
		}
		else {
			bits[i] = '\0';
		}
	}
	cout << "After stuffing: ";
	pbits(bits);
	//framing
	i = 0;
	j = 0;
	while (!flag) {
		int bits2[b_length] = { '\0' };
		for (j = 0; framing[j] != 2; j++)
		{
			bits2[j] = framing[j];
		}
		i = j;
		for (j = 0; bits[j] != 2; j++, i++)
		{
			bits2[i] = bits[j];
		}
		for (j = 0; flag2; j++, i++)
		{
			bits2[i] = framing[j];
			if (bits2[i] == 2)
			{
				flag2 = false;
			}
		}
		flag2 = true;
		for (j = 0; flag2; j++)
		{
			bits[j] = bits2[j];
			if (bits2[j] == 2)
			{
				flag2 = false;
			}
		}
		flag = true;
	}
	cout << "After framing: ";
	pbits(bits);
}
void pbits(int bits[]) {
	int i;
	bool flag = true;
	for (i = 0; bits[i] != 2; i++)
	{
		cout << bits[i] << " ";
	}
	cout << " --- " << i << " characters" << endl;
}