*******************************************************
*  Name      :  Prinn Prinyanut
*  Student ID:  103379393
*  Class     :  CSCI 2421
*  Due Date  :  Feb. 22, 2018
*******************************************************


                      Read Me


*******************************************************
*  Description of the program
*******************************************************

Build my own vector class by redefining my MyVector class 
using dynamic memory allocation (dynamically allocating arrays).

*******************************************************
*  Source files
*******************************************************

Name: main.cpp
   Main program. This is the driver program that create a vector of MyVector class.
   - create a vector
   - check if the vec is empty by using .empty
   - print if it was empty or not
   - use .push_back
   - print out the all elements in the vec
   - use .pop_back
   - print out all update elements in the vec
   - use .search 
   - print if search was found or not

Name: MyVector.h
   Contains the definition for the class MyVector. (Given)

Name: MyVector.cpp
   Function 1: overloading operator []
    - check if index is bigger than size
   Function 2: pop_back
    - delete last item in vec
    - create a temp pointer
    - check if vec is empty
    - if not -1 from size then use temp ptr to point to new vec
   Function 3: push_back
    - add 1 item to the end of vec
    - check if vec is empty
    - is not +1 to size then set vec index-1 = value
   Function 4: empty
    - check if the vector is empty or not
    - return true or false
   Function 5: search
    - search if there's a specific item in that vec
    - linear search compare value to each item in vec
    - return true or false
    

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode g++.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
