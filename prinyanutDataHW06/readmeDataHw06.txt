*******************************************************
*  Name      :  Prinn Prinyanut
*  Student ID:  103379393
*  Class     :  CSCI 2421
*  Due Date  :  Mar 8, 2018
*******************************************************


                      Read Me


*******************************************************
*  Description of the program
*******************************************************

Build a dictionary class that reads in a list of unsorted 
words into a <list> STL (which is an implementation of a doubly linked list.)
from a file called dictionary.txtPreview the document.  Use a list of dictionary
entries (DictEntry). Next, sort the list.  The list STL has a member 
function .sort which works when overloadeding the < operator for the data 
type you are sorting).  Now, read a list of words from a file called findwords.txt
Preview the document. For each word in findwords.txt, search that list from the 
beginning of the list and if found, print (to the screen) how many 
searches/comparisons you had to make to find the word. Then search from the back of 
the list and print how many searches you had to make.

*******************************************************
*  Source files
*******************************************************

Name: main.cpp
   Main program. This is the driver program that create a list from Dictionary class.
   - create a Dictionary object
   - loading in words from text files
   - sort dict list and print out list
   - print out find words list
   - compare find words to dict list from front
   - print out result
   - compare find words to dict list from back

Name: DictEntry.h
   Contains the definition for the class DictEntry. (Given)

Name: Dictionary.h
   Contains the definition for the class Dictionary.
   - contain 1 list of dictlist and 1 list of findwords
   - 5 prototypes for all member functions

Name: Dictionary.cpp
   Function 1: loadWords
    - for loop that load in dict list and find words list
   Function 2: printDictList
    - sort list
    - print out sorted dict list
   Function 3: printFindWords
    - print out find words
   Function 4: compareFromFront
    - nested for loop that compare find words list to dict list from front
    - print out result and count how many time it takes to find match words from front
   Function 5: compareFromBack
    - nested for loop that compare find words list to dict list from back
    - print out result and count how many time it takes to find match words from back

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode g++.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
