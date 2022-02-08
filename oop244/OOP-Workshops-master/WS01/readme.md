# Workshop #1: Modules   
 (V1.0)

In process of doing your first workshop, in the ***lab*** (part 1) you are to sub-divide a program into modules, compile each module separately and construct an executable from the results of each compilation. In ***DIY*** (part 2) you are to write a modular program based on your knowledge of ipc144 subject and basic C++ input and output objects (cin and cout). 

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:
- organize source code into modules, using header and implementation files;
- compile and link modular programs;
- distinguish the contents of a header and an implementation file;
- describe to your instructor what you have learned in completing this workshop.



## Submission Policy

The workshop is divided into two coding parts; part 1, **LAB** and part 2, **DIY**  and one non-coding part:

- ***LAB*** (part 1): worth 50% of the workshop's total mark, is due on **Wednesday at 23:59:59** of the week of your scheduled lab.
> Please note that the LAB (part 1) section is **not to be started in your lab session**. You should start it on your own before the day of your lab and and join the lab session to ask for help and correct your mistakes.
- ***DIY*** (part 2): worth 50% of the workshop's total mark, is due on **Sunday at 23:59:59** of the week of your scheduled lab.  Submissions of *DIY* part that do not contain the *reflection* are not considered valid submissions and are ignored.
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated to it, but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

If at the deadline the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

If the file contains only your work, or work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment are given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrong doing.


## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

# LAB (50%)
***50 top movies of all times "genre" search*** is a program that searches through 50 movies records that are saved in a file, based on the users inquiry on the genre of the movie.

For example if the user enters *Comedy*, the program lists all the movies with *Comedy* in their list of genres.

## LAB Execution example

```text
Welcome to 50 top movies of all times "genre" search.

Enter the movie genre to start the search: Anim<ENTER>
1- Finding Nemo [2003], G, duration: 100 minutes, Rating: 8.1/10
    (Animation, Adventure, Comedy)
Do another search? (Y)es: y<ENTER>

Enter the movie genre to start the search: Comedy<ENTER>
1- Life Is Beautiful [1997], PG, duration: 116 minutes, Rating: 8.6/10
    (Comedy, Drama, Romance)
2- The Intouchables [2011], 14A, duration: 112 minutes, Rating: 8.5/10
    (Biography, Comedy, Drama)
3- My Sassy Girl [2001], PG, duration: 137 minutes, Rating: 8/10
    (Comedy, Drama, Romance)
4- Back to the Future [1985], PG, duration: 116 minutes, Rating: 8.5/10
    (Adventure, Comedy, Sci-Fi)
5- Finding Nemo [2003], G, duration: 100 minutes, Rating: 8.1/10
    (Animation, Adventure, Comedy)
Do another search? (Y)es: n<ENTER>

Goodbye!
```


## Step 1: *Test the Program*

### On Visual Studio
- Open Visual studio 2019 and create an Empty C++ Windows Console Project:<br />
![Empty Project](images/emptyproj.png)
- In VS, (if not open already) open Solution Explorer (click on View/Solution Explorer) and then add w1p1.cpp file to your project:<br />
-Right click on **“Source Files”**<br />
-Select **“Add/Existing Item”**<br />
-Select **w1p1.cpp** from the file browser<br />
-Click on **“Ok”**
- Now you can run the program by selecting **“Debug/Start Without Debugging”** or pressing the **“Ctr-F5”** button. 
### On Linux, in your Matrix account
- Connect to Seneca with [Global Protect VPN](https://inside.senecacollege.ca/its/services/vpn/studentvpn.html)
- Upload **w1p1.cpp** and **movies.dat** to your matrix account (Ideally to a designated directory for your workshop solutions). Then, enter the following command to compile the source file and create an executable called ws:
```bash
g++ w1p1.cpp -Wall -std=c++11 -o ws<ENTER>

-Wall: display all warnings
-std=c++11: compile using C++11 standards
-o ws:  name the executable ws
```
- Type the following to run and test the execution:
```bash
ws<ENTER>
```
## Step 2: Create the Modules
### On Windows, using Visual Studio (VS)
In solution explorer, add three new modules to your project:
- 50Best; A module to hold the main() function and its relative functions. (see below)
- File; A module to hold the functions and global variables related to File processing.
- Movie; A module to hold movie functions and global variables which have no direct relation to the File analysis in the program.

The **50Best** module has an implementation (.cpp) file but no header file. The **File** and **Movie** modules have both implementation (.cpp) and header (.h) files:

- Add **File.h** and **Movie.h** to the “Header Files” directory (right click on “Header Files” and select “Add/New Item” and add a header file)<br />
Make sure you add the compilation safeguards and also have all the C++ code in **File** and **Movie** modules in a namespace called “sdds”.
> **Important**: Note that, you are not allowed to use the “using” statement in a header file.<br />
For example, in a header file you are not allowed to write:
```C++
using namespace std; // not allowed in a ".h" file
```
- **compilation safeguards** refer to a technique to guard against multiple inclusion of header files. It does so by applying macros that check against a defined name:
```C++
#ifndef NAMESPACE_HEADERFILENAME_H // replace with relevant names
#define NAMESPACE_HEADERFILENAME_H

// Your header file content goes here

#endif
```
If the name isn’t yet defined, the **#ifndef** will allow the code to proceed onward to then define that same name. Following that the header is then included. If the name is already defined, meaning the file has been included prior (otherwise the name wouldn’t have been defined), the check fails, the code proceeds no further and the header is not included again.<br />
Compilation safeguards prevent multiple inclusions of a header in a module. They do not protect against including the header again in a different module (remember that each module is compiled independently from other modules).<br />
Additionally, here is an instructional video showing how the compiler works and why you need these safeguards in all of your header files. Do note that this video describes the intent and concept behind safeguards, the naming scheme isn’t the standard for our class. Follow the standard for safeguards as described in your class.<br />
[Compilation Safegards](https://www.youtube.com/watch?v=EGak2R7QdHo): https://www.youtube.com/watch?v=EGak2R7QdHo

-Add **50Best.cpp**, **File.cpp** and **Movie.cpp** to the “Source Files” directory (right click on “Source Files” and select “Add/New Item” and add a C++ file)<br />

**50Best.cpp** Module should have only these include and namespace statements: 
```C++
#include <iostream>
#include "Movie.h"
using namespace std;
using namespace sdds;
```
and contain only the following functions:  
```Text
flushkeys
yes
main
```
- Separate the rest of the functions in **w1p1.cpp** and copy them into FILE and Movie modules as described below. Copy the body of the functions into the cpp files and the prototype into the header files. Note that the global variables must be in the cpp files to be kept invisible to other modules, but the structure difinitions must be kept in the header file to be visible to all the other modules using it<br />  
### Movie module
Contains the ***Movie*** Structure, the ***movies*** global array of **Movies** and the following functions:
```Text
loadMovies;
hasGenre;
displayMovie;
displayMoviesWithGenre;
```
### File Module
Contains the ***fptr*** FILE pointer as global variable and following functions
```Text
openFile
closeFile
readTitle
readYear
readMovieRating
readDuration
readGenres
readConsumerRating
```
To test that you have done this correctly, you can compile each module separately, by right clicking on **50Best.cpp**, **File.cpp** and **Movie.cpp** separately and select compile from the menu. If the compilation is successful, most likely you have done it correctly.

The equivalent of this on matrix is to add -c to the compile command:
```Bash
g++ File.cpp –Wall -std=c++11 –c<ENTER>
```
This example will only compile File.cpp and will not create an executable.

Now remove w1p1.cpp from the project. You can do this by right clicking on the filename in solution explorer and selecting remove in the menu (make sure you do not delete this file but only remove it).
Compile and run the project (as you did before in Step 1) and make sure everything works.

On Linux, in your matrix account, upload the five files from earlier (**File.cpp, File.h, Movie.cpp, Movie.h** and **50Best.cpp**) and **movies.dat** to your matrix account and compile the source code using the following command.
```Bash
g++ File.cpp Movie.cpp 50Best.cpp -Wall -std=c++11 -o ws<ENTER>
```
Run the program like before with the **movies.dat** file and make sure that everything still works properly. 

## LAB Submission (part 1)

To test and demonstrate execution of your program use the same data as shown in the [LAB Execution example](#LAB-Execution-example) .

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w1/p1
```
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.





# DIY (50%)

Seneca needs a program that can search for the main help telephone extension of each of its 24 schools in a text data file. 

The text data file is called **"schools.dat"** and is formatted like as follows:
  
```Text
3 to 5 Capital letter school code with no spaces
One Space
5 Digit integer extention number
New line
```
Example:
```Text
BSAC 65432
EMET 54541
FPET 34332
ITAS 11245
SDDS 24234
```
## DIY Execution example
```text
Seneca School Extension search.

Enter the School code: SDDS<ENTER>
416 491 5050 x 24234
Do another search? (Y)es: y<ENTER>

Enter the School code: FPET<ENTER>
416 491 5050 x 34332
Do another search? (Y)es: y<ENTER>

Enter the School code: ABC<ENTER>
ABC School code not found!
Do another search? (Y)es: n<ENTER>

Goodbye!
```

Implement a system in 3 modules called SchoolDir, File, School that can accomplish the above task.  

> you may freely use/copy any logic or code needed from the LAB section.

Files to submit:  
```Text
SchoolDir.cpp <--- contains the main function
File.cpp
File.h
School.cpp
School.h
```

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)

To test and demonstrate execution of your program use the same data as shown in the [DIY Execution example](#DIY-Execution-example).

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w1/p2
```
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
