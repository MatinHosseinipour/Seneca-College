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


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        contents below...                        |
// +-------------------------------------------------+


#include "contacts.h"


// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);

// pause:
// Put function prototype below:
void pause(void);

// getInt:
// Put function prototype below:
int getInt(void);

// getIntInRange:
// Put function prototype below:
int getIntInRange(int min, int max);

// yes:
// Put function prototype below:
int yes(void);

// menu:
// Put function prototype below:
int menu(void);

// contactManagerSystem:
// Put function prototype below:
void contactManagerSystem(void);








// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | NOTE:  Add new function prototypes as per the   |
// |        Milestone-3 specifications document      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);


// displayContactHeader
// put function prototype here:
void displayContactHeader(void);

// displayContactFooter:
// put function prototype here:
void displayContactFooter(int count);

// displayContact:
// put function prototype here:
void displayContact(const struct Contact* contact);

// displayContacts:
// put function prototype here:
void displayContacts(const struct Contact contacts[], int size);

// searchContacts:
// put function prototype here:
void searchContacts(const struct Contact contacts[], int size);

// addContact:
// put function prototype here:
void addContact(struct Contact contacts[], int size);

// updateContact:
// put function prototype here:
void updateContact(struct Contact contacts[], int size);

// deleteContact:
// put function prototype here:
void deleteContact(struct Contact contacts[], int size);

// sortContacts:
// put function prototype here:
void sortContacts(struct Contact contacts[], int size);