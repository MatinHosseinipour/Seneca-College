//==============================================
// Name:           Matin Hosseini Pour
// Student Number: 151267192
// Email:          smmhosseini-pour@myseneca.ca
// Section:        NJJ
// Date:           July 31st
//==============================================
// Assignment:     2
// Milestone:      3
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-----------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2     |
// |        function definitions below...                |
// |                                                     |
// | HINT:  Update the getNumbers function to use the    |
// |        new helper function "getTenDigitPhone"       |
// |        where applicable                             |
// +-----------------------------------------------------+


#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"


// getName:
void getName(struct Name* name)
{


    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    if (yes() == 1) {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]%*c", name->middleInitial);
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{
    int value;
    printf("Please enter the contact's street number: ");

    value = getInt();
    while (value < 0) {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        value = getInt();
    }
    address->streetNumber = value;
    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);
    printf("Do you want to enter an apartment number? (y or n): ");
    if (yes() == 1) {
        printf("Please enter the contact's apartment number: ");
        value = getInt();
        while (value < 1) {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            value = getInt();
        }
        address->apartmentNumber = value;
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]%*c", address->postalCode);
    clearKeyboard();
    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    long number=0;
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(number);
    numbers->cell == number;

    printf("Do you want to enter a home phone number? (y or n): ");
    if (yes()) {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(number);
        numbers->home == number;
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    if (yes()) {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(number);
        numbers->business == number;
    }

}
void getContact(struct Contact* contact) {
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
