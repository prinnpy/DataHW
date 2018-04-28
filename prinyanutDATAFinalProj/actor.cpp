/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: Oscar's Database final project
 Due Date: May 2 2018
 */

#include "actor.h"

//adding records for actor database (worked!)
void actorAdd(BSTree<ActorData, string> *actorTree) {
    
    //vars
    ActorData actor;
    string stringAward, stringName, stringFilm;
    int intYear = 0;
    char tempWinner;
    bool boolWinner;
    bool validYear = false;
    
    //ask for new year
    while (!validYear) {
        cout << "\nEnter new actor/actress year.\n";
        cin >> intYear;
        validYear = validNumbers();
    }
    
    //ask for new award
    cout << "Enter new actor/actress award.\n";
    cin.ignore();
    getline(cin, stringAward);
    
    //ask for new winner
    cout << "Enter new actor/actress Winner. (y or n)\n";
    cin >> tempWinner;
    tolower(tempWinner);
    if (tempWinner == 'y') {
        boolWinner = true;
    } else {
        boolWinner = false;
    }
    
    //ask for new name
    cout << "Enter new actor/actress name.\n";
    cin.ignore();
    getline(cin, stringName);
    
    //ask for new film
    cout << "Enter new actor/actress film.\n";
    getline(cin, stringFilm);
    
    //store into obj
    actor.year = intYear;
    actor.award = stringAward;
    actor.winner = boolWinner;
    actor.name = stringName;
    actor.film = stringFilm;
    
    //add to tree
    actorTree->addNode(actor.name, actor);
    
    actorTree->printActorInorder();

    
}

//Actor modify function (worked!)
void actorModify(BSTree<ActorData, string> *actorTree) {
    
    string name;
    
    //enter name
    cout << "\nEnter name of the record you want to modify\n";
    cin.ignore();
    getline(cin, name);
    
    //find the node
    Node<ActorData, string> *foundRecord = actorTree->findNode(name);
    if (foundRecord == nullptr) {
        cout << "Record not found!\n";
        return;
    }
    ActorData actor = foundRecord->Data();
    bool exit = false;
    
    //loop exit
    while (!exit) {
    
        bool validMenuInput = false;
        bool validYear = false;
        char menu = ' ';
        int newYear = 0;
        bool newWinner;
        char tempWinner;
        string newAward, newName, newFilm;
        
        //valid menu input
        while (!validMenuInput) {
            cout << "\nWhich field do you want to modify?\n";
            cout << "---------------------------------\n";
            cout << "Enter 0 to mofidy year\n";
            cout << "Enter 1 to modify award\n";
            cout << "Enter 2 to modify winner\n";
            cout << "Enter 3 to modify name\n";
            cout << "Enter 4 to modify film\n";
            cout << "Enter Q to go back to Actor database\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
            
        }//while
        
        switch (menu) {
            case '0':
                //change foundRecord year (worked)
                while (!validYear) {//enter year
                    cout << "Enter new year:\n";
                    cin >> newYear;
                    validYear = validNumbers();
                }
                actor.year = newYear;
                foundRecord->setData(actor); //set new data
                actorTree->printActorInorder();
                break;
            case '1':
                //change foundRecord award (worked)
                cout << "Enter new award:\n"; //enter award
                cin.ignore();
                getline(cin, newAward);
                actor.award = newAward;
                foundRecord->setData(actor); //set new data
                actorTree->printActorInorder();
                break;
            case '2':
                //change foundRecord winner (worked)
                cout << "Enter new winner (y for win or n for not win):\n"; //enter new winner
                cin >> tempWinner;
                tolower(tempWinner);
                if (tempWinner == 'y') {
                    newWinner = true;
                } else {
                    newWinner = false;
                }
                actor.winner = newWinner;
                foundRecord->setData(actor); //set new data
                actorTree->printActorInorder();
                break;
            case '3':
                //change foundRecord name (worked!)
                cout << "Enter new name:\n"; //enter new name
                cin.ignore();
                getline(cin, newName);
                actor.name = newName;
                //deleting the found node
                actorTree->deleteNode(foundRecord->Key());
                //add new node
                actorTree->addNode(newName, actor);
                actorTree->printActorInorder();
                break;
            case '4':
                //change foundRecord film (worked)
                cout << "Enter new film:\n"; //enter new film
                cin.ignore();
                getline(cin, newFilm);
                actor.film = newFilm;
                foundRecord->setData(actor); // set new data
                actorTree->printActorInorder();
                break;
            case 'Q':
                //exit program
                exit = true;
                break;
            default:
                //incorret
                cout << "Incorrect input. Try again!" << endl;
                break;
        }//switch
    
    }//while
    
}

//delete actor data (Worked!)
void actorDelete(BSTree<ActorData, string> *actorTree) {
    
    string name;
    
    //ask for name to delete
    cout << "\nEnter name of the record you want to delete: \n";
    cin.ignore();
    getline(cin, name);
    
    //find node
    Node<ActorData, string> *foundDeleteRecord = actorTree->findNode(name);
    if (foundDeleteRecord == nullptr) {
        cout << "Record not found!\n";
        return;
    }
    //delete found node
    actorTree->deleteNode(foundDeleteRecord->Key());
    //print new results
    actorTree->printActorInorder();
    
}

//function for resorting bst (worked!)
void actorSort(BSTree<ActorData, string> *actorTree) {
    
    bool exit = false;
    
    //loop exit
    while (!exit) {
        
        bool validMenuInput = false;
        char menu = ' ';
        vector<ActorData> yearVector;
        vector<ActorData> awardVector;
        vector<ActorData> filmVector;
        BSTree<ActorData, int> *yearTree = new BSTree<ActorData, int>;
        BSTree<ActorData, string> *awardTree = new BSTree<ActorData, string>;
        BSTree<ActorData, string> *filmTree = new BSTree<ActorData, string>;
        
        //valid menu input
        while (!validMenuInput) {
            cout << "\nWhich field do you want to resort this BST by?\n";
            cout << "----------------------------------------------\n";
            cout << "Enter 0 to sort by year\n";
            cout << "Enter 1 to sort by award\n";
            cout << "Enter 2 to sort by film\n";
            cout << "Enter Q to go back to Actor database\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
            
        }//while
        
        switch (menu) {
            case '0':
                //sort by year and print (worked!)
                bstToVector(actorTree->Root(), yearVector);
                
                //convert to new tree
                for (int i = 0; i < yearVector.size(); i++) {
                    yearTree->addNode(yearVector[i].year, yearVector[i]);
                }
                yearTree->printActorInorder();
                break;
            case '1':
                //sort by award and print (worked!)
                bstToVector(actorTree->Root(), awardVector);
                
                //convert to new tree
                for (int i = 0; i < awardVector.size(); i++) {
                    awardTree->addNode(awardVector[i].award, awardVector[i]);
                }
                awardTree->printActorInorder();
                
                break;
            case '2':
                //sort by film and print (worked!)
                bstToVector(actorTree->Root(), filmVector);
                
                //convert to new tree
                for (int i = 0; i < filmVector.size(); i++) {
                    filmTree->addNode(filmVector[i].film, filmVector[i]);
                }
                filmTree->printActorInorder();
                
                break;
            case 'Q':
                //exit program
                exit = true;
                break;
            default:
                //incorret
                cout << "Incorrect input. Try again!" << endl;
                break;
        }//switch
        
    }//while
    
    
}


//for sorting
void bstToVector(Node<ActorData, string> *actorNode, vector<ActorData> &v) {
    
    //check if it's empty
    if (actorNode == nullptr)
        return;
    
    //store data into vector
    bstToVector(actorNode->Left(), v);
    v.push_back(actorNode->Data());
    bstToVector(actorNode->Right(), v);
    
}

//function for a complete search (worked!)
void actorCompleteSearch(BSTree<ActorData, string> *actorTree) {
    
    bool exit = false;
    
    //exit loop
    while (!exit) {
        
        int year = 0;
        char menu = ' ';
        bool validMenuInput = false;
        bool validSearchAgain = false;
        bool validYear = false;
        string award, film, name;
        ActorData actor;
        char searchAgain = ' ';
        vector<ActorData> yearVector;
        vector<ActorData> awardVector;
        vector<ActorData> filmVector;
        vector<ActorData> foundCompleteYearVector;
        vector<ActorData> foundCompleteAwardVector;
        vector<ActorData> foundCompleteFilmVector;
        vector<ActorData> foundCompleteNameVector;
        BSTree<ActorData, int> *yearTree = new BSTree<ActorData, int>;
        BSTree<ActorData, string> *awardTree = new BSTree<ActorData, string>;
        BSTree<ActorData, string> *filmTree = new BSTree<ActorData, string>;
        
        //valid menu input
        while (!validMenuInput) {
            cout << "\nWhich field do you want to search this BST by?\n";
            cout << "----------------------------------------------\n";
            cout << "Enter 0 to complete search by year\n";
            cout << "Enter 1 to complete search by award\n";
            cout << "Enter 2 to complete search by name\n";
            cout << "Enter 3 to complete search by film\n";
            cout << "Enter Q to go back to Actor database\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
            
        }//while
        
        switch (menu) {
            case '0':
                //search by complete year (worked!)
                bstToVector(actorTree->Root(), yearVector);
                for (int i = 0; i < yearVector.size(); i++) {
                    yearTree->addNode(yearVector[i].year, yearVector[i]);
                }
                //enter year
                while (!validYear) {
                    cout << "\nEnter complete year:\n";
                    cin >> year;
                    validYear = validNumbers();
                }
                
                //find all search and put them in vector
                foundCompleteIntSearch(yearTree->Root(), foundCompleteYearVector, year);
                
                //print found searches
                cout << "\nWe've found " << foundCompleteYearVector.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteYearVector);
                } else {
                    printActorVector(foundCompleteYearVector);
                }
                
                
                break;
            case '1':
                //search by complete award (worked!)
                bstToVector(actorTree->Root(), awardVector);
                for (int i = 0; i < awardVector.size(); i++) {
                    awardTree->addNode(awardVector[i].award, awardVector[i]);
                }
                //enter award
                cout << "\nEnter complete award name:\n";
                cin.ignore();
                getline(cin, award);
                
                //find all search and put them in vector
                foundCompleteStringSearch(awardTree->Root(), foundCompleteAwardVector, award);
                
                //print found searches
                cout << "\nWe've found " << foundCompleteAwardVector.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteAwardVector);
                } else {
                    printActorVector(foundCompleteAwardVector);
                }
                
                break;
            case '2':
                
                //search by complete name (worked!)
                cout << "\nEnter complete name:\n";
                cin.ignore();
                getline(cin, name);
                
                //find all search and put them in vector
                foundCompleteStringSearch(actorTree->Root(), foundCompleteNameVector, name);
                
                //print found searches
                cout << "\nWe've found " << foundCompleteNameVector.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteNameVector);
                } else {
                    printActorVector(foundCompleteNameVector);
                }
                
                break;
            case '3':
                //search by complete film (worked!)
                bstToVector(actorTree->Root(), filmVector);
                for (int i = 0; i < filmVector.size(); i++) {
                    filmTree->addNode(filmVector[i].film, filmVector[i]);
                }
                //enter film
                cout << "\nEnter complete film name:\n";
                cin.ignore();
                getline(cin, film);
                
                //find all search and put them in vector
                foundCompleteStringSearch(filmTree->Root(), foundCompleteFilmVector, film);
                
                //print found searches
                cout << "\nWe've found " << foundCompleteFilmVector.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteFilmVector);
                } else {
                    printActorVector(foundCompleteFilmVector);
                }
                
                break;
            case 'Q':
                //exit program
                exit = true;
                break;
            default:
                //incorret
                cout << "Incorrect input. Try again!" << endl;
                break;
        }//switch
        
    }//while
}

void secondCompleteSearch(vector<ActorData> &v) {
    
    bool exit = false;
    
    //exit loop
    while (!exit) {
        
        int year = 0;
        char menu = ' ';
        bool validMenuInput = false;
        bool validInputPrint = false;
        bool validYear = false;
        string award, film, name;
        ActorData actor;
        char print = ' ';
        vector<ActorData> found2ndCompleteYearVector;
        vector<ActorData> found2ndCompleteAwardVector;
        vector<ActorData> found2ndCompleteFilmVector;
        vector<ActorData> found2ndCompleteNameVector;
        
        //valid menu input
        while (!validMenuInput) {
            cout << "\nWhich field do you want to second search this BST by?\n";
            cout << "----------------------------------------------\n";
            cout << "Enter 0 to complete second search by year\n";
            cout << "Enter 1 to complete second search by award\n";
            cout << "Enter 2 to complete second search by name\n";
            cout << "Enter 3 to complete second search by film\n";
            cout << "Enter Q to go back\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
            
        }//while
        
        switch (menu) {
            case '0':
                //second search by complete year (worked!)
                //enter year
                while (!validYear) {
                    cout << "\nEnter your second complete search for year\n";
                    cin >> year;
                    validYear = validNumbers();
                }
                
                //search again
                for (int i = 0; i < v.size(); i++) {
                    if (year == v[i].year) {
                        found2ndCompleteYearVector.push_back(v[i]);
                    }
                }
                
                //print found size
                cout << "\nWe've found " << found2ndCompleteYearVector.size() << " search(es)\n";
                
                //print input
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printActorVector(found2ndCompleteYearVector);
                } else {
                    return;
                }
                
                break;
            case '1':
                //second search by complete award (worked!)
                //enter award
                cout << "\nEnter your second complete search for award\n";
                cin.ignore();
                getline(cin, award);
                //seach again
                for (int i = 0; i < v.size(); i++) {
                    if (award == v[i].award) {
                        found2ndCompleteAwardVector.push_back(v[i]);
                    }
                }
                //print out size
                cout << "\nWe've found " << found2ndCompleteAwardVector.size() << " search(es)\n";
                
                //print input
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printActorVector(found2ndCompleteAwardVector);
                } else {
                    return;
                }
                
                break;
            case '2':
                //second search by complete name (worked!)
                //enter name
                cout << "\nEnter your second complete search for name\n";
                cin.ignore();
                getline(cin, name);
                //search again
                for (int i = 0; i < v.size(); i++) {
                    if (name == v[i].name) {
                        found2ndCompleteNameVector.push_back(v[i]);
                    }
                }
                //print new vector size
                cout << "\nWe've found " << found2ndCompleteNameVector.size() << " search(es)\n";
                
                //print input
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printActorVector(found2ndCompleteNameVector);
                } else {
                    return;
                }
                
                break;
            case '3':
                //second search by complete film (worked!)
                //enter film
                cout << "\nEnter your second complete search for film\n";
                cin.ignore();
                getline(cin, film);
                
                //search again
                for (int i = 0; i < v.size(); i++) {
                    if (film == v[i].film) {
                        found2ndCompleteFilmVector.push_back(v[i]);
                    }
                }
                //print new vector size
                cout << "\nWe've found " << found2ndCompleteFilmVector.size() << " search(es)\n";
                //print input
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                //print
                if (print == 'Y') {
                    printActorVector(found2ndCompleteFilmVector);
                } else {
                    return;
                }
                
                break;
            case 'Q':
                //exit program
                exit = true;
                break;
            default:
                //incorret
                cout << "Incorrect input. Try again!" << endl;
                break;
        }//switch
        
    }//while
    
}

//found search function and store them in a vector
void foundCompleteIntSearch(Node<ActorData, int> *actorNode, vector<ActorData> &v, int value) {
    //check for empty tree
    if (actorNode == nullptr)
        return;
    
    //go left
    foundCompleteIntSearch(actorNode->Left(), v, value);
    
    //check for match
    if (value == actorNode->Key()) {
        v.push_back(actorNode->Data());
    }
    
    //go right
    foundCompleteIntSearch(actorNode->Right(), v, value);
    
}

//found search function for strings
void foundCompleteStringSearch(Node<ActorData, string> *actorNode, vector<ActorData> &v, string value) {
    //check if empty
    if (actorNode == nullptr)
        return;
    
    //go left
    foundCompleteStringSearch(actorNode->Left(), v, value);
    
    //check for match
    if (value == actorNode->Key()) {
        v.push_back(actorNode->Data());
    }
    //go right
    foundCompleteStringSearch(actorNode->Right(), v, value);
}

//function for a complete search (worked!)
void actorPartialSearch(BSTree<ActorData, string> *actorTree) {
    
    bool exit = false;
    //exit loop
    while (!exit) {
        
        //vars
        int year = 0;
        char menu = ' ';
        char searchAgain = ' ';
        bool validMenuInput = false;
        bool validSearchAgain = false;
        bool validYear = false;
        //vars
        string award, film, name;
        ActorData actor;
        vector<ActorData> yearVector;
        vector<ActorData> awardVector;
        vector<ActorData> filmVector;
        vector<ActorData> foundPartialYearVector;
        vector<ActorData> foundPartialAwardVector;
        vector<ActorData> foundPartialFilmVector;
        vector<ActorData> foundPartialNameVector;
        BSTree<ActorData, int> *yearTree = new BSTree<ActorData, int>;
        BSTree<ActorData, string> *awardTree = new BSTree<ActorData, string>;
        BSTree<ActorData, string> *filmTree = new BSTree<ActorData, string>;
        
        //valid menu input
        while (!validMenuInput) {
            cout << "\nWhich field do you want to search this BST by?\n";
            cout << "----------------------------------------------\n";
            cout << "Enter 0 to partial search by year\n";
            cout << "Enter 1 to partial search by award\n";
            cout << "Enter 2 to partial search by name\n";
            cout << "Enter 3 to partial search by film\n";
            cout << "Enter Q to go back to Actor database\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
            
        }//while
        
        switch (menu) {
            case '0':
                //search by complete year (worked!)
                bstToVector(actorTree->Root(), yearVector);
                for (int i = 0; i < yearVector.size(); i++) {
                    yearTree->addNode(yearVector[i].year, yearVector[i]);
                }
                //enter year
                while (!validYear) {
                    cout << "\nEnter partial year:\n";
                    cin >> year;
                    validYear = validNumbers();
                }
                
                //find all search and put them in vector
                foundPartialIntSearch(yearTree->Root(), foundPartialYearVector, year);
                
                //print found searches
                cout << "\nWe've found " << foundPartialYearVector.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialYearVector);
                } else {
                    printActorVector(foundPartialYearVector);
                }
                
                break;
            case '1':
                //search by complete award (worked!)
                bstToVector(actorTree->Root(), awardVector);
                for (int i = 0; i < awardVector.size(); i++) {
                    awardTree->addNode(awardVector[i].award, awardVector[i]);
                }
                //enter award
                cout << "\nEnter partial award name:\n";
                cin.ignore();
                getline(cin, award);
                
                //find all search and put them in vector
                foundPartialStringSearch(awardTree->Root(), foundPartialAwardVector, award);
                
                //print found searches
                cout << "\nWe've found " << foundPartialAwardVector.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialAwardVector);
                } else {
                    printActorVector(foundPartialAwardVector);
                }
                
                break;
            case '2':
                
                //search by complete name (worked!)
                //enter name
                cout << "\nEnter partial name:\n";
                cin.ignore();
                getline(cin, name);
                
                //find all search and put them in vector
                foundPartialStringSearch(actorTree->Root(), foundPartialNameVector, name);
                
                //print found searches
                cout << "\nWe've found " << foundPartialNameVector.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialNameVector);
                } else {
                    printActorVector(foundPartialNameVector);
                }
                
                break;
            case '3':
                //search by complete film (worked!)
                bstToVector(actorTree->Root(), filmVector);
                for (int i = 0; i < filmVector.size(); i++) {
                    filmTree->addNode(filmVector[i].film, filmVector[i]);
                }
                //enter film
                cout << "\nEnter partial film name:\n";
                cin.ignore();
                getline(cin, film);
                
                //find all search and put them in vector
                foundPartialStringSearch(filmTree->Root(), foundPartialFilmVector, film);
                
                //print found searches
                cout << "\nWe've found " << foundPartialFilmVector.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialFilmVector);
                } else {
                    printActorVector(foundPartialFilmVector);
                }
                
                break;
            case 'Q':
                //exit program
                exit = true;
                break;
            default:
                //incorret
                cout << "Incorrect input. Try again!" << endl;
                break;
        }//switch
        
    }//while
}

//second partial search
void secondPartialSearch(vector<ActorData> &v) {
    
    bool exit = false;
    
    //exit loop
    while (!exit) {
        //vars
        int year = 0;
        char menu = ' ';
        bool validMenuInput = false;
        bool validInputPrint = false;
        bool validYear = false;
        string award, film, name, tempName, tempAward, tempFilm;
        ActorData actor;
        char print = ' ';
        vector<ActorData> found2ndPartialYearVector;
        vector<ActorData> found2ndPartialAwardVector;
        vector<ActorData> found2ndPartialFilmVector;
        vector<ActorData> found2ndPartialNameVector;
        
        //valid menu input
        while (!validMenuInput) {
            cout << "\nWhich field do you want to second search this BST by?\n";
            cout << "----------------------------------------------\n";
            cout << "Enter 0 to partial second search by year\n";
            cout << "Enter 1 to partial second search by award\n";
            cout << "Enter 2 to partial second search by name\n";
            cout << "Enter 3 to partial second search by film\n";
            cout << "Enter Q to go back\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
            
        }//while
        
        switch (menu) {
            case '0':
                //second search by partial year (worked!)
                //enter year
                while (!validYear) {
                    cout << "\nEnter your second partial search for year\n";
                    cin >> year;
                    validYear = validNumbers();
                }
                
                //search again
                for (int i = 0; i < v.size(); i++) {
                    if (to_string(v[i].year).find(to_string(year)) != string::npos) {
                        found2ndPartialYearVector.push_back(v[i]);
                    }
                }
                //print out new size
                cout << "\nWe've found " << found2ndPartialYearVector.size() << " search(es)\n";
                //print input
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                //print
                if (print == 'Y') {
                    printActorVector(found2ndPartialYearVector);
                } else {
                    return;
                }
                
                break;
            case '1':
                //second search by partial award (worked!)
                //enter award
                cout << "\nEnter your second partial search for award\n";
                cin.ignore();
                getline(cin, award);
                
                //search again
                for (int i = 0; i < v.size(); i++) {
                    if ((v[i].award).find(award) != string::npos) {
                        found2ndPartialAwardVector.push_back(v[i]);
                    }
                }
                //print new vec size
                cout << "\nWe've found " << found2ndPartialAwardVector.size() << " search(es)\n";
                
                //print input
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printActorVector(found2ndPartialAwardVector);
                } else {
                    return;
                }
                
                break;
            case '2':
                
                //second search by partial name (worked!)
                //enter name
                cout << "\nEnter your second partial search for name\n";
                cin.ignore();
                getline(cin, name);
                
                //search again
                for (int i = 0; i < v.size(); i++) {
                    if ((v[i].name).find(name) != string::npos) {
                        found2ndPartialNameVector.push_back(v[i]);
                    }
                }
                //print vec size
                cout << "\nWe've found " << found2ndPartialNameVector.size() << " search(es)\n";
                
                //print input
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printActorVector(found2ndPartialNameVector);
                } else {
                    return;
                }
                
                break;
            case '3':
                //second search by partial film (worked!)
                //enter film
                cout << "\nEnter your second partial search for film\n";
                cin.ignore();
                getline(cin, film);
                
                //search again
                for (int i = 0; i < v.size(); i++) {
                    if ((v[i].film).find(film) != string::npos) {
                        found2ndPartialFilmVector.push_back(v[i]);
                    }
                }
                
                //enter vec size
                cout << "\nWe've found " << found2ndPartialFilmVector.size() << " search(es)\n";
                
                //print input
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                //print
                if (print == 'Y') {
                    printActorVector(found2ndPartialFilmVector);
                } else {
                    return;
                }
                
                break;
            case 'Q':
                //exit program
                exit = true;
                break;
            default:
                //incorret
                cout << "Incorrect input. Try again!" << endl;
                break;
        }//switch
        
    }//while
}

//function for partial search int
void foundPartialIntSearch(Node<ActorData, int> *actorNode, vector<ActorData> &v, int value) {
    //check if empty
    if (actorNode == nullptr)
        return;
    //go left
    foundPartialIntSearch(actorNode->Left(), v, value);
    
    //check for partial match
    if (to_string(actorNode->Key()).find(to_string(value)) != string::npos) {
        v.push_back(actorNode->Data());
    }
    
    //go right
    foundPartialIntSearch(actorNode->Right(), v, value);
}

//function for partial search string
void foundPartialStringSearch(Node<ActorData, string> *actorNode, vector<ActorData> &v, string value) {
    //check if empty
    if (actorNode == nullptr)
        return;
    
    //go left
    foundPartialStringSearch(actorNode->Left(), v, value);
    
    //check for partial match
    if (actorNode->Key().find(value) != string::npos) {
        v.push_back(actorNode->Data());
    }
    
    //go right
    foundPartialStringSearch(actorNode->Right(), v, value);
}

//printing tree to a csv file (worked!)
void writeActorDatabase(BSTree<ActorData, string> *actorTree) {
    
    //open file
    ofstream inFile("new-actor-actress.csv");
    //convert bst to vector
    vector<ActorData> actorVector;
    bstToVector(actorTree->Root(), actorVector);
    
    //write first line
    inFile << "Year,Award,Winner,Name,Film\n";
    
    //write all nodes to file
    for (int i = 0; i < actorVector.size(); i++) {
        inFile << actorVector[i].year << "," <<  actorVector[i].award << "," <<  actorVector[i].winner << "," <<  actorVector[i].name << "," <<  actorVector[i].film << endl;
    }
    
    //success
    cout << "\nWrite file success!\n";
    
    //close file
    inFile.close();
    
}




