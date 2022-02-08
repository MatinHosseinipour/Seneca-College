

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
.Display customer numberfor customers who have payments.Do not included any repeated values. (hints: how do you know a customer has made a payment?You will need to access only one table for this query)
*/



