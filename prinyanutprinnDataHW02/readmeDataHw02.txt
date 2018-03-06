*******************************************************
*  Name      :  Prinn Prinyanut
*  Student ID:  103379393
*  Class     :  CSCI 2421
*  Due Date  :  Feb. 8, 2018
*******************************************************


                      Read Me


*******************************************************
*  Description of the program
*******************************************************

Add function where combining the two objects into one set by
overloading the  + (union) operator, and print out the union set.
The + operator must remove all duplicates from the result and
store one copy of any item. Also implement a subtraction operator
 where A - B means removing all elements that are in B from A.
If the item is in B but not A, it is not placed in the result.
Then remove the duplicates from the result, and print out the subtracted set.

*******************************************************
*  Source files
*******************************************************

Name: main.cpp
   Main program. This is the driver program that create a 4 ArrayBag objects.
   Then it calls one of its method read_file, which read in data from a txt file.
   The program prints out obj1 and obj2. Next obj1 and obj2 are added using
   + operator. It prints out obj3. Then obj1 and obj2 are subtracted using + operator.
   The program prints out obj4.

Name: ArrayBag.h
   Contains the definition for the class ArrayBag.
   I added 4 functions
    - read_file function: read from text file then put data in objects
    - print_object: prints data
    - overloading + operator
    - overloading - operator

Name: ArrayBag.cpp
   Defines and implements the ArrayBag class for implementing a overloading operators logic.
   I added 4 functions to given files
    - read_file function: read from text file then put data in objects
      * I got the code that convert string to integer from stackoverflow
    - print_object: prints data
    - overloading + operator: adding integers and remove duplicates
      * I had logic help from Tate
    - overloading - operator: remove duplicates and any any data that obj1 and obj2 have in common
      * I had logic help from Tate


*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode g++.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
