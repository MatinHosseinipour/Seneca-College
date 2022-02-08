/*
1.	Create a query that shows employee number, first name, last name, city, phone number and postal code for all employees in France.
a.	Answer this question using an ANSI-89 Join
*/
SELECT  employeenumber, firstname, lastname, o.city, o.phone || ' - ' || e.extension "PhoneNumber - ext", o.postalcode
FROM employees e, offices o 
WHERE o.officecode = 4;
/*
b.	Answer this question using an ANSI-92 Join
*/
SELECT  employeenumber, firstname, lastname, o.city, o.phone || ' - ' || e.extension "PhoneNumber - ext", o.postalcode
FROM employees e LEFT OUTER JOIN offices o
ON o.officecode = 4;

/*
2.	Create a query that displays all payments made by customers from Canada.  
a.	Sort the output by Customer Number.  
*/
SELECT c.customernumber, c.customername, c.state, c.country,  p.checknumber, p.paymentdate
FROM customers c INNER JOIN payments p ON c.country = 'Canada' ORDER BY c.customernumber;
/*
b.	Only display the Customer Number, Customer Name, Payment Date and Amount.  
*/
SELECT c.customernumber, c.customername, p.paymentdate, p.amount
FROM customers c INNER JOIN payments p ON c.country = 'Canada' ORDER BY c.customernumber;
/*
c.	Make sure the date is displayed clearly to know what date it is. (i.e. what date is 02-04-19??? – Feb 4, 2019,
April 2, 2019, April 19, 2002, ….)
*/
SELECT c.customernumber, c.customername, TO_CHAR(p.paymentdate, 'MON DD, YYYY'), p.amount
FROM customers c INNER JOIN payments p ON c.country = 'Canada' ORDER BY c.customernumber;
/*
3.	Create a query that shows all USA customers who have not made a payment.  Display only the 
customer number and customer name sorted by customer number.
*/
SELECT c.customernumber, c.customername
FROM customers c LEFT OUTER JOIN payments p 
ON c.country = 'USA' AND p.paymentdate = NULL
ORDER BY c.customernumber;
/*
4.	a) Create a view (vwCustomerOrder) to list all orders with the following data for all customers:  
Customer Number, Order number, order date, product name, quantity ordered, and price for each product in every order.
*/
CREATE VIEW vwCustomerOrder AS 
SELECT customernumber, ordernumber, orderdate, p.productname, quantityordered, priceeach
FROM orders JOIN orderdetails USING (ordernumber) LEFT OUTER JOIN products p 
ON orderdetails.productcode = p.productcode;
/*
b) Write a statement to view the results of the view just created.
*/
SELECT * FROM vwCustomerOrder;
/*
5.	Using the vwCustomerOrder  view, display the order information for customer number 124.
Sort the output based on order number and then order line number.
(Yes, I know orderLineNumber is not in the view)
*/
SELECT * FROM vwCustomerOrder v LEFT OUTER JOIN orderdetails o
ON v.ordernumber = o.ordernumber
WHERE customernumber = 124
ORDER BY v.ordernumber, orderlinenumber;
/*
6.	Create a query that displays the customer number, first name, last name,
phone, and credit limits for all customers who do not have any orders.
*/
SELECT c.customernumber, c.contactfirstname, c.contactlastname, c.phone, c.creditlimit
FROM customers c LEFT OUTER JOIN orders o 
ON  o.ordernumber = NULL;
/*
7.	Create a view (vwEmployeeManager) to display all information of all employees and the name
and the last name of their managers if there is any manager that the employee reports to.  
Include all employees, including those who do not report to anyone.
*/

CREATE VIEW vwEmployeeManager AS
SELECT employeenumber, jobtitle, lastname || ', ' || firstname Full_Name,
(CASE WHEN reportsto IS NULL THEN 'Head'
ELSE 
    (SELECT lastname || ', ' || firstname AS Manager_Name FROM employees e2 WHERE e1.reportsto = e2.employeenumber)
END) AS Manager
FROM employees e1;

/*
CREATE VIEW vwEmployeeManager AS
SELECT employeenumber, jobtitle, lastname || ', ' || firstname Full_Name, reportsto Manager,
(CASE WHEN reportsto = NULL THEN 'No Manager' 
ELSE lastname || ', ' || firstname END) AS Manager_Name
FROM employees;
------------------
CREATE VIEW vwEmployeeManager AS
SELECT * FROM employees e1 LEFT OUTER JOIN employees e2
ON e1.reportsto = e2.employeenumber;
------------------
CREATE VIEW vwEmployeeManager AS
SELECT employeenumber, reportsto FROM employees;*/
SELECT * from vwemployeemanager;
/*
8.	Modify the employee_manager view so the view returns only employee information 
for employees who have a manager. Do not DROP and recreate the view – modify it. 
(Google is your friend).
*/
/*Although you could DROP the view and the recreate it, there is an alternative using the CREATE OR REPLACE statement. week 4 le*/
CREATE OR REPLACE VIEW vwemployeemanager AS
SELECT employeenumber, jobtitle, lastname || ', ' || firstname Full_Name,
    (SELECT lastname || ', ' || firstname AS Manager_Name FROM employees e2 WHERE e1.reportsto = e2.employeenumber) Manager_Name
FROM employees e1 
WHERE reportsto is not null;

/*
9.	Drop both customer_order and employee_manager views. 
*/
DROP VIEW vwemployeemanager;
DROP VIEW vwCustomerOrder;