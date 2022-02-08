//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
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
    while(value > max || value < min){
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
            else if (yesNo == 'N' || yesNo == 'n'){
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
            printf("\n<<< Feature 1 is unavailable >>>\n\n");
            pause();
        }
        else if (value == 2) {
            printf("\n<<< Feature 2 is unavailable >>>\n\n");
            pause();
        }
        else if (value == 3) {
            printf("\n<<< Feature 3 is unavailable >>>\n\n");
            pause();
        }
        else if (value == 4) {
            printf("\n<<< Feature 4 is unavailable >>>\n\n");
            pause();
        }
        else if (value == 5) {
            printf("\n<<< Feature 5 is unavailable >>>\n\n");
            pause();
        }
        else if (value == 6) {
            printf("\n<<< Feature 6 is unavailable >>>\n\n");
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

