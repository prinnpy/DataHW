*******************************************************
*  Name      :  Prinn Prinyanut
*  Student ID:  103379393
*  Class     :  CSCI 2421
*  Due Date  :  Mar 29, 2018
*******************************************************


                      Read Me


*******************************************************
*  Description of the program
*******************************************************

This program reads in a list of customers from a file. Create a bank
simulation and print out the time each customer arrive and depart. It also
calculate how many customers and what was the average wait time.

*******************************************************
*  Source files
*******************************************************

Name: main.cpp
   Main program. This is the driver program that run bank simulation

Name: customer.h
   Contains the definition for the class Customer.

Name: function.h
   Contains functions prototypes.
    - overloading <
    - runSimulation

Name: function.cpp
   Function 1: overloading <
    - sorting queues based on time in ascending order
    - got steps from stack overflow, but I implemented it myself
   Function 2: runSimulation
    - read from file
    - enter info / calculations
    - print results

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode g++.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
