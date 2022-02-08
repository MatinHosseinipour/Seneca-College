/*
1.	List the 4 ways that we know that a transaction can be started

1- making a new connection to the server
2- using begin command
3- using commit command to commit the current transaction and start a new one
4- using ddl commands
*/

/*
2.	Using SQL, create an empty table, that is the same as the employees table, and name it newEmployees.
*/
create table newEmployees as select * from employees where 1=2;
select * from newemployees;

/*
3.	Execute the following commands.
*/
SET AUTOCOMMIT OFF;
SET TRANSACTION READ WRITE;

/*
4.	Write an INSERT statement to populate the newEmployees table with the rows of the sample data. 
Insert the NULL value for the reportsTo column. (Write a single INSERT statement to insert all the rows)
*/
insert into newemployees(employeenumber, lastname, firstname, extension, email, officecode, jobtitle) 
select employeenumber, lastname, firstname, extension, email, officecode, jobtitle
from employees;
select * from newemployees;

/*
5.	Create a query that shows all the inserted rows from the newEmployees table. How many rows are selected?

23
*/
select * from newemployees;

/*
6.	Execute the rollback command. Display all rows and columns from the newEmployees table. How many rows are selected?

null- nothing its empty
*/
ROLLBACK;
select * from newemployees;

/*
7.	Repeat Task 4. Make the insertion permanent to the table newEmployees. 
Display all rows and columns from the newEmployee table. How many rows are selected?

23
*/
insert into newemployees(employeenumber, lastname, firstname, extension, email, officecode, jobtitle) 
select employeenumber, lastname, firstname, extension, email, officecode, jobtitle
from employees;
commit;
select * from newemployees;

/*
8.	Write an update statement to update the value of column jobTitle to ‘unknown’ for all the employees in the newEmployees table.
*/
update newemployees
    set
        jobtitle = 'unknown';
select * from newemployees;

/*
9.	Make your changes permanent.
*/
commit;

/*
10.	Execute the rollback command. 
a.	Display all employees from the newEmployees table whose job title is ‘unknown’. How many rows are still updated?
b.	Was the rollback command effective?
c.	What was the difference between the result of the rollback execution from Task 6 and the result of the rollback execution of this task?

-----

a : 23
b : no because from the last commit command nothing had changed so basically rollback did nothing
c : in task 6 because we still had not commited by rollback we went to the first place where weve just created the table
but here since we used the command commit rollback could not really roll back because it was a new transaction;
*/
rollback;
select * from newemployees where jobtitle = 'unknown';

/*
11.	Begin a new transaction and then create a statement to delete to employees from the newEmployees table

when i use this command
begin transaction;
i get the following error
Encountered the symbol "end-of-file" when expecting one of the following:

   ( begin case declare end exception exit for goto if loop mod
   null pragma raise return select update while with
   <an identifier> <a double-quoted delimited-identifier>
   <a bind variable> << continue close current delete fetch lock
   insert open rollback savepoint set sql execute commit forall
   merge pipe purge
06550. 00000 -  "line %s, column %s:\n%s"
*Cause:    Usually a PL/SQL compilation error.
------------
therefore i will use commit command to terminated the last transaction and start a new one
*/
commit;
begin transaction;
delete from newemployees;

/*
12.	Create a VIEW, called vwNewEmps, that queries all the records in the newEmployees table sorted by last name and then by first name.
*/
create view vwNewEmps as
select * from newEmployees order by lastname, firstname;

/*
13.	Perform a rollback to undo the deletion of the employees
a.	How many employees are now in the newEmployees table?
b.	Was the rollback effective and why?

--
a : null - nothing it is empty
b : no it was not effective because we used a ddl(create) command and we know the fact that everytime we use a ddl command it will
automatically commit and begin a new transaction;
*/
rollback;
select * from vwNewEmps;

/*
14.	Begin a new transaction and rerun the data insertion from Task 4 (copy the code down to Task 14 and run it)

still does not work ' begin; '
*/
commit;
insert into newemployees(employeenumber, lastname, firstname, extension, email, officecode, jobtitle) 
select employeenumber, lastname, firstname, extension, email, officecode, jobtitle
from employees;

select * from newemployees;

/*
15.	Set a Savepoint, called insertion, after inserting the data
*/
savepoint insertion;

/*
16.	Rerun the update statement from Task 8 and run a query to view the data (copy the code down and run it again)
*/
update newemployees
    set
        jobtitle = 'unknown';
select * from newemployees;

/*
17.	Rollback the transaction to the Savepoint created in task 15 above and run a query to view the data.
What does the data look like (i.e. describe what happened?

----
it actually rolled before the ddl(update) command and that is because we manually saved a point for our roll back
just like the system restore point. if we had not save that point we could not roll back to that point because of the
ddl command
*/

rollback to insertion;
select * from vwNewEmps;

/*
18.	Use the basic for of the rollback statement and again view the data.  Describe what the results look like and what happened.

-----
because we have already rolled back before the update statement it shows our data the way it has to be (with job titles included (NOT UNKNOWN))
*/
rollback;
select * from vwNewEmps;

/*
19.	Write a statement that denies all access to the newemployees table for all public users
*/
revoke all on newemployees from public;

/*
20.	Write a statement that allows a classmate (use their database login) read only access to the newemployees table.
*/
grant read on newemployees to dbs211_202f41;

/*
21.	Write a statement that allows the same classmate to modify (insert, update and delete) the data of the newemployees table.
*/
grant insert,update,delete on newemployees to dbs211_202f41;

/*
22.	Write a statement the denies all access to the newemployees table for the same classmate.
*/
revoke all on newemployees from dbs211_202f41;

/*
23.	Write statements to permanently remove the view and table created for this lab
*/

drop table newEmployees;
drop view vwNewEmps;

