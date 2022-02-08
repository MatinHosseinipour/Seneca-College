SET AUTOCOMMIT ON; 
/*
1.	Create table the following tables and their given constraints:
L5_MOVIES (movieid:int, title:varchar(35), year:int, director:int,score:decimal(3,2))
*/
CREATE TABLE  L5_MOVIES  (
mid int PRIMARY KEY,
title varchar(35) NOT NULL,
year int NOT NULL,
director int NOT NULL,
score decimal(3,2),
CONSTRAINT score_chk CHECK (score BETWEEN 0 AND 5)
);
/*
L5_ACTORS (actorid:int, name:varchar(20), lastname:varchar(30))	
*/
CREATE TABLE  L5_ACTORS  (
aid int PRIMARY KEY,
name varchar(20) NOT NULL,
lastname varchar(30) NOT NULL
);
/*
L5_CASTINGS (movieid:int, actorid:int)
*/
CREATE TABLE L5_CASTINGS(
movieid int,
actorid int,
PRIMARY KEY(movieid, actorid),
CONSTRAINT movieid_fk FOREIGN KEY (movieid) REFERENCES l5_movies(mid),
CONSTRAINT actorid FOREIGN KEY (actorid) REFERENCES l5_actors(aid)
);
/*
L5_DIRECTORS(id:int, name:varchar(20), lastname:varchar(30))
*/
CREATE TABLE L5_DIRECTORS(
directorid int PRIMARY KEY,
firstname varchar(20) NOT NULL,
lastname varchar(30) NOT NULL
);
/*
2.	Modify the movies table to create a foreign key constraint that refers to table directors. 
*/
ALTER TABLE L5_MOVIES
    ADD CONSTRAINT director_fk FOREIGN KEY (director) REFERENCES L5_DIRECTORS(directorid);
/*
3.	Modify the movies table to create a new constraint so the uniqueness of the movie title is guaranteed. 
*/
ALTER TABLE L5_MOVIES
    ADD CONSTRAINT title_unq UNIQUE (title);
/*
4.	Write insert statements to add the following data to table directors and movies.

Director
directorid	First name	Last name
1010	Rob	Minkoff
1020	Bill	Condon
1050	Josh	Cooley
2010	Brad	Bird
3020	Lake	Bell
*/
INSERT ALL
    INTO L5_DIRECTORS (directorid, firstname, lastname) VALUES (1010, 'Rob', 'Minkoff')
    INTO L5_DIRECTORS (directorid, firstname, lastname) VALUES (1020, 'Bill', 'Condon')
    INTO L5_DIRECTORS (directorid, firstname, lastname) VALUES (1050, 'Josh', 'Cooley')
    INTO L5_DIRECTORS (directorid, firstname, lastname) VALUES (2010, 'Brad', 'Bird')
    INTO L5_DIRECTORS (directorid, firstname, lastname) VALUES (3020, 'Lake', 'Bell')
SELECT * FROM dual;
SELECT * FROM L5_DIRECTORS;
/*
Movies
id	title	year	director	score
100	The Lion King	2019	3020	3.50
200	Beauty and the Beast	2017	1050	4.20
300	Toy Story 4	2019	1020	4.50
400	Mission Impossible	2018	2010	5.00
500	The Secret Life of Pets	2016	1010	3.90
*/
INSERT ALL
    INTO L5_MOVIES (mid,title,year,director,score) VALUES (100, 'The Lion King', 2019, 3020, 3.50)
    INTO L5_MOVIES (mid,title,year,director,score) VALUES (200, 'Beauty and the Beast', 2017, 1050, 4.20)
    INTO L5_MOVIES (mid,title,year,director,score) VALUES (300, 'Toy Story 4', 2019, 1020, 4.50)
    INTO L5_MOVIES (mid,title,year,director,score) VALUES (400, 'Mission Impossible', 2019, 2010, 5.00)
    INTO L5_MOVIES (mid,title,year,director,score) VALUES (500, 'The Secret Life of Pets', 2016, 1010, 3.90)
SELECT * FROM dual;
/*
5.	Write SQL statements to remove all above tables. 
Is the order of tables important when removing? Why? 

YES order matters because tables are related to each other
in this case first child tables has to be droped in order to drop parent tables
here is the order
first castings because its primary keys are related to the movies and actors
after removing movies we can drop directors because its director id is being used in movies
*/
DROP TABLE L5_CASTINGS;
DROP TABLE L5_MOVIES;
DROP TABLE L5_ACTORS;
DROP TABLE L5_DIRECTORS;
/*
6.	Create a new empty table employee2 the same as table employees.  
Use a single statement to create the table and insert the data at the same time.
*/
CREATE TABLE employee2 AS (SELECT * FROM employees);
SELECT * FROM employee2;
/*
7.	Modify table employee2 and add a new column username to this table. 
The value of this column is not required and does not have to be unique.
----------
because usernames are usually string i will set it as varchar as long as it has not been
mentioned in the question and i will use the length of 15
*/
ALTER TABLE employee2
    ADD username varchar(15);
SELECT * FROM employee2;
/*
8.	Delete all the data in the employee2 table
*/
DELETE FROM employee2;
SELECT * FROM employee2;
/*
9.	Re-insert all data from the employees table into your new table employee2 using a single statement. 
----------------
this time i have to select the columns i want to be copied from 'employees' because username does not exist
in 'employees'
*/
INSERT INTO employee2(employeenumber, lastname, firstname, extension, email, officecode, reportsto, jobtitle)
    SELECT * FROM employees;
SELECT * FROM employee2;
/*
10.	In table employee2, write a SQL statement to change the first name and the last name of 
employee with ID 1002 to your name. 
*/
UPDATE employee2
SET
    firstname = 'Matin',
    lastname = 'Hosseini Pour'
WHERE
    employeenumber = 1002;
SELECT * FROM employee2;
/*
11.	In table employee2, generate the email address for column username for each student 
by concatenating the first character of employee’s first name and the employee’s last name. 
For instance, the username of employee Peter Stone will be pstone. NOTE: the username is in all lower case letters.  
*/
UPDATE employee2
SET 
    username =
LOWER
(
CONCAT
(SUBSTR(firstname,0,1), lastname)
);
SELECT * FROM employee2;
/*
12.	In table employee2, remove all employees with office code 4. 
*/
DELETE FROM employee2
WHERE 
    officecode = 4;
SELECT * FROM employee2;
/*
13.	Drop table employee2. 
*/
DROP TABLE employee2;