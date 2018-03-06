*******************************************************
*  Name      :  Prinn Prinyanut
*  Student ID:  103379393
*  Class     :  CSCI 2421
*  Due Date  :  Feb. 15, 2018
*******************************************************


                      Read Me


*******************************************************
*  Description of the program
*******************************************************

This program searches specific make, model, or year based on user's input. 
Create a class called vehicle, that has make, model, and year as a private member functions. 
Build a vector that contains vehicle class. Before you search you have to sort by make, model and year
using overloading function. Then build 2 recursive search functions and
2 iterative search functions. 

*******************************************************
*  Source files
*******************************************************

Name: main.cpp
   Main program. This is the driver program that create a vector of Vehicle class.
   It reads in inputs from a text file. Then present a menu of search options.
   Case 1: recursive search by make
   Case 2: recursive search by model
   Case 3: recursive search by year
   Case 4: iterative search by make
   Case 5: iterative search by model
   Case 6: iterative search by year
   Case 7: Exit

Name: Vehicle.h
   Contains the definition for the class Vehicle.
   This vehicle class contains 3 private members: make, model, year.
   It also contains constructors for Vehicle, and set and get for all 
   private members.

Name: functions.h
   Contains all function prototypes.

Name: functions.cpp
   Function 1: read_file
    - read input form text files and put them in Vehicle objects
    - then put those opjects back into vector
   Function 2: sort_func
    - overloading sort function for make, model, year
   Function 3: swap
    - this is a part of sort function
    - use this when want to switch item's positions
   Function 4: print_found
    - when right index is found
    - print out the correct car info base on index number
   Function 5: BinSearchRec
    - take in user's target search
    - overloaded search function for model and make
    - return the correct index
    - Got algorithm help from geeksforgeeks.com
   Function 6: BinSearchRecYear
    - take in user's target search
    - overloaded recursive search function for year
    - return the correct index
    - Got algorithm help from geeksforgeeks.com
   Function 7: BinSearchIter
    - take in user's target search
    - overloaded iterative search function for model and make
    - return the correct index
    - Got algorithm help from geeksforgeeks.com
   Function 8: BinSearchIterYear
    - take in user's target search
    - overloaded iterative search function for year
    - return the correct index
    - Got algorithm help from geeksforgeeks.com

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode g++.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
