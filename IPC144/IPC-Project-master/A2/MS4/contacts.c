//==============================================
// Name:           Matin Hosseini Pour
// Student Number: 151267192
// Email:          smmhosseini-pour@myseneca.ca
// Section:        NJJ
// Date:           July 31st
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+




// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+


// getName:
void getName(struct Name* name)
{
	int result;
	printf("Please enter the contact's first name: ");
	scanf("%[^\n]", name->firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");

	result = yes();
	if (result == 1)
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]s", name->middleInitial);
		//fgets(name->middleInitial, 7, stdin);

		clearKeyboard();
	}
	printf("Please enter the contact's last name: ");
	scanf("%[^\n]s", name->lastName);
	clearKeyboard();
}

// getAddress:
void getAddress(struct Address* address)
{

	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	while (address->streetNumber < 0)
	{
		printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		address->streetNumber = getInt();
	}
	printf("Please enter the contact's street name: ");
	scanf("%36[^\n]s", address->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	clearKeyboard();
	// Contact Numbers Input:
	if (yes())
	{
		printf("Please enter the contact's apartment number: ");
		//scanf("%d", &address->apartmentNumber);
		address->apartmentNumber = getInt();
		if (address->apartmentNumber < 0)
		{
			printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			address->apartmentNumber = getInt();
		}

	}
	printf("Please enter the contact's postal code: ");
	//scanf(" %[^\n]s", address->postalCode);
	fgets(address->postalCode, 8, stdin);
	clearKeyboard();


	printf("Please enter the contact's city: ");
	scanf(" %[^\n]s", address->city);
	clearKeyboard();

}







// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable

void getNumbers(struct Numbers* numbers)
{



	printf("Please enter the contact's cell phone number: ");

	getTenDigitPhone(numbers->cell);
	printf("Do you want to enter a home phone number? (y or n): ");

	if (yes())
	{
		printf("Please enter the contact's home phone number: ");
		//scanf("%*c%[^\n]", numbers->home);
		clearKeyboard();
		getTenDigitPhone(numbers->home);

	}
	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes())
	{
		printf("Please enter the contact's business phone number: ");
		//scanf("%*c%[^\n]", numbers->business);

		getTenDigitPhone(numbers->business);


	}

}


// getContact
void getContact(struct Contact* contact)
{
	getName(&(*contact).name);
	getAddress(&(*contact).address);
	getNumbers(&(*contact).numbers);
}