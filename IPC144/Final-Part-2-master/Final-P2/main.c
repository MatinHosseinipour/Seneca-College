/* DIGITAL SIGNATURE(S): MATIN_HP
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)Matin Hosseini Pour    smmhosseini-pour@myseneca.ca
   2)
   3)

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  S  U  M  M  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "file_helper.h"

void sort(struct SkierInfo data[], int Total) {
    int i, j;
    struct SkierInfo temp;

    for (i = Total - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (compare(data[j], data[j + 1]) > 0) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

double total_Time(struct SkierInfo skier) {
   return (skier.Time_Finished - skier.Time_Started);
}

void sectionByAgeGroup(int age) {
    if (age >= 16 && age <= 20) {
        printf("%9s", "Junior");
    }
    else if (age >= 21 && age <= 34){
       printf("%9s", "Adult");
    }
    else if (age >= 35) {
       printf("%9s", "Senior");
    }
    else {
        printf("%9s", "NOT_VALID");
    }
}

void displayTime(double time) {
   int h = (int) time;
   int m = round((time - h) * 60);
   printf("  %1d:%02d", h, m);
}

void displayCategory(char category) {
    if (category == 'S') {
        printf("%10s", "10 km");
    }
    else if (category == 'M') {
        printf("%10s", "25 km");
    }
    else if(category == 'L') {
      printf("%10s", "50 km");
    }
}

void printAll(char category, struct SkierInfo data[], int Total) {
    int i;

    printf("\n\nSkier                         Age Group  Time  withdrew\n");
    printf("-----------------------------------------------------------\n");

    for (i = 0; i < Total; i++) {
        // if skier has completed the course
        if (data[i].section == category) {
            printf("%-30s", data[i].name);
            sectionByAgeGroup(data[i].age);

            if (data[i].withdrawn == 0) {
                displayTime(total_Time(data[i]));
                printf("%10s\n", "NO");
            }
            else {
                printf("%6s", "N/A");
                printf("%10s\n", "YES");
            }
        }
    }
}

void printTop3(char category, struct SkierInfo data[] , int Total){
   int i, k=0;

   printf("\n\nSkier                         Age Group  Time\n");
   printf("-------------------------------------------------\n");

   for(i = 0; i < Total; i++) {
      if(data[i].withdrawn == 0 && data[i].section == category){
         printf("%-30s", data[i].name);
         sectionByAgeGroup(data[i].age);
         displayTime(total_Time(data[i]));
         printf("\n");
         k++;
         if (k == 3) {
             break;
         }
      }
   }

   if(k == 0) {
      printf("Not Awarded\n");
   }
}

void printLast3(char category, struct SkierInfo data[] , int Total){
   int i, k=0;
   struct SkierInfo last3[3];

   printf("\n\nSkier                         Age Group  Time\n");
   printf("-------------------------------------------------\n");

   for(i = Total-1; i >= 0 && k < 3; i--) {
      if(data[i].withdrawn == 0 && data[i].section == category){
         last3[k] = data[i];
         k++;
      }
   }

   if(k == 0) {
      printf("Not Awarded\n");
   } else {
      for (i = 0; i < k; i++) {
         printf("%-30s", last3[i].name);
         sectionByAgeGroup(last3[i].age);
         displayTime(total_Time(last3[i]));
         printf("\n");
      }
      
   }
}

void printAllWinners(struct SkierInfo data[], int Total) {
   char categories[] = {'S', 'M', 'L'};
   int i, j;
   int f ;

   printf("\n\nSkier                         Age Group  category  Time\n");
   printf("-----------------------------------------------------------\n");

   for(j=0; j<3; j++){
      f = 0;
      for(i = 0; i < Total; i++) {
         if(data[i].section == categories[j] && data[i].withdrawn == 0){
            f = 1;
            printf("%-30s", data[i].name);
            sectionByAgeGroup(data[i].age);
            displayCategory(data[i].section);
            displayTime(total_Time(data[i]));
            printf("\n");
            break;
         }
      }
      if(f == 0) {
         printf("%-30s", "Not Awarded");
         printf("%9s", "");
         displayCategory(categories[j]);
         printf("\n");
      }
   }
}

double compare(struct SkierInfo first, struct SkierInfo second) {
   if (first.withdrawn == 1)
      return 1;
      
   if (second.withdrawn == 1)
      return -1;

   return (total_Time(first) - total_Time(second));
}

char getCategory() {
    char option;

    printf("\nWhich category (S, M, L): ");
    scanf(" %c%*c", &option);
    option = toupper(option);

    while (option != 'S' || option != 'M' || option != 'L') {
        printf("*** OUT OF RANGE ***\n");
        printf("\nWhich category (S, M, L): ");
        scanf("%c%*c", &option);
    }

    return option;
}

int main(void)
{
	// TODO: Code the necessary logic for your solution below
	//
	// NOTE: Use modularity whenever possible in your design
	//
	// HINTS:
	// 1) You will need to load the file data and store
	//    it to a data structure array 
	//    (MUST USE: provided "readFileRecord" function)
	//
	// 2) Create a menu system to provide the user with
	//    the reporting options
	//
	// 3) Generate the user-selected report

   struct SkierInfo data[2000];
   int Total = 0;

   FILE *fp = NULL;

   fp = fopen("data.txt","r");
   if (fp == NULL) {
      printf("Failed to open file\n"); 
      return 0;
   }

   // Read all records
   while(!readFileRecord(fp, &data[Total])){
       Total++;
   }

   sort(data, Total);
   int select = 0;
   char category;
   printf("\nWhat would you like to do?\n");
   printf("-------------------------\n");
   printf("0 - Exit\n");
   printf("1 - Print top 3 skiers in a category\n");
   printf("2 - Print all skiers in a category\n");
   printf("3 - Print last 3 skiers in a category\n");
   printf("4 - Print winners in all categories\n");
   printf("\n");
   printf(": ");

   scanf("%d", &select);

   while (!(select >= 0 && select <= 4)) {
       printf("*** OUT OF RANGE ***\n");
       printf(": ");
       scanf("%d", &select);
   }
   printf("\n");
	do {
		switch (select)
		{
        case 1:
            category = getCategory();
            printTop3(category, data, Total);
            break;
        case 2:
            category = getCategory();
            printAll(category, data, Total);
            break;
        case 3:
            category = getCategory();
            printLast3(category, data, Total);
            break;
        case 4:
            printAllWinners(data, Total);
            break;
        }

	} while (select != 0);			

    printf("Keep on Skiing!");
    return 0;
}
