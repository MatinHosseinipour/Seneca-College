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
#include <string.h>


#include "contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}


// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
	printf("\n");
}


// getInt:
int getInt(void)
{
	int value;
	char check;
	scanf("%d%c", &value, &check);


	while (check != '\n')
	{
		clearKeyboard();


		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf("%d%c", &value, &check);




	}
	return value;


}



// getIntInRange:
int getIntInRange(int min, int max)
{
	int valid, flag = 0;


	do
	{
		valid = getInt();
		if (valid < min || valid > max)
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		else
			flag = 1;
	} while (flag != 1);


	return valid;
}


// yes:
int yes(void)
{
	char selection, NL;
	int result = 0;
	scanf("%c%c", &selection, &NL);
	while (NL != '\n' || (selection != 'y' && selection != 'Y' && selection != 'n' && selection != 'N'))
	{
		clearKeyboard();
		printf("*** INVALID ENTRY ***");
		printf(" <Only (Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &selection, &NL);
	}
	if (selection == 'y' || selection == 'Y')
	{
		result = 1;
	}

	else

		result = 0;

	return result;
}


// menu:
int menu(void)
{
	int choice;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");
	choice = getIntInRange(0, 6);
	printf("\n");
	return choice;
}


void contactManagerSystem(void)
{

	struct Contact contact[MAXCONTACTS] = {
	  {
		{ "Rick",{ '\0' }, "Grimes" },
		{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
		{ "4161112222", "4162223333", "4163334444" } },
		{
		  { "Maggie", "R.", "Greene" },
		  { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		  { "9051112222", "9052223333", "9053334444" } },
		  {
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } },
			{
			  { "Sasha",{ '\0' }, "Williams" },
			  { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			  { "9052223333", "9052223333", "9054445555" } },
	};

	int done = 0, option;

	while (done == 0)
	{

		option = menu();
		switch (option)
		{

		case 1:
			displayContacts(contact, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 2:
			addContact(contact, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 3:
			updateContact(contact, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 4:
			deleteContact(contact, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 5:
			searchContacts(contact, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 6:
			printf("<<< Feature to sort is unavailable >>>\n\n");
			pause();
			break;

		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			done = yes();
			printf("\n");
			break;


		default:
			break;
		}
	}
	printf("Contact Management System: terminated\n");
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;

	while (needInput == 1)
	{
		scanf("%10[0-9]", phoneNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10)
		{
			needInput = 0;
		}
		else
		{
			printf("Enter a 10-digit phone number: ");
		}
	}


}
// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{

	int j;
	int i = 0;
	int index = -1;
	do
	{
		j = strcmp(contacts[i].numbers.cell, cellNum);
		if (j == 0)
		{
			index = i;
		}
		i++;
	} while (i < size);

	return index;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

}

// displayContactFooter
void displayContactFooter(int size)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", size);
}


// displayContact:
void displayContact(const struct Contact* contact)
{
	if (strcmp((*contact).name.middleInitial, "") == 0)
		printf(" %s %s\n", (*contact).name.firstName, (*contact).name.lastName);
	else
		printf(" %s %s %s\n", (*contact).name.firstName, (*contact).name.middleInitial, (*contact).name.lastName);

	printf("    C: %-10s   H: %-10s   B: %-10s\n", (*contact).numbers.cell, (*contact).numbers.home, (*contact).numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0) printf("Apt# %d, ", contact->address.apartmentNumber);
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);

}


// displayContacts:
void displayContacts(const struct Contact contact[], int size)
{
	int i = 0, j = 0;
	int lenght;
	displayContactHeader();

	for (i = 0; i < size; i++)
	{
		lenght = strlen(contact[i].numbers.cell);
		if (lenght > 0)
		{
			displayContact(&(contact[i]));
			j++;
		}
	}displayContactFooter(j);
}

// searchContacts:
void searchContacts(const struct Contact contact[], int size)
{
	int i;
	char cellNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	i = findContactIndex(contact, size, cellNum);

	if (i >= 0 && i < size)
	{
		printf("\n");
		displayContact(&(contact[i]));
		printf("\n");
	}
	else
	{
		printf("*** Contact NOT FOUND ***");
		printf("\n\n");
	}

}

// addContact:
void addContact(struct Contact contacts[], int size)
{
	int i, available = -1;

	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 0)
		{
			available = i;
			break;
		}
	}
	if (available > -1)
	{
		getContact(&contacts[available]);
		printf("--- New contact added! ---\n\n");
	}
	else
	{
		printf("*** ERROR: The contact list is full! ***");
		printf("\n\n");
	}
}

// updateContact:
void updateContact(struct Contact contact[], int size)
{
	int myIndex;
	char phonenum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phonenum);

	myIndex = findContactIndex(contact, size, phonenum);
	if (myIndex == -1)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&(contact[myIndex]));
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		if (yes() == 1)
		{
			contact[myIndex].name.firstName[0] = '\0';
			contact[myIndex].name.middleInitial[0] = '\0';
			contact[myIndex].name.lastName[0] = '\0';
			getName(&(contact[myIndex].name));
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1)
		{

			getAddress(&(contact[myIndex].address));
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1)
		{
			contact[myIndex].numbers.cell[0] = '\0';
			contact[myIndex].numbers.home[0] = '\0';
			contact[myIndex].numbers.business[0] = '\0';

			getNumbers(&(contact)[myIndex].numbers);
		}
		printf("--- Contact Updated! ---\n\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contact[], int size)
{
	int myIndex;
	char cellNum[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	//searchContacts(contact, size, cellNum);
	myIndex = findContactIndex(contact, size, cellNum);

	if (myIndex == -1)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else printf("\nContact found:\n");
	displayContact(&(contact[myIndex]));
	printf("\n");
	printf("CONFIRM: Delete this contact? (y or n): ");
	if (yes() == 1)
	{
		contact[myIndex].numbers.cell[0] = '\0';
		contact[myIndex].numbers.home[0] = '\0';
		contact[myIndex].numbers.business[0] = '\0';
		printf("--- Contact deleted! ---\n\n");
	}
	else
		printf("\n");
}
// sortContacts:
// put function prototype here:
void sortContacts(struct Contact contacts[], int size) {
	printf("<<< Feature to sortis unavailable >>>\n");
}