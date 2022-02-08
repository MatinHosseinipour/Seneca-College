/* -------------------------------------------
Name:   Matin Hosseini Pour
Student number: 151267192
Email:  smmhosseini-pour@myseneca.ca
Section:    NJJ
Date:   July 10th 2020
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

void getName(struct Name *name) {

    char yesNo;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    scanf("%c%*c", &yesNo);

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]%*c", name->middleInitial);
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

void getAddress(struct Address *address)
{
    char yesNo;

    do {
        printf("Please enter the contact's street number: ");
        scanf("%d%*c", &address->streetNumber);
    } while (address->streetNumber < 1);

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");
    scanf("%c%*c", &yesNo);
    if (yesNo == 'y' || yesNo == 'Y') {
        do {
            printf("Please enter the contact's apartment number: ");
            scanf("%d%*c", &address->apartmentNumber);
        } while (address->apartmentNumber < 1);
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]%*c", address->postalCode);

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

void getNumbers(struct Numbers *numbers)
{
    char yesNo;

    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf("%c%*c", &yesNo);

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's cell phone number: ");
        scanf("%10[^\n]%*c", numbers->cell);
    }

    printf("Do you want to enter a home phone number? (y or n): ");
    scanf("%c%*c", &yesNo);

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]%*c", numbers->home);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    scanf("%c%*c", &yesNo);

    if (yesNo == 'y' || yesNo == 'Y') {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]%*c", numbers->business);
    }
}
