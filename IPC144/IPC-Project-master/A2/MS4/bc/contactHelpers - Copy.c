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
#include "contactHelpers.h"
#include "contacts.h"
#include <string.h>


#define MAXCONTACTS 5
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        contents below...                        |
// +-------------------------------------------------+



// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void) {
    printf("(Press Enter to Continue)");
    clearKeyboard();
}


// getInt function definition goes here:
int getInt(void) {
    char NL = 'x';
    int value;
    while (NL != '\n') {
        scanf("%d%c", &value, &NL);
        if (NL != '\n')
        {
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            clearKeyboard();
        }

    }
    return value;
}


// getIntInRange function definition goes here:
int getIntInRange(int min, int max) {
    int value = getInt();
    while (value > max || value < min) {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        value = getInt();
    }
    return value;
}


// yes function definition goes here:
int yes(void) {
    /*char NL = 'x';
    char yesNo = '\0';
    clearKeyboard();
    while (yesNo != 'Y' && yesNo != 'y' && yesNo != 'N' && yesNo != 'n') {
        while (NL != '\n') {
            scanf("%c%c", &yesNo, &NL);
            clearKeyboard();
            if (NL != '\n')
            {
                printf("*** INVALID INTEGER *** <Please enter an integer>: ");
                clearKeyboard();
            }
            clearKeyboard();
        }
        if (yesNo != 'Y' && yesNo != 'y' && yesNo != 'N' && yesNo != 'n')
        {
            clearKeyboard();
        }
        clearKeyboard();
    }
    if (yesNo == 'y' || yesNo == 'Y') {
        clearKeyboard();
        return "1";
    }
    else {
        clearKeyboard();
        return "0";
    }
    */

    char yesNo;
    char NL;
    while (1) {
        scanf("%c%c", &yesNo, &NL);
        if (NL == '\n') {
            if (yesNo == 'Y' || yesNo == 'y')
            {
                return 1;
            }
            else if (yesNo == 'N' || yesNo == 'n') {
                return 0;
            }
        }
        else {
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            clearKeyboard();
            continue;
            yes();
        }
    }
}


// menu function definition goes here:
int menu(void) {
    int value;
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
    value = getIntInRange(0, 6);
    return value;
}


// contactManagerSystem function definition goes here:
void contactManagerSystem(void) {
    struct Contact contacts[MAXCONTACTS] = { 
        { 
            { "Rick", {'\0'}, "Grimes"},
            { 11, "Trailer Park", 0, "A7A 2J2", "King City"},
            { "4161112222", "4162223333", "4163334444"} 
        },
        { 
            { "Maggie", "R.", "Greene"},
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton"},
            { "9051112222", "9052223333", "9053334444"} 
        },
        { 
            { "Morgan", "A.", "Jones"},
            { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough"},
            { "7051112222", "7052223333", "7053334444"} 
        },
        { 
            { "Sasha", {'\0'}, "Williams"},
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton"},
            { "9052223333", "9052223333", "9054445555"} 
        }, 
    };
    int value;
    value = menu();
    /*switch (value)
    {
    case 0:
        printf("Exit the program? (Y)es/(N)o: ");
        if (yes() == 1) {
            printf("Contact Management System: terminated\n");
            value = 7;
            break;
        }
        else {
            value = 8;
        }
        break;
    case 1:
        printf("\n<<< Feature 1 is unavailable >>>\n\n");
        pause();
        break;
    case 2:
        printf("\n<<< Feature 2 is unavailable >>>\n\n");
        pause();
        break;
    case 3:
        printf("\n<<< Feature 3 is unavailable >>>\n\n");
        pause();
        break;
    case 4:
        printf("\n<<< Feature 4 is unavailable >>>\n\n");
        pause();
        break;
    case 5:
        printf("\n<<< Feature 5 is unavailable >>>\n\n");
        pause();
        break;
    case 6:

        break;
    default:
        break;
    }*/
    if (value == 1) {
        displayContacts(contacts, MAXCONTACTS);
        pause();
    }
    else if (value == 2) {
        addContact(contacts, MAXCONTACTS);
        pause();
    }
    else if (value == 3) {
        updateContact(contacts, MAXCONTACTS);
        pause();
    }
    else if (value == 4) {
        deleteContact(contacts, MAXCONTACTS);
        pause();
    }
    else if (value == 5) {
        searchContacts(contacts, MAXCONTACTS);
        pause();
    }
    else if (value == 6) {
        sortContacts(contacts, MAXCONTACTS);
        pause();
    }
    else if (value == 0) {
        printf("\nExit the program? (Y)es/(N)o: ");
        if (yes() == 1) {
            printf("\nContact Management System: terminated\n");
            return;
        }
    }
    printf("\n");
    contactManagerSystem();
}






// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(long phoneNum)
{
    int needInput = 1;

    while (needInput == 1)
    {
        scanf("%10[0-9]", &phoneNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (phoneNum >= 100000000)
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
    int i, ln = -1;

    for (i = 0; ln == -1 && i < size; i++) {
        if (strcmp(contacts->numbers.cell, cellNum) == 0) {
            ln = i;
        }
        else {
            contacts++;
        }
    }
    return ln;
}


// displayContactHeader
// put function prototype here:
void displayContactHeader(void) {
    printf("+----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+----------------------------------------------------------------------------+\n");
}

// displayContactFooter:
// put function prototype here:
void displayContactFooter(int count) {
    printf("+----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", count);
}

// displayContact:
// put function prototype here:
void displayContact(const struct Contact* contact) {
    printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    printf("    C: %-10s   H: %-10s   B: %-10s\n",contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    printf("       %d %s, ",contact->address.streetNumber, contact->address.street);
    if (contact->address.apartmentNumber > 0)
    {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }
    printf("%s, %s\n",contact->address.city, contact->address.postalCode);
}

// displayContacts:
// put function prototype here:
void displayContacts(const struct Contact contacts[], int size) {
    displayContactHeader();
    int i = 0, count = 0, ln;
    for (i = 0; i < size; i++)
    {
        ln = strlen(contacts[i].numbers.cell);
        if (ln > 0)
        {
            displayContact(&(contacts[i]));
            count++;
        }
    }
    /*for (i = 0; i < size; i++)
    {
        if (contacts[i].numbers.cell > 0)
        {
            displayContact(contacts, i);
            count++;
        }
    }*/
    displayContactFooter(count);
}

// searchContacts:
// put function prototype here:
void searchContacts(const struct Contact contacts[], int size) {
    long num = 0;
    int x = 0;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(num);
    x = findContactIndex(contacts, size, num);
    if (x != 0)
    {
        displayContact(&(contacts[x]));
    }
    else {
        printf("*** Contact NOT FOUND ***\n");
    }

}

// addContact:
// put function prototype here:
void addContact(struct Contact contacts[], int size) {
    int num = 0;
    int found = 0;
    found = findContactIndex(contacts, size, num);
    if (found > 0)
    {
        getContact(&contacts[found]);
        printf("--- New contact added! ---\n\n");
    }
    else {
        printf("*** ERROR: The contact list is full! ***\n");
    }
}

// updateContact:
// put function prototype here:
void updateContact(struct Contact contacts[], int size) {
    long num = 0;
    int found = 0;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(num);
    found = findContactIndex(contacts, size, num);
    if (found != 0)
    {
        printf("\nContact found:\n");
        displayContact(&(contacts[found]));
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
        if (yes())
        {
            getName(&(contacts[found]));
        }
        else {
            printf("Do you want to update the address? (y or n): ");
            if (yes())
            {
                getAddress(&(contacts[found]));
            }
            else {
                printf("Do you want to update the numbers? (y or n): ");
                if (yes())
                {
                    getNumbers(&(contacts[found]));
                }
            }
        }
        printf("--- Contact Updated! ---\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n");
    }
}

// deleteContact:
// put function prototype here:
void deleteContact(struct Contact contacts[], int size) {
    long num = 0;
    int found = 0;
    getTenDigitPhone(num);
    found = findContactIndex(contacts,size,num);
    if (found != 0)
    {
        printf("\nContact found:\n");
        displayContact(&(contacts[found]));
        printf("CONFIRM: Delete this contact? (y or n): ");
        if (yes())
        {
            contacts->numbers.cell == 0;
            contacts->name.firstName == "";
            printf("---Contact deleted! ---\n");
        }

    }
    else {
        printf("*** Contact NOT FOUND ***\n");
    }
}

// sortContacts:
// put function prototype here:
void sortContacts(struct Contact contacts[], int size) {
    printf("<<< Feature to sortis unavailable >>>\n");
}
