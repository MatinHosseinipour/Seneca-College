//==============================================
// Name:          
// Student Number:
// Email:          
// Section:        NJJ
// Workshop:       5 (at-home)
//==============================================



#define _CRT_SECURE_NO_WARNINGS
#define SIZE 4
struct employee {
	int ID;
	int age;
	float salary;
}employee;
#include <stdio.h>

// Define Number of Employees "SIZE" to be 2


// Declare Struct Employee 


/* main program */
int main(void)
{
	int option = 0;
	struct employee emp[SIZE] = { {0} };
	int count = 0;
	int i = 0, j = 0, x = 0, num1 = 0, num2 = 0;
	int changeSal, removeUser;
	int valid = 0;
	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero


	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!");
			break;

		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (x = 0; x < SIZE; x++)
			{
				if (emp[x].ID != 0)
				{
					printf("%6d%9d%11.2f\n", emp[x].ID, emp[x].age, emp[x].salary);
				}
			}
			printf("\n");

			break;

		case 2:	// Adding Employee
				// @IN-LAB

			count++;
			printf("Adding Employee\n");
			printf("===============\n");

			if (count > SIZE)
			{
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
				count--;
			}
			else {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[i].ID);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[i].age);
				printf("Enter Employee Salary: ");
				scanf("%f", &emp[i].salary);
				printf("\n");
			}
			// Check for limits on the array and add employee 
			// data accordingly. 
			//Adding Employee

			i++;


			break;

		case 3:
			printf("Update Employee Salary\n");
			printf("======================\n");
			
			if (count == 0)
			{
				printf("There is not any employee in our data base, first add an employee!\n");
				break;
			}
			else {
				printf("Enter Employee ID: ");
				scanf("%d", &changeSal);
				do {
					for (j = 0; j < SIZE; j++)
					{
						if (emp[j].ID == changeSal)
						{
							valid = 1;
							num1 = j;
						}
					}
					if (valid != 1)
					{
						printf("*** ERROR: Employee ID not found! ***\n");
						printf("Enter Employee ID: ");
						scanf("%d", &changeSal);
					}
				} while (valid == 0);
				printf("The current salary is ");
				printf("%0.2f\n", emp[num1].salary);
				printf("Enter Employee New Salary: ");
				scanf("%f", &emp[num1].salary);
				printf("\n");
				valid = 0;
				valid = 0;
			}
			

			break;

		case 4:
			printf("Remove Employee\n");
			printf("===============\n");
			printf("Enter Employee ID: ");
			scanf("%d", &removeUser);
			do {
				for (i = 0; i < SIZE; i++)
				{
					if (emp[i].ID == removeUser)
					{
						valid = 1;
						num2 = i;
					}
				}
				if (valid != 1)
				{
					printf("*** ERROR: Employee ID not found! ***\n");
					printf("Enter Employee ID: ");
					scanf("%d", &removeUser);
				}
			} while (valid == 0);
			printf("Employee %d will be removed\n\n", removeUser);
			emp[num2].ID = 0;
			i = num2;
			count--;
			valid = 0;

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}





// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements




// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 222
Enter Employee Age: 22
Enter Employee Salary: 22222.22

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 333
Enter Employee Age: 33
Enter Employee Salary: 33333.33

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 444
Enter Employee Age: 44
Enter Employee Salary: 44444.44

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 555
Enter Employee Age: 55
Enter Employee Salary: 55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   33333.33
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 123
*** ERROR: Employee ID not found! ***
Enter Employee ID: 321
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
The current salary is 33333.33
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   99999.99
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 789
*** ERROR: Employee ID not found! ***
Enter Employee ID: 987
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
Employee 333 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 666
Enter Employee Age: 66
Enter Employee Salary: 66666.66

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
666       66   66666.66
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
