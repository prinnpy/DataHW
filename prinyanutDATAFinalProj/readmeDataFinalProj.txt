*******************************************************
*  Name      :  Prinn Prinyanut
*  Student ID:  103379393
*  Class     :  CSCI 2421
*  Due Date  :  May 2, 2018
*******************************************************


                      Read Me


*******************************************************
*  Description of the program
*******************************************************

Develop a simple database system. The database is to handle multiple
records, each composed of several fields. The database will store its
information to a file, addition and deletion of records, field modifications,
and it will allow users to sort records based on the selected keys, and
produce reports according to predefined criteria.

*******************************************************
*  Source files
*******************************************************

Name: main.cpp
   Main program. This is the driver program that opens up menu
   for database selections.

Name: functions.h
    Contains functions prototypes

Name: functions.cpp
    function 1: readActorActressFile
        - read actor / actress files
        - store in bst sorted by name
    function 2: readPicturesFile
        - read picture files
        - store in bst sorted by name
    function 3: readNominationFile (EXTRA CREDIT!)
        - read nomination file
        - store in bst sorted by name
    function 4: actorDatabase
        - access actor database
    function 5: picturesDatabase
        - access picture database
    function 6: nominationsDatabase
        - access nominations database

Name: actor.h
    Contains actors function prototypes

Name: actor.cpp
    function 1: actorAdd
        - add new records
    function 2: actorModify
        - modify records
    function 3: actorDelete
        - delete records
    function 4: actorSort
        - sort by new keys
    function 5: bstToVector
        - convert bst to Vector
    function 6: actorCompleteSearch
        - complete search for records
    function 7: foundCompleteIntSearch
        - complete search for ints
    function 8: foundCompleteStringSearch
        - complete search for string
    function 9: secondCompleteSearch
        - compelte second search for records
    function 10: actorPartialSearch
        - partial search for records
    function 11: foundPartialIntSearch
        - partial search for ints
    function 12: foundPartialStringSearch
        - partial search for string
    function 13: secondPartialSearch
        - partial second search for records
    function 14: writeActorDatabase
        - write current database to a file

Name: pictures.h
    Contains pictures function prototypes

Name: pictures.cpp
    function 1: picturesAdd
        - add new records
    function 2: picturesModify
        - modify records
    function 3: picturesDelete
        - delete records
    function 4: picturesSort
        - sort by new keys
    function 5: bstToVector
        - convert bst to Vector
    function 6: picturesCompleteSearch
        - complete search for records
    function 7: foundCompleteIntSearch
        - complete search for ints
    function 8: foundCompleteStringSearch
        - complete search for string
    function 9: foundCompleteDoubleSearch
        - complete search for double 
    function 10: secondCompleteSearch
        - compelte second search for records
    function 11: picturesPartialSearch
        - partial search for records
    function 12: foundPartialIntSearch
        - partial search for ints
    function 13: foundPartialStringSearch
        - partial search for string
    function 14: foundPartialDoubleSearch
        - partial search for double
    function 15: secondPartialSearch
        - partial second search for records
    function 16: writePicturesDatabase
        - write current database to a file

Name: nominations.h (EXTRA CREDIT!)
    Contains nominatinos function prototypes

Name: nominations.cpp (EXTRA CREDIT!)
    function 1: printWinner
        - print all winner in a given year
    function 2: printWonActor
        - prints all actor in leading role who won
    function 3: ActorVSActressNominations
        - compare # of nominations between actor and actress
    function 4: printTitleContainsThe
        - print movies that contain 'The'

Name: extraFunctions.h
    Contains extra functions prototypes

Name: extraFunctions.cpp
    function 1: validMenu
        - menu validation
    function 2: validYOrN
        - valid print
    function 3: validNumbers
        - check if its numbers
    function 4: stringToBool
        - convert string to bool
    function 5: stringToInt
        - convert string to int
    function 6: stringToDouble
        - convert string to double
    function 7: printActorVector
        - print actor vector
    function 8: printPictureVector
        - print pictures vector
    
Name: BSTree.h (Given)
    Contains BSTree class and prototypes

Name: BSTree.hpp (Given)
    I fill in:
        - freeNode
        - addNode
        - findNode
        - printInorder

Name: Node.h (Given)
    Contains:
        - Actor struct
        - Pictures struct
        - Node class

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode g++.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
