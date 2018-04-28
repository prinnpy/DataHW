/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: Oscar's Database final project
 Due Date: May 2 2018
 */

#include "functions.h"

//read in actor/actress file into BST sorted by name
void readActorActressFile(BSTree<ActorData, string> *actorTree) {
    
    //open file
    fstream inFile("testactor.csv");
    
    //create temp
    string dummyLine, tempYear, stringAward, tempWinner, stringName, stringFilm;
    int intYear = 0;
    bool boolWinner;
    ActorData actor;
    
    //get first line
    getline(inFile, dummyLine);
    
    //get data from text file
    while (getline(inFile, tempYear, ',')) {
        
        //getline data
        getline(inFile, stringAward, ',');
        getline(inFile, tempWinner, ',');
        getline(inFile, stringName, ',');
        getline(inFile, stringFilm);
        
        //convert to true type
        intYear = stringToInt(tempYear);
        boolWinner = stringToBool(tempWinner);
        
        //store data into actor obj
        actor.year = intYear;
        actor.award = stringAward;
        actor.winner = boolWinner;
        actor.name = stringName;
        actor.film = stringFilm;
        
        //add to tree sorted by name
        actorTree->addNode(actor.name, actor);
        
    }
    
}

//read in pictures files in BST sorted by name
void readPicturesFile(BSTree<PictureData, string> *picturesTree) {
    
    //open file
    fstream inFile("testpictures.csv");
    
    //vars
    string dummyLine, stringName, tempYear, tempNominations, tempRating, tempDuration, stringGenre1, stringGenre2, stringRelease, tempMetacritic, stringSynopsis;
    int intYear, intNominations, intDuration, intMetacritic;
    double doubleRating;
    PictureData picture;
    
    //get first line
    getline(inFile, dummyLine);
    
    //loop for store data
    while (getline(inFile, stringName, ',')) {
        
        //getline info
        getline(inFile, tempYear, ',');
        getline(inFile, tempNominations, ',');
        getline(inFile, tempRating, ',');
        getline(inFile, tempDuration, ',');
        getline(inFile, stringGenre1, ',');
        getline(inFile, stringGenre2, ',');
        getline(inFile, stringRelease, ',');
        getline(inFile, tempMetacritic, ',');
        getline(inFile, stringSynopsis);
        
        //convert to true type
        intYear = stringToInt(tempYear);
        intNominations = stringToInt(tempNominations);
        intDuration = stringToInt(tempDuration);
        intMetacritic = stringToInt(tempMetacritic);
        doubleRating = stringToDouble(tempRating);
        
        //add to obj
        picture.name = stringName;
        picture.year = intYear;
        picture.nominations = intNominations;
        picture.rating = doubleRating;
        picture.duration = intDuration;
        picture.genre1 = stringGenre1;
        picture.genre2 = stringGenre2;
        picture.release = stringRelease;
        picture.metacritic = intMetacritic;
        picture.synopsis = stringSynopsis;
        
        //add node to tree
        picturesTree->addNode(picture.name, picture);
        
        
    }
    
    
}

//read in nominations files in BST sorted by name
void readNominationFile(BSTree<ActorData, string> *nominationsTree) {
    
    //open file
    fstream inFile("nominations.csv");
    
    //create temp
    string dummyLine, tempYear, stringAward, tempWinner, stringName, stringFilm;
    int intYear = 0;
    bool boolWinner;
    ActorData actor;
    
    //get first line
    getline(inFile, dummyLine);
    
    //get data from text file
    while (getline(inFile, tempYear, ',')) {
        
        //getline data
        getline(inFile, stringAward, ',');
        getline(inFile, tempWinner, ',');
        getline(inFile, stringName, ',');
        getline(inFile, stringFilm,',');
        
        //convert to true type
        intYear = stringToInt(tempYear);
        boolWinner = stringToBool(tempWinner);
        
        //store data into actor obj
        actor.year = intYear;
        actor.award = stringAward;
        actor.winner = boolWinner;
        actor.name = stringName;
        actor.film = stringFilm;
        
        //add to tree sorted by name
        nominationsTree->addNode(actor.name, actor);
        
    }
    
}

//actor/actress database
void actorDatabase(BSTree<ActorData, string> *actorTree) {
    bool exit = false;
    
    //start loop
    while (!exit) {
        
        bool validMenuInput = false;
        char menu = ' ';
        
        //valid menu
        while (!validMenuInput) {
            cout << "\nActor/Actress Database:\n";
            cout << "-----------------------\n";
            cout << "Enter 0 to add records\n";
            cout << "Enter 1 to modify records\n";
            cout << "Enter 2 to delete records\n";
            cout << "Enter 3 to sort records by data fields\n";
            cout << "Enter 4 to do a complete search\n";
            cout << "Enter 5 to do a partial search\n";
            cout << "Enter 6 to print the database\n";
            cout << "Enter Q to go back to main menu\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
        }
        
        switch (menu) {
            case '0':
                //call function add new actor record to tree
                actorAdd(actorTree);
                break;
            case '1':
                //call function that modify actor records
                actorModify(actorTree);
                break;
            case '2':
                //call function that deletes actor record
                actorDelete(actorTree);
                break;
            case '3':
                //call function that sort actor record based on field
                actorSort(actorTree);
                break;
            case '4':
                //call function that do a complete actor search based on selected field
                actorCompleteSearch(actorTree);
                break;
            case '5':
                //call function that do a partial actor search based on selected field
                actorPartialSearch(actorTree);
                break;
            case '6':
                //call function that prints actor database to a file
                writeActorDatabase(actorTree);
                break;
            case 'Q':
                //exit program
                exit = true;
                break;
            default:
                //invalid inputs
                cout << "Incorrect input. Try again!" << endl;
                break;
        }//switch
        
    }//while
    
}

//pictures database
void picturesDatabase(BSTree<PictureData, string> *picturesTree) {
    bool exit = false;
    
    //loop to exit
    while (!exit) {
        
        bool validMenuInput = false;
        char menu = ' ';
        
        //valid menu
        while (!validMenuInput) {
            cout << "\nPictures Database:\n";
            cout << "---------------------\n";
            cout << "Enter 0 to add records\n";
            cout << "Enter 1 to modify records\n";
            cout << "Enter 2 to delete records\n";
            cout << "Enter 3 to sort records by data fields\n";
            cout << "Enter 4 to do a complete search\n";
            cout << "Enter 5 to do a partial search\n";
            cout << "Enter 6 to print the database\n";
            cout << "Enter Q to go back to main menu\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
        }
        
        switch (menu) {
            case '0':
                //call function add new pictures record to tree
                picturesAdd(picturesTree);
                break;
            case '1':
                //call function that modify pictures records
                picturesModify(picturesTree);
                break;
            case '2':
                //call function that deletes pictures record
                picturesDelete(picturesTree);
                break;
            case '3':
                //call function that sort pictures record based on field
                picturesSort(picturesTree);
                break;
            case '4':
                //call function that do a complete pictures search based on selected field
                picturesCompleteSearch(picturesTree);
                break;
            case '5':
                //call function that do a partial pictures search based on selected field
                picturesPartialSearch(picturesTree);
                break;
            case '6':
                //call function that prints pictures database to a file
                writePicturesDatabase(picturesTree);
                break;
            case 'Q':
                //exit program
                exit = true;
                break;
            default:
                //invalid inputs
                cout << "Incorrect input. Try again!" << endl;
                break;
        }//switch
        
    }//while
    
}

//nomination database
void nominationsDatabase(BSTree<ActorData, string> *nominationsTree) {
    bool exit = false;
    
    //loop to exit
    while (!exit) {
        bool validMenuInput = false;
        char menu = ' ';
        
        //valid menu
        while (!validMenuInput) {
            cout << "\nNominations Database:\n";
            cout << "-----------------------\n";
            cout << "Enter 0 to print all winner in a given year\n";
            cout << "Enter 1 to print all actor in leading role who won\n";
            cout << "Enter 2 to print actor or actress has more total nominations\n";
            cout << "Enter 3 to print all movies that contain 'The'\n";
            cout << "Enter Q to go back to main menu\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
        }
        
        switch (menu) {
            case '0':
                //function that prints out all winner with a given year
                printWinner(nominationsTree);
                break;
            case '1':
                //function that prints all actor in leading role who won
                printWonActor(nominationsTree);
                break;
            case '2':
                //function that compare # of nominations between actor / actress
                ActorVSActressNominations(nominationsTree);
                break;
            case '3':
                //function that prints out all movies that starts with 'The'
                printTitleContainsThe(nominationsTree);
                break;
            case 'Q':
                //exit program
                exit = true;
                break;
            default:
                //invalid inputs
                cout << "Incorrect input. Try again!" << endl;
                break;
        }//switch
        
    }//while
}

