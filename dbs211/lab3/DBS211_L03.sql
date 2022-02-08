
/*
1.Display the data for all offices.
*/
SElECT * FROM offices;


/*
2.Display the employeenumberfor all employeeswhose office code is 1.
*/
SELECT * FROM EMPLOYEES WHERE OFFICECODE = 1;


/*
3.Display customer number, customername,contact first name and contact
last name, and phonefor all customers in Paris.(hint: be wary of case sensitivity
*/
SELECT CUSTOMERNUMBER, CUSTOMERNAME, CONTACTFIRSTNAME, CONTACTLASTNAME, PHONE FROM CUSTOMERS WHERE UPPER(CITY) = UPPER('PARIS');

/*
4.Repeat the previous Query with a couple small changes:
a.The contact’s first and last name should be in a single column in the format “lastname, firstname”.
b.Show customers who are in Canada
*/
SELECT CUSTOMERNUMBER, CUSTOMERNAME, CONTACTLASTNAME||' '||CONTACTFIRSTNAME, PHONE FROM CUSTOMERS WHERE UPPER(STATE) = UPPER('CA');

/*
5.Display customer numberfor customers who have payments.Do not included any repeated values. 
(hints: how do you know a customer has made a payment?You will need to access only one table for this query)
*/

SELECT DISTINCT CUSTOMERNUMBER From PAYMENTS ;

/*
6. List customer numbers, check number, and amount for customers whosepayment amountis not in the rangeof$30,000 to $65,000.
Sort the output by top payments amountfirst.
*/

SELECT DISTINCT customernumber,CHECKNUMBER, AMOUNT FROM PAYMENTS WHERE AMOUNT >= 30000 AND AMOUNT <= 65000 ORDER BY AMOUNT DESC;

/*
7. Display the order information for all orders that are cancelled.
*/

SELECT comments FROM ORDERS WHERE UPPER(status) = UPPER('CANCELLED');

/*
8.The company needs to know the percentage markup for each product sold. 
Produce a query that outputs the ProductCode, ProductName, BuyPrice, MSRP in addition to
a. The difference between MSRP and BuyPrice (i.e. MSRP-BuyPrice)called markup
b. The percentage markup (100 * calculated by difference / BuyPrice)called percmarkuproundedto 1 decimal place.
*/
SELECT productcode, productname, buyprice, msrp, (msrp-buyprice), ROUND((100* (msrp-buyprice)/buyprice), 1) FROM PRODUCTS;

/*
9. Display the information of all productswith string ‘co’in their product name.(c and o can be lower or upper case).
*/

SELECT productdescription FROM PRODUCTS where lower(productname) like '%co%';

/*
10. Display all customers whose contact first name starts with letter s(both lowercase and uppercase) and 
includes letter e(both lowercase and uppercase).
*/

SELECT contactfirstname FROM CUSTOMERS where lower(contactfirstname) like 's%e%';

/*
11. Create a statement that will insert yourself as an employee of the company.  
a.Use a unique employee number of your choice
b.Use your school email address
c.Your job title will be “Cashier”
d.Office code will be 4
e.You will report to employee 1088
*/
INSERT INTO EMPLOYEES VALUES (4848, 'HOSSEINI', 'MATIN', x01, 'smmhosseini-pour@myseneca.ca', 4, 1088, 'Cashier');

/*
12. Create a query that displays your, and only your, employee data
*/
SELECT * FROM EMPLOYEES WHERE employeenumber = 4848;

/*
13. Create a statement to update your job title to “Head Cashier”
*/

UPDATE EMPLOYEES SET JOBTITLE = 'HEAD Cashier' WHERE employeenumber = 4848;

/*
14. Create a statement to insert another fictional employee into the database.  
This employee will be a “Cashier” and will report to you.  
Make up fake data for the other fields.
*/

INSERT INTO EMPLOYEES VALUES (1035, 'GHADERI', 'ABBAS', x05, 'AB_GHAD@myseneca.ca', 5, 4848, 'Cashier');

/*
15.Create a statement to Delete yourself from the database.  Did it work?  If not, why?
*/

DELETE FROM EMPLOYEES WHERE employeenumber = 4848;

/*
No it did not because some other row is depended on this row
*/
/*
16. Create a statement to delete the fake employee from the database and 
then rerun the statement to delete yourself.  Did it work?
*/
DELETE FROM EMPLOYEES WHERE employeenumber = 1035;
DELETE FROM EMPLOYEES WHERE employeenumber = 4848;

/*
YES
*/

/*
17. Create a single statement that will insert both yourself and the fake employee at the same time. 
This time the fake employee will report to 1088 as well
*/

INSERT ALL
INTO EMPLOYEES VALUES (4848, 'HOSSEINI', 'MATIN', x01, 'smmhosseini-pour@myseneca.ca', 4, 1088, 'Cashier')
INTO EMPLOYEES VALUES (1035, 'GHADERI', 'ABBAS', x05, 'AB_GHAD@myseneca.ca', 5, 1088, 'Cashier')
SELECT * FROM dual;

/*
18. Create a singlestatement to delete both yourself and the fake employee.
*/

DELETE FROM EMPLOYEES WHERE employeenumber = 4848 AND employeenumber = 1035;
