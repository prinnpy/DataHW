/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: Oscar's Database final project
 Due Date: May 2 2018
 */

//include
#include "pictures.h"

//adding records for actor database (worked! done)
void picturesAdd(BSTree<PictureData, string> *picturesTree) {
    
    //create obj
    PictureData pictures;
    
    //vars
    string stringGenre1, stringGenre2, stringName, stringRelease, stringSynopsis;
    int intYear = 0, intNominations = 0, intDuration = 0, intMetacritic = 0;
    double doubleRating = 0.0;
    bool validYear = false;
    bool validNominations = false;
    bool validDuration = false;
    bool validMetacritic = false;
    bool validRating = false;
    
    //ask for new name
    cout << "\nEnter new pictures name:\n";
    cin.ignore();
    getline(cin, stringName);
    
    //ask for new year
    while (!validYear) {
        cout << "Enter new pictures year:\n";
        cin >> intYear;
        validYear = validNumbers();
    }
    
    //ask for new nominations
    while (!validNominations) {
        cout << "Enter new pictures nominations:\n";
        cin >> intNominations;
        validNominations = validNumbers();
    }
    
    //ask for new rating
    while (!validRating) {
        cout << "Enter new pictures rating:\n";
        cin >> doubleRating;
        validRating = validNumbers();
    }
    
    //ask for new duration
    while (!validDuration) {
        cout << "Enter new pictures durations:\n";
        cin >> intDuration;
        validDuration = validNumbers();
    }
    
    //ask for genre 1
    cout << "Enter new pictures genre 1:\n";
    cin.ignore();
    getline(cin, stringGenre1);
    
    //ask for genre 2
    cout << "Enter new pictures genre 2:\n";
    getline(cin, stringGenre2);
    
    //ask for new release month
    cout << "Enter new pictures release month:\n";
    getline(cin, stringRelease);
    
    //ask for new metacritic
    while (!validMetacritic) {
        cout << "Enter new pictures metacritic scores:\n";
        cin >> intMetacritic;
        validMetacritic = validNumbers();
    }
    
    //ask for new synopsis
    cout << "Enter new pictures synopsis:\n";
    cin.ignore();
    getline(cin, stringSynopsis);
    
    //add to obj
    pictures.name = stringName;
    pictures.year = intYear;
    pictures.nominations = intNominations;
    pictures.rating = doubleRating;
    pictures.duration = intDuration;
    pictures.genre1 = stringGenre1;
    pictures.genre2 = stringGenre2;
    pictures.release = stringRelease;
    pictures.metacritic = intMetacritic;
    pictures.synopsis = stringSynopsis;
 
    //add to picture tree
    picturesTree->addNode(pictures.name, pictures);
    
    //print out the result
    picturesTree->printPicturesInorder();
    
    
}

//function to modify search (worked! done)
void picturesModify(BSTree<PictureData, string> *picturesTree) {
    
    string name;
    
    //enter name of records to modify
    cout << "\nEnter name of the record you want to modify\n";
    cin.ignore();
    getline(cin, name);
    
    //find ndoe
    Node<PictureData, string> *foundRecord = picturesTree->findNode(name);
    if (foundRecord == nullptr) {
        cout << "Record not found!\n";
        return;
    }
    //set found node to obj
    PictureData picture = foundRecord->Data();
    
    bool exit = false;
    
    //loop to exit
    while (!exit) {
        
        //vars
        bool validMenuInput = false;
        bool validYear = false;
        bool validNominations = false;
        bool validDuration = false;
        bool validMetacritic = false;
        bool validRating = false;
        char menu = ' ';
        string newName, newGenre1, newGenre2, newRelease, newSynopsis;
        int newYear = 0, newNominations = 0, newDuration = 0, newMetacritic = 0;
        double newRating = 0.0;
        
        //valid menu input
        while (!validMenuInput) {
            cout << "\nWhich field do you want to modify?\n";
            cout << "---------------------------------\n";
            cout << "Enter 0 to mofidy name\n";
            cout << "Enter 1 to modify year\n";
            cout << "Enter 2 to modify nominations\n";
            cout << "Enter 3 to modify rating\n";
            cout << "Enter 4 to modify duration\n";
            cout << "Enter 5 to modify genre 1\n";
            cout << "Enter 6 to modify genre 2\n";
            cout << "Enter 7 to modify release month\n";
            cout << "Enter 8 to modify metacritic\n";
            cout << "Enter 9 to modify synopsis\n";
            cout << "Enter Q to go back to Actor database\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
            
        }//while
        
        switch (menu) {
            case '0': //change foundRecord name (worked!)
                //enter name
                cout << "Enter new name:\n";
                cin.ignore();
                getline(cin, newName);
                picture.name = newName;
                picturesTree->deleteNode(foundRecord->Key()); //delete found node
                picturesTree->addNode(newName, picture); //add new node
                //picturesTree->printPicturesInorder();
                break;
            case '1'://change foundRecord year (worked!)
                //enter year
                while (!validYear) {
                    cout << "Enter new year:\n";
                    cin >> newYear;
                    validYear = validNumbers();
                }
                picture.year = newYear;
                foundRecord->setData(picture); //set node to new value
                //picturesTree->printPicturesInorder();
                break;
            case '2'://change foundRecord nominations (worked!)
                //enter nominations
                while (!validNominations) {
                    cout << "Enter new nominations:\n";
                    cin >> newNominations;
                    validNominations = validNumbers();
                }
                picture.nominations = newNominations;
                foundRecord->setData(picture); //set node to new value
                //picturesTree->printPicturesInorder();
                break;
            case '3': //change foundRecord rating (worked!)
                //enter rating
                while (!validRating) {
                    cout << "Enter new rating:\n";
                    cin >> newRating;
                    validRating = validNumbers();
                }
                picture.rating = newRating;
                foundRecord->setData(picture); //set node to new value
                //picturesTree->printPicturesInorder();
                break;
            case '4': //change foundRecord duration (worked!)
                //enter duration
                while (!validDuration) {
                    cout << "Enter new duration:\n";
                    cin >> newDuration;
                    validDuration = validNumbers();
                }
                picture.duration = newDuration;
                foundRecord->setData(picture); //set node to new value
                //picturesTree->printPicturesInorder();
                break;
            case '5'://change foundRecord genre 1 (worked!)
                //enter genre 1
                cout << "Enter new genre 1:\n";
                cin.ignore();
                getline(cin, newGenre1);
                picture.genre1 = newGenre1;
                foundRecord->setData(picture); //set node to new value
                //picturesTree->printPicturesInorder();
                break;
            case '6': //change foundRecord genre 2 (worked!)
                //enter genre 2
                cout << "Enter new genre 2:\n";
                cin.ignore();
                getline(cin, newGenre2);
                picture.genre2 = newGenre2;
                foundRecord->setData(picture); //set node to new value
                //picturesTree->printPicturesInorder();
                break;
            case '7': //change foundRecord release month (worked!)
                //enter release month
                cout << "Enter new release month:\n";
                cin.ignore();
                getline(cin, newRelease);
                picture.release = newRelease;
                foundRecord->setData(picture); //set node to new value
                //picturesTree->printPicturesInorder();
                break;
            case '8': //change foundRecord metacritic (worked!)
                //enter metacritic
                while (!validMetacritic) {
                    cout << "Enter new metacritic:\n";
                    cin >> newMetacritic;
                    validMetacritic = validNumbers();
                }
                picture.metacritic = newMetacritic;
                foundRecord->setData(picture); //set node to new value
                //picturesTree->printPicturesInorder();
                break;
            case '9': //change foundRecord synopsis (worked!)
                //enter synopsis
                cout << "Enter new synopsis:\n";
                cin.ignore();
                getline(cin, newSynopsis);
                picture.synopsis = newSynopsis;
                foundRecord->setData(picture); //set node to new value
                //picturesTree->printPicturesInorder();
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


//delete function for pictures database (worked! done)
void picturesDelete(BSTree<PictureData, string> *picturesTree) {
    
    string name;
    
    //enter record to delete
    cout << "\nEnter name of the record you want to delete: \n";
    cin.ignore();
    getline(cin, name);
    
    //find that record
    Node<PictureData, string> *foundDeleteRecord = picturesTree->findNode(name);
    if (foundDeleteRecord == nullptr) {
        cout << "Record not found!\n";
        return;
    }
    
    //delete that record
    picturesTree->deleteNode(foundDeleteRecord->Key());
    
    //print new results
    picturesTree->printPicturesInorder();
    
}


//function for sorting pictures (done!)
void picturesSort(BSTree<PictureData, string> *pictureTree) {
    
    bool exit = false;
    
    //exit loop
    while (!exit) {
        
        bool validMenuInput = false;
        char menu = ' ';
        
        //temp vec and bst
        vector<PictureData> yearVector;
        vector<PictureData> nominationsVector;
        vector<PictureData> ratingsVector;
        vector<PictureData> durationVector;
        vector<PictureData> genre1Vector;
        vector<PictureData> genre2Vector;
        vector<PictureData> releaseVector;
        vector<PictureData> metacriticVector;
        vector<PictureData> synopsisVector;
        BSTree<PictureData, int> *yearTree = new BSTree<PictureData, int>;
        BSTree<PictureData, int> *nominationsTree = new BSTree<PictureData, int>;
        BSTree<PictureData, double> *ratingsTree = new BSTree<PictureData, double>;
        BSTree<PictureData, int> *durationTree = new BSTree<PictureData, int>;
        BSTree<PictureData, string> *genre1Tree = new BSTree<PictureData, string>;
        BSTree<PictureData, string> *genre2Tree = new BSTree<PictureData, string>;
        BSTree<PictureData, string> *releaseTree = new BSTree<PictureData, string>;
        BSTree<PictureData, int> *metacriticTree = new BSTree<PictureData, int>;
        BSTree<PictureData, string> *synopsisTree = new BSTree<PictureData, string>;
        
        //valid menu input
        while (!validMenuInput) {
            cout << "\nWhich field do you want to resort this BST by?\n";
            cout << "----------------------------------------------\n";
            cout << "Enter 0 to sort by year\n";
            cout << "Enter 1 to sort by nominations\n";
            cout << "Enter 2 to sort by ratings\n";
            cout << "Enter 3 to sort by nominations\n";
            cout << "Enter 4 to sort by genre 1\n";
            cout << "Enter 5 to sort by genre 2\n";
            cout << "Enter 6 to sort by release month\n";
            cout << "Enter 7 to sort by metacritic\n";
            cout << "Enter 8 to sort by synopsis\n";
            cout << "Enter Q to go back to Actor database\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
            
        }//while
        
        switch (menu) {
            case '0': //sort by year and print (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), yearVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < yearVector.size(); i++) {
                    yearTree->addNode(yearVector[i].year, yearVector[i]);
                }
                yearTree->printPicturesInorder(); //print new sorted tree
                break;
            case '1'://sort by nominations and print (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), nominationsVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < nominationsVector.size(); i++) {
                    nominationsTree->addNode(nominationsVector[i].nominations, nominationsVector[i]);
                }
                nominationsTree->printPicturesInorder();//print new sorted tree
                break;
            case '2': //sort by ratings and print (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), ratingsVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < ratingsVector.size(); i++) {
                    ratingsTree->addNode(ratingsVector[i].rating, ratingsVector[i]);
                }
                ratingsTree->printPicturesInorder();//print new sorted tree
                break;
            case '3'://sort by duration and print (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), durationVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < durationVector.size(); i++) {
                    durationTree->addNode(durationVector[i].duration, durationVector[i]);
                }
                durationTree->printPicturesInorder();//print new sorted tree
                break;
            case '4': //sort by genre 1 (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), genre1Vector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < genre1Vector.size(); i++) {
                    genre1Tree->addNode(genre1Vector[i].genre1, genre1Vector[i]);
                }
                genre1Tree->printPicturesInorder();//print new sorted tree
                break;
            case '5': //sort by genre 2 (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), genre2Vector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < genre2Vector.size(); i++) {
                    genre2Tree->addNode(genre2Vector[i].genre2, genre2Vector[i]);
                }
                genre2Tree->printPicturesInorder(); //print new sorted tree
                break;
            case '6': //sort by release month (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), releaseVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < releaseVector.size(); i++) {
                    releaseTree->addNode(releaseVector[i].release, releaseVector[i]);
                }
                releaseTree->printPicturesInorder(); //print new sorted tree
                break;
            case '7': //sort by release metacritic (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), metacriticVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < metacriticVector.size(); i++) {
                    metacriticTree->addNode(metacriticVector[i].metacritic, metacriticVector[i]);
                }
                metacriticTree->printPicturesInorder(); //print new sorted tree
                break;
            case '8': //sort by release synopsis (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), synopsisVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < synopsisVector.size(); i++) {
                    synopsisTree->addNode(synopsisVector[i].synopsis, synopsisVector[i]);
                }
                synopsisTree->printPicturesInorder(); //print new sorted tree
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
void bstToVector(Node<PictureData, string> *picturesNode, vector<PictureData> &v) {
    
    //check if it's empty
    if (picturesNode == nullptr)
        return;
    
    //store data into vector
    bstToVector(picturesNode->Left(), v);
    v.push_back(picturesNode->Data()); //push back data
    bstToVector(picturesNode->Right(), v);
    
}

//picture complete search (worked!)
void picturesCompleteSearch(BSTree<PictureData, string> *pictureTree) {
    
    bool exit = false;
    //loop until exit
    while (!exit) {
        
        bool validMenuInput = false;
        char menu = ' ';
        char searchAgain = ' ';
        bool validSearchAgain = false;
        bool validYear = false;
        bool validNominations = false;
        bool validDuration = false;
        bool validMetacritic = false;
        bool validRating = false;
        int year = 0, nominations = 0, duration = 0, metacritic = 0;
        double ratings = 0.0;
        string genre1, genre2, release, synopsis, name;
        
        //tempvec
        vector<PictureData> yearVector;
        vector<PictureData> nominationsVector;
        vector<PictureData> ratingsVector;
        vector<PictureData> durationVector;
        vector<PictureData> genre1Vector;
        vector<PictureData> genre2Vector;
        vector<PictureData> releaseVector;
        vector<PictureData> metacriticVector;
        vector<PictureData> synopsisVector;
        
        //found vec
        vector<PictureData> foundCompleteYear;
        vector<PictureData> foundCompleteNominations;
        vector<PictureData> foundCompleteRatings;
        vector<PictureData> foundCompleteDurations;
        vector<PictureData> foundCompleteGenre1;
        vector<PictureData> foundCompleteGenre2;
        vector<PictureData> foundCompleteRelease;
        vector<PictureData> foundCompleteMetacritic;
        vector<PictureData> foundCompleteSynopsis;
        vector<PictureData> foundCompleteName;
        
        //temptrees
        BSTree<PictureData, int> *yearTree = new BSTree<PictureData, int>;
        BSTree<PictureData, int> *nominationsTree = new BSTree<PictureData, int>;
        BSTree<PictureData, double> *ratingsTree = new BSTree<PictureData, double>;
        BSTree<PictureData, int> *durationTree = new BSTree<PictureData, int>;
        BSTree<PictureData, string> *genre1Tree = new BSTree<PictureData, string>;
        BSTree<PictureData, string> *genre2Tree = new BSTree<PictureData, string>;
        BSTree<PictureData, string> *releaseTree = new BSTree<PictureData, string>;
        BSTree<PictureData, int> *metacriticTree = new BSTree<PictureData, int>;
        BSTree<PictureData, string> *synopsisTree = new BSTree<PictureData, string>;
        //valid menu input
        while (!validMenuInput) {
            cout << "\nWhich field do you want to complete search this BST?\n";
            cout << "----------------------------------------------\n";
            cout << "Enter 0 to complete search by year\n";
            cout << "Enter 1 to complete search by nominations\n";
            cout << "Enter 2 to complete search by ratings\n";
            cout << "Enter 3 to complete search by durations\n";
            cout << "Enter 4 to complete search by genre 1\n";
            cout << "Enter 5 to complete search by genre 2\n";
            cout << "Enter 6 to complete search by release month\n";
            cout << "Enter 7 to complete search by metacritic\n";
            cout << "Enter 8 to complete search by synopsis\n";
            cout << "Enter 9 to complete search by name\n";
            cout << "Enter Q to go back to Actor database\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
            
        }//while
        
        switch (menu) {
            case '0': //search by complete year (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), yearVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < yearVector.size(); i++) {
                    yearTree->addNode(yearVector[i].year, yearVector[i]);
                }
                //get year input
                while (!validYear) {
                    cout << "\nEnter complete year:\n";
                    cin >> year;
                    validYear = validNumbers();
                }
                
                //find all matches
                foundCompleteIntSearch(yearTree->Root(), foundCompleteYear, year);
                
                //print found searches
                cout << "\nWe've found " << foundCompleteYear.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteYear);
                } else {
                    printPictureVector(foundCompleteYear);
                }
                
                break;
            case '1': //search by nominations (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), nominationsVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < nominationsVector.size(); i++) {
                    nominationsTree->addNode(nominationsVector[i].nominations, nominationsVector[i]);
                }
                
                //enter nominations
                while (!validNominations) {
                    cout << "\nEnter complete nominations numbers:\n";
                    cin >> nominations;
                    validNominations = validNumbers();
                }
                
                //find all matches
                foundCompleteIntSearch(nominationsTree->Root(), foundCompleteNominations, nominations);

                //print found searches
                cout << "\nWe've found " << foundCompleteNominations.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteNominations);
                } else {
                    printPictureVector(foundCompleteNominations);
                }
                
                break;
            case '2': //search by ratings (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), ratingsVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < ratingsVector.size(); i++) {
                    ratingsTree->addNode(ratingsVector[i].rating, ratingsVector[i]);
                }
                
                //enter rating
                while (!validRating) {
                    cout << "\nEnter complete ratings:\n";
                    cin >> ratings;
                    validRating = validNumbers();
                }
                
                //find all matches
                foundCompleteDoubleSearch(ratingsTree->Root(), foundCompleteRatings, ratings);
                
                //print found searches
                cout << "\nWe've found " << foundCompleteRatings.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteRatings);
                } else {
                    printPictureVector(foundCompleteRatings);
                }
                
                break;
            case '3': //search by durations (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), durationVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < durationVector.size(); i++) {
                    durationTree->addNode(durationVector[i].duration, durationVector[i]);
                }
                
                //enter duration
                while (!validDuration) {
                    cout << "\nEnter complete durations:\n";
                    cin >> duration;
                    validDuration = validNumbers();
                }
                
                //find all matches
                foundCompleteIntSearch(durationTree->Root(), foundCompleteDurations, duration);
                
                //print found searches
                cout << "\nWe've found " << foundCompleteDurations.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteDurations);
                } else {
                    printPictureVector(foundCompleteDurations);
                }
                
                break;
            case '4': //search by genre 1 (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), genre1Vector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < genre1Vector.size(); i++) {
                    genre1Tree->addNode(genre1Vector[i].genre1, genre1Vector[i]);
                    
                }
                
                //enter genre 1
                cout << "\nEnter complete genre 1:\n";
                cin.ignore();
                getline(cin, genre1);
                
                //find all matches
                foundCompleteStringSearch(genre1Tree->Root(), foundCompleteGenre1, genre1);
                
                //print found searches
                cout << "\nWe've found " << foundCompleteGenre1.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteGenre1);
                } else {
                    printPictureVector(foundCompleteGenre1);
                }
                
                break;
            case '5': //search by genre 2 (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), genre2Vector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < genre2Vector.size(); i++) {
                    genre2Tree->addNode(genre2Vector[i].genre2, genre2Vector[i]);
                }
                
                //enter genre 2
                cout << "\nEnter complete genre 2:\n";
                cin.ignore();
                getline(cin, genre2);
                
                //find all matches
                foundCompleteStringSearch(genre2Tree->Root(), foundCompleteGenre2, genre2);
                
                //print found searches
                cout << "\nWe've found " << foundCompleteGenre2.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteGenre2);
                } else {
                    printPictureVector(foundCompleteGenre2);
                }
                
                break;
            case '6': //search by release month (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), releaseVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < releaseVector.size(); i++) {
                    releaseTree->addNode(releaseVector[i].release, releaseVector[i]);
                }
                
                //enter release month
                cout << "\nEnter complete release month:\n";
                cin.ignore();
                getline(cin, release);
                
                //find all matches
                foundCompleteStringSearch(releaseTree->Root(), foundCompleteRelease, release);
                
                //print found searches
                cout << "\nWe've found " << foundCompleteRelease.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteRelease);
                } else {
                    printPictureVector(foundCompleteRelease);
                }
                
                break;
            case '7'://search by metacritic (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), metacriticVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < metacriticVector.size(); i++) {
                    metacriticTree->addNode(metacriticVector[i].metacritic, metacriticVector[i]);
                }
                
                //enter metacritic
                while (!validMetacritic) {
                    cout << "\nEnter complete metacritic:\n";
                    cin >> metacritic;
                    validMetacritic = validNumbers();
                }
                
                //find all matches
                foundCompleteIntSearch(metacriticTree->Root(), foundCompleteMetacritic, metacritic);
                
                //print found searches
                cout << "\nWe've found " << foundCompleteMetacritic.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteMetacritic);
                } else {
                    printPictureVector(foundCompleteMetacritic);
                }
                
                break;
            case '8'://search by synopsis (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), synopsisVector);
                
                //loop vector to store data into new tree
                for (int i = 0; i < synopsisVector.size(); i++) {
                    synopsisTree->addNode(synopsisVector[i].synopsis, synopsisVector[i]);
                    
                }
                
                //enter synopsis
                cout << "\nEnter complete synopsis:\n";
                cin.ignore();
                getline(cin, synopsis);
                
                //find all matches
                foundCompleteStringSearch(synopsisTree->Root(), foundCompleteSynopsis, synopsis);
                
                //print found searches
                cout << "\nWe've found " << foundCompleteSynopsis.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteSynopsis);
                } else {
                    printPictureVector(foundCompleteSynopsis);
                }
                
                break;
            case '9'://search by name (worked!)
                //enter name
                cout << "\nEnter complete name:\n";
                cin.ignore();
                getline(cin, name);
                
                //find all matches
                foundCompleteStringSearch(pictureTree->Root(), foundCompleteName, name);
                
                //print found searches
                cout << "\nWe've found " << foundCompleteName.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondCompleteSearch(foundCompleteName);
                } else {
                    printPictureVector(foundCompleteName);
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

//second complete search function
void secondCompleteSearch(vector<PictureData> &v) {
    bool exit = false;
    
    //loop while not exit
    while (!exit) {
        
        bool validMenuInput = false;
        char menu = ' ';
        char print = ' ';
        bool validYear = false;
        bool validNominations = false;
        bool validDuration = false;
        bool validMetacritic = false;
        bool validRating = false;
        bool validInputPrint = false;
        int year = 0, nominations = 0, duration = 0, metacritic = 0;
        double ratings = 0.0;
        string genre1, genre2, release, synopsis, name;
        
        //found vec
        vector<PictureData> found2ndCompleteYearVector;
        vector<PictureData> found2ndCompleteNominationsVector;
        vector<PictureData> found2ndCompleteRatingsVector;
        vector<PictureData> found2ndCompleteDurationsVector;
        vector<PictureData> found2ndCompleteGenre1Vector;
        vector<PictureData> found2ndCompleteGenre2Vector;
        vector<PictureData> found2ndCompleteReleaseVector;
        vector<PictureData> found2ndCompleteMetacriticVector;
        vector<PictureData> found2ndCompleteSynopsisVector;
        vector<PictureData> found2ndCompleteNameVector;
        
        //valid menu input
        while (!validMenuInput) {
            cout << "\nWhich field do you want to complete second search this BST?\n";
            cout << "---------------------------------------------------\n";
            cout << "Enter 0 to complete second search by year\n";
            cout << "Enter 1 to complete second search by nominations\n";
            cout << "Enter 2 to complete second search by ratings\n";
            cout << "Enter 3 to complete second search by durations\n";
            cout << "Enter 4 to complete second search by genre 1\n";
            cout << "Enter 5 to complete second search by genre 2\n";
            cout << "Enter 6 to complete second search by release month\n";
            cout << "Enter 7 to complete second search by metacritic\n";
            cout << "Enter 8 to complete second search by synopsis\n";
            cout << "Enter 9 to complete second search by name\n";
            cout << "Enter Q to go back to Actor database\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
            
        }//while
        
        switch (menu) {
            case '0'://second search by complete year (worked!)
                
                //enter year
                while (!validYear) {
                    cout << "\nEnter your second complete search for year\n";
                    cin >> year;
                    validYear = validNumbers();
                }
                
                //loop through vector to match
                for (int i = 0; i < v.size(); i++) {
                    if (year == v[i].year) {
                        found2ndCompleteYearVector.push_back(v[i]);
                    }
                }
                
                //print found
                cout << "\nWe've found " << found2ndCompleteYearVector.size() << " search(es)\n";
                
                //ask if they want to print
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print search results
                if (print == 'Y') {
                    printPictureVector(found2ndCompleteYearVector);
                } else {
                    return;
                }
                
                break;
            case '1': // second search by nominations (worked!)
                
                //enter nominations
                while (!validNominations) {
                    cout << "\nEnter your second complete search for nominations\n";
                    cin >> nominations;
                    validNominations = validNumbers();
                }
                
                //loop through vector to match
                for (int i = 0; i < v.size(); i++) {
                    if (nominations == v[i].nominations) {
                        found2ndCompleteNominationsVector.push_back(v[i]);
                    }
                }
                
                //print found
                cout << "\nWe've found " << found2ndCompleteNominationsVector.size() << " search(es)\n";
                
                //ask if they want to print
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print search results
                if (print == 'Y') {
                    printPictureVector(found2ndCompleteNominationsVector);
                } else {
                    return;
                }
                
                break;
            case '2': // second search by ratings (worked!)
                
                //enter rating
                while (!validRating) {
                    cout << "\nEnter your second complete search for ratings\n";
                    cin >> ratings;
                    validRating = validNumbers();
                }
                
                //loop through vector to match
                for (int i = 0; i < v.size(); i++) {
                    if (ratings == v[i].rating) {
                        found2ndCompleteRatingsVector.push_back(v[i]);
                    }
                }
                
                //print found
                cout << "\nWe've found " << found2ndCompleteRatingsVector.size() << " search(es)\n";
                
                //ask if they want to print
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print search results
                if (print == 'Y') {
                    printPictureVector(found2ndCompleteRatingsVector);
                } else {
                    return;
                }
                
                break;
            case '3'://second search by durations (worked!)
                
                //enter duration
                while (!validDuration) {
                    cout << "\nEnter your second complete search for durations\n";
                    cin >> duration;
                    validDuration = validNumbers();
                }
                
                //loop through vector to match
                for (int i = 0; i < v.size(); i++) {
                    if (duration == v[i].duration) {
                        found2ndCompleteDurationsVector.push_back(v[i]);
                    }
                }
                
                //print found
                cout << "\nWe've found " << found2ndCompleteDurationsVector.size() << " search(es)\n";
                
                //ask if they want to print
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print search results
                if (print == 'Y') {
                    printPictureVector(found2ndCompleteDurationsVector);
                } else {
                    return;
                }
                
                break;
            case '4': // second search by genre 1 (worked!)
                
                //enter genre 1
                cout << "\nEnter your second complete search for genre 1\n";
                cin.ignore();
                getline(cin, genre1);
                
                //loop through vector to match
                for (int i = 0; i < v.size(); i++) {
                    if (genre1 == v[i].genre1) {
                        found2ndCompleteGenre1Vector.push_back(v[i]);
                    }
                }
                
                //print found
                cout << "\nWe've found " << found2ndCompleteGenre1Vector.size() << " search(es)\n";
                
                //ask if they want to print
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print search results
                if (print == 'Y') {
                    printPictureVector(found2ndCompleteGenre1Vector);
                } else {
                    return;
                }
                
                break;
            case '5': // secondsearch by genre 2 (worked!)
                
                //enter genre 2
                cout << "\nEnter your second complete search for genre 2\n";
                cin.ignore();
                getline(cin, genre2);
                
                //loop through vector to match
                for (int i = 0; i < v.size(); i++) {
                    if (genre2 == v[i].genre2) {
                        found2ndCompleteGenre2Vector.push_back(v[i]);
                    }
                }
                
                //print found
                cout << "\nWe've found " << found2ndCompleteGenre2Vector.size() << " search(es)\n";
                
                //ask if they want to print
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print search results
                if (print == 'Y') {
                    printPictureVector(found2ndCompleteGenre2Vector);
                } else {
                    return;
                }
                
                break;
            case '6': //second search by release month (worked!)
                
                //enter release month
                cout << "\nEnter your second complete search for release month\n";
                cin.ignore();
                getline(cin, release);
                
                //loop through vector to match
                for (int i = 0; i < v.size(); i++) {
                    if (release == v[i].release) {
                        found2ndCompleteReleaseVector.push_back(v[i]);
                    }
                }
                
                //print found
                cout << "\nWe've found " << found2ndCompleteReleaseVector.size() << " search(es)\n";
                
                //ask if they want to print
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print search results
                if (print == 'Y') {
                    printPictureVector(found2ndCompleteReleaseVector);
                } else {
                    return;
                }
                
                break;
            case '7': //second search by metacritic (worked!)
                
                //enter metacritic
                while (!validMetacritic) {
                    cout << "\nEnter your second complete search for metacritic\n";
                    cin >> metacritic;
                    validMetacritic = validNumbers();
                }
                
                //loop through vector to match
                for (int i = 0; i < v.size(); i++) {
                    if (metacritic == v[i].metacritic) {
                        found2ndCompleteMetacriticVector.push_back(v[i]);
                    }
                }
                
                //print found
                cout << "\nWe've found " << found2ndCompleteMetacriticVector.size() << " search(es)\n";
                
                //ask if they want to print
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print search results
                if (print == 'Y') {
                    printPictureVector(found2ndCompleteMetacriticVector);
                } else {
                    return;
                }
                
                break;
            case '8': //second search by synopsis (worked!)
                
                //enter synopsis
                cout << "\nEnter your second complete search for synopsis\n";
                cin.ignore();
                getline(cin, synopsis);
                
                //loop through vector to match
                for (int i = 0; i < v.size(); i++) {
                    if (synopsis == v[i].synopsis) {
                        found2ndCompleteSynopsisVector.push_back(v[i]);
                    }
                }
                
                //print found
                cout << "\nWe've found " << found2ndCompleteSynopsisVector.size() << " search(es)\n";
                
                //ask if they want to print
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print search results
                if (print == 'Y') {
                    printPictureVector(found2ndCompleteSynopsisVector);
                } else {
                    return;
                }
                
                break;
            case '9'://second search by name (worked!)
                
                //enter name
                cout << "\nEnter your second complete search for name\n";
                cin.ignore();
                getline(cin, name);
                
                //loop through vector to match
                for (int i = 0; i < v.size(); i++) {
                    if (name == v[i].name) {
                        found2ndCompleteNameVector.push_back(v[i]);
                    }
                }
                
                //print found
                cout << "\nWe've found " << found2ndCompleteNameVector.size() << " search(es)\n";
                
                //ask if they want to print
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print search results
                if (print == 'Y') {
                    printPictureVector(found2ndCompleteNameVector);
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


//complete search for ints
void foundCompleteIntSearch(Node<PictureData, int> *pictureNode, vector<PictureData> &v, int value) {
    
    //check if tree is empty
    if (pictureNode == nullptr)
        return;
    
    //traverse left
    foundCompleteIntSearch(pictureNode->Left(), v, value);
    
    //check for matches
    if (value == pictureNode->Key()) {
        v.push_back(pictureNode->Data());
    }
    
    //traverse right
    foundCompleteIntSearch(pictureNode->Right(), v, value);
    
}

//complete search for double
void foundCompleteDoubleSearch(Node<PictureData, double> *pictureNode, vector<PictureData> &v, double value){
    
    //check if tree is empty
    if (pictureNode == nullptr)
        return;
    
    //traverse left
    foundCompleteDoubleSearch(pictureNode->Left(), v, value);
    
    //check for matches
    if (value == pictureNode->Key()) {
        v.push_back(pictureNode->Data());
    }
    
    //traverse right
    foundCompleteDoubleSearch(pictureNode->Right(), v, value);
}

//complete search for string
void foundCompleteStringSearch(Node<PictureData, string> *pictureNode, vector<PictureData> &v, string value) {
    
    //check if tree is empty
    if (pictureNode == nullptr)
        return;
    
    //traverse left
    foundCompleteStringSearch(pictureNode->Left(), v, value);
    
    //check for matches
    if (value == pictureNode->Key()) {
        v.push_back(pictureNode->Data());
    }
    
    //traverse right
    foundCompleteStringSearch(pictureNode->Right(), v, value);
    
}

//function partial search (worked!)
void picturesPartialSearch(BSTree<PictureData, string> *pictureTree) {
    bool exit = false;
    
    //exit loop
    while (!exit) {
        
        bool validMenuInput = false;
        char menu = ' ';
        char searchAgain = ' ';
        bool validSearchAgain = false;
        bool validYear = false;
        bool validNominations = false;
        bool validDuration = false;
        bool validMetacritic = false;
        bool validRating = false;
        int year = 0, nominations = 0, duration = 0, metacritic = 0;
        double ratings = 0.0;
        string genre1, genre2, release, synopsis, name;
        
        //tempvec
        vector<PictureData> yearVector;
        vector<PictureData> nominationsVector;
        vector<PictureData> ratingsVector;
        vector<PictureData> durationVector;
        vector<PictureData> genre1Vector;
        vector<PictureData> genre2Vector;
        vector<PictureData> releaseVector;
        vector<PictureData> metacriticVector;
        vector<PictureData> synopsisVector;
        
        //found vec
        vector<PictureData> foundPartialYear;
        vector<PictureData> foundPartialNominations;
        vector<PictureData> foundPartialRatings;
        vector<PictureData> foundPartialDurations;
        vector<PictureData> foundPartialGenre1;
        vector<PictureData> foundPartialGenre2;
        vector<PictureData> foundPartialRelease;
        vector<PictureData> foundPartialMetacritic;
        vector<PictureData> foundPartialSynopsis;
        vector<PictureData> foundPartialName;
        
        //temptrees
        BSTree<PictureData, int> *yearTree = new BSTree<PictureData, int>;
        BSTree<PictureData, int> *nominationsTree = new BSTree<PictureData, int>;
        BSTree<PictureData, double> *ratingsTree = new BSTree<PictureData, double>;
        BSTree<PictureData, int> *durationTree = new BSTree<PictureData, int>;
        BSTree<PictureData, string> *genre1Tree = new BSTree<PictureData, string>;
        BSTree<PictureData, string> *genre2Tree = new BSTree<PictureData, string>;
        BSTree<PictureData, string> *releaseTree = new BSTree<PictureData, string>;
        BSTree<PictureData, int> *metacriticTree = new BSTree<PictureData, int>;
        BSTree<PictureData, string> *synopsisTree = new BSTree<PictureData, string>;
        
        //valid menu input
        while (!validMenuInput) {
            cout << "\nWhich field do you want to complete search this BST?\n";
            cout << "----------------------------------------------\n";
            cout << "Enter 0 to partial search by year\n";
            cout << "Enter 1 to partial search by nominations\n";
            cout << "Enter 2 to partial search by ratings\n";
            cout << "Enter 3 to partial search by durations\n";
            cout << "Enter 4 to partial search by genre 1\n";
            cout << "Enter 5 to partial search by genre 2\n";
            cout << "Enter 6 to partial search by release month\n";
            cout << "Enter 7 to partial search by metacritic\n";
            cout << "Enter 8 to partial search by synopsis\n";
            cout << "Enter 9 to partial search by name\n";
            cout << "Enter Q to go back to Actor database\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
            
        }//while
        
        switch (menu) {
            case '0': //partial search by year (worked!)
                
                //convert bst to vector
                bstToVector(pictureTree->Root(), yearVector);
                
                //loop to add data into vector
                for (int i = 0; i < yearVector.size(); i++) {
                    yearTree->addNode(yearVector[i].year, yearVector[i]);
                }
                
                //enter year
                while (!validYear) {
                    cout << "\nEnter partial year:\n";
                    cin >> year;
                    validYear = validNumbers();
                }
                
                //find partial match
                foundPartialIntSearch(yearTree->Root(), foundPartialYear, year);
                
                //print found searches
                cout << "\nWe've found " << foundPartialYear.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialYear);
                } else {
                    printPictureVector(foundPartialYear);
                }
                
                break;
            case '1'://partial search by nominations (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), nominationsVector);
                
                //loop to add data into vector
                for (int i = 0; i < nominationsVector.size(); i++) {
                    nominationsTree->addNode(nominationsVector[i].nominations, nominationsVector[i]);
                }
                
                //enter nominations
                while (!validNominations) {
                    cout << "\nEnter partial nominations numbers:\n";
                    cin >> nominations;
                    validNominations = validNumbers();
                }
                
                //find partial match
                foundPartialIntSearch(nominationsTree->Root(), foundPartialNominations, nominations);
                
                //print found searches
                cout << "\nWe've found " << foundPartialNominations.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialNominations);
                } else {
                    printPictureVector(foundPartialNominations);
                }
                
                break;
            case '2'://partial search by ratings (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), ratingsVector);
                
                //loop vector to store new ratings
                for (int i = 0; i < ratingsVector.size(); i++) {
                    ratingsTree->addNode(ratingsVector[i].rating, ratingsVector[i]);
                }
                
                //enter rating
                while (!validRating) {
                    cout << "\nEnter partial ratings:\n";
                    cin >> ratings;
                    validRating = validNumbers();
                }
                
                //find partial match
                foundPartialDoubleSearch(ratingsTree->Root(), foundPartialRatings, ratings);
                
                //print found searches
                cout << "\nWe've found " << foundPartialRatings.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialRatings);
                } else {
                    printPictureVector(foundPartialRatings);
                }
                
                break;
            case '3'://search by durations (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), durationVector);
                
                //loop vector to store into new tree
                for (int i = 0; i < durationVector.size(); i++) {
                    durationTree->addNode(durationVector[i].duration, durationVector[i]);
                }
                
                //enter duration
                while (!validDuration) {
                    cout << "\nEnter partial durations:\n";
                    cin >> duration;
                    validDuration = validNumbers();
                }
                
                //find partial match
                foundPartialIntSearch(durationTree->Root(), foundPartialDurations, duration);
                
                //print found searches
                cout << "\nWe've found " << foundPartialDurations.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialDurations);
                } else {
                    printPictureVector(foundPartialDurations);
                }
                
                break;
            case '4'://partial search by genre 1 (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), genre1Vector);
                
                //loop vector and convert into new bst
                for (int i = 0; i < genre1Vector.size(); i++) {
                    genre1Tree->addNode(genre1Vector[i].genre1, genre1Vector[i]);
                }
                
                //enter genre 1
                cout << "\nEnter partial genre 1:\n";
                cin.ignore();
                getline(cin, genre1);
                
                //find partial match
                foundPartialStringSearch(genre1Tree->Root(), foundPartialGenre1, genre1);
                
                //print found searches
                cout << "\nWe've found " << foundPartialGenre1.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialGenre1);
                } else {
                    printPictureVector(foundPartialGenre1);
                }
                
                break;
            case '5'://partial search by genre 2 (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), genre2Vector);
                
                //loop vector and convert into new bst
                for (int i = 0; i < genre2Vector.size(); i++) {
                    genre2Tree->addNode(genre2Vector[i].genre2, genre2Vector[i]);
                }
                
                //enter genre 2
                cout << "\nEnter partial genre 2:\n";
                cin.ignore();
                getline(cin, genre2);
                
                //find partial search
                foundPartialStringSearch(genre2Tree->Root(), foundPartialGenre2, genre2);
                
                //print found searches
                cout << "\nWe've found " << foundPartialGenre2.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialGenre2);
                } else {
                    printPictureVector(foundPartialGenre2);
                }
                
                break;
            case '6': //partial search by release month (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), releaseVector);
                
                //loop vector and convert into new bst
                for (int i = 0; i < releaseVector.size(); i++) {
                    releaseTree->addNode(releaseVector[i].release, releaseVector[i]);
                }
                
                //enter release month
                cout << "\nEnter partial release month:\n";
                cin.ignore();
                getline(cin, release);
                
                //find partial match
                foundPartialStringSearch(releaseTree->Root(), foundPartialRelease, release);
                
                //print found searches
                cout << "\nWe've found " << foundPartialRelease.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialRelease);
                } else {
                    printPictureVector(foundPartialRelease);
                }
                
                break;
            case '7'://partial search by metacritic (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), metacriticVector);
                
                //loop vector and convert into new bst
                for (int i = 0; i < metacriticVector.size(); i++) {
                    metacriticTree->addNode(metacriticVector[i].metacritic, metacriticVector[i]);
                }
                
                //enter metacritic
                while (!validMetacritic) {
                    cout << "\nEnter partial metacritic:\n";
                    cin >> metacritic;
                    validMetacritic = validNumbers();
                }
                
                //find partial match
                foundPartialIntSearch(metacriticTree->Root(), foundPartialMetacritic, metacritic);
                
                //print found searches
                cout << "\nWe've found " << foundPartialMetacritic.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialMetacritic);
                } else {
                    printPictureVector(foundPartialMetacritic);
                }
                
                break;
            case '8'://partial search by synopsis (worked!)
                //convert bst to vector
                bstToVector(pictureTree->Root(), synopsisVector);
                
                //loop vector and convert into new bst
                for (int i = 0; i < synopsisVector.size(); i++) {
                    synopsisTree->addNode(synopsisVector[i].synopsis, synopsisVector[i]);
                    
                }
                
                //enter synopsis
                cout << "\nEnter partial synopsis:\n";
                cin.ignore();
                getline(cin, synopsis);
                
                //find partial match
                foundPartialStringSearch(synopsisTree->Root(), foundPartialSynopsis, synopsis);
                
                //print found searches
                cout << "\nWe've found " << foundPartialSynopsis.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialSynopsis);
                } else {
                    printPictureVector(foundPartialSynopsis);
                }
                
                break;
            case '9'://partial search by synopsis (worked!)
                
                //enter name
                cout << "\nEnter partial name:\n";
                cin.ignore();
                getline(cin, name);
                
                //find partial match
                foundPartialStringSearch(pictureTree->Root(), foundPartialName, name);
                
                //print found searches
                cout << "\nWe've found " << foundPartialName.size() << " search(es)\n";
                
                //ask for second searches
                while (!validSearchAgain) {
                    cout << "\nDo you want to do a second search? (y or n)\n";
                    cin >> searchAgain;
                    searchAgain = toupper(searchAgain);
                    validSearchAgain = validYOrN(searchAgain);
                }
                
                //second search
                if (searchAgain == 'Y') {
                    secondPartialSearch(foundPartialName);
                } else {
                    printPictureVector(foundPartialName);
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

//partial second search function
void secondPartialSearch(vector<PictureData> &v) {
    bool exit = false;
    
    //loop until exit
    while (!exit) {
        
        bool validMenuInput = false;
        char menu = ' ';
        char print = ' ';
        bool validYear = false;
        bool validNominations = false;
        bool validDuration = false;
        bool validMetacritic = false;
        bool validRating = false;
        bool validInputPrint = false;
        int year = 0, nominations = 0, duration = 0, metacritic = 0;
        double ratings = 0.0;
        string genre1, genre2, release, synopsis, name;
        
        //found vec
        vector<PictureData> found2ndPartialYearVector;
        vector<PictureData> found2ndPartialNominationsVector;
        vector<PictureData> found2ndPartialRatingsVector;
        vector<PictureData> found2ndPartialDurationsVector;
        vector<PictureData> found2ndPartialGenre1Vector;
        vector<PictureData> found2ndPartialGenre2Vector;
        vector<PictureData> found2ndPartialReleaseVector;
        vector<PictureData> found2ndPartialMetacriticVector;
        vector<PictureData> found2ndPartialSynopsisVector;
        vector<PictureData> found2ndPartialNameVector;
        
        //valid menu input
        while (!validMenuInput) {
            cout << "\nWhich field do you want to partial second search this BST?\n";
            cout << "---------------------------------------------------\n";
            cout << "Enter 0 to partial second search by year\n";
            cout << "Enter 1 to partial second search by nominations\n";
            cout << "Enter 2 to partial second search by ratings\n";
            cout << "Enter 3 to partial second search by durations\n";
            cout << "Enter 4 to partial second search by genre 1\n";
            cout << "Enter 5 to partial second search by genre 2\n";
            cout << "Enter 6 to partial second search by release month\n";
            cout << "Enter 7 to partial second search by metacritic\n";
            cout << "Enter 8 to partial second search by synopsis\n";
            cout << "Enter 9 to partial second search by name\n";
            cout << "Enter Q to go back to Actor database\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
            
        }//while
        
        switch (menu) {
            case '0': //second search by partial year (worked!)
                //enter year
                while (!validYear) {
                    cout << "\nEnter your second partial search for year\n";
                    cin >> year;
                    validYear = validNumbers();
                }
                
                //loop vector to find second match
                for (int i = 0; i < v.size(); i++) {
                    if (to_string(v[i].year).find(to_string(year)) != string::npos) {
                        found2ndPartialYearVector.push_back(v[i]);
                    }
                }
                
                //find found count
                cout << "\nWe've found " << found2ndPartialYearVector.size() << " search(es)\n";
                
                //ask if want to print
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printPictureVector(found2ndPartialYearVector);
                } else {
                    return;
                }
                
                break;
            case '1': //second partial search by nominations (worked!)
                
                //enter nominations
                while (!validNominations) {
                    cout << "\nEnter your second partial search for nominations\n";
                    cin >> nominations;
                    validNominations = validNumbers();
                }
                
                //loop vector to find second match
                for (int i = 0; i < v.size(); i++) {
                    if (to_string(v[i].nominations).find(to_string(nominations)) != string::npos) {
                        found2ndPartialNominationsVector.push_back(v[i]);
                    }
                }
                
                //find found count
                cout << "\nWe've found " << found2ndPartialNominationsVector.size() << " search(es)\n";
                
                //ask if want to print
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printPictureVector(found2ndPartialNominationsVector);
                } else {
                    return;
                }
                
                break;
            case '2'://second partial search by ratings (worked!)
                //enter rating
                while (!validRating) {
                    cout << "\nEnter your second partial search for ratings\n";
                    cin >> ratings;
                    validRating = validNumbers();
                }
                
                //loop vector to find second match
                for (int i = 0; i < v.size(); i++) {
                    if (to_string(v[i].rating).find(to_string(ratings)) != string::npos) {
                        found2ndPartialRatingsVector.push_back(v[i]);
                    }
                }
                
                //find found count
                cout << "\nWe've found " << found2ndPartialRatingsVector.size() << " search(es)\n";
                
                //ask if want to print
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printPictureVector(found2ndPartialRatingsVector);
                } else {
                    return;
                }
                
                break;
            case '3'://partial second search by durations (worked!)
                
                //enter duration
                while (!validDuration) {
                    cout << "\nEnter your second partial search for durations\n";
                    cin >> duration;
                    validDuration = validNumbers();
                }
                
                //loop vector to find second match
                for (int i = 0; i < v.size(); i++) {
                    if (to_string(v[i].duration).find(to_string(duration)) != string::npos) {
                        found2ndPartialDurationsVector.push_back(v[i]);
                    }
                }
                
                //print count
                cout << "\nWe've found " << found2ndPartialDurationsVector.size() << " search(es)\n";
                
                //print or not
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printPictureVector(found2ndPartialDurationsVector);
                } else {
                    return;
                }
                
                
                break;
            case '4'://partial second search by genre 1 (worked!)
                //enter genre 1
                cout << "\nEnter your second partial search for genre 1\n";
                cin.ignore();
                getline(cin, genre1);
                
                //loop vector to find second match
                for (int i = 0; i < v.size(); i++) {
                    if ((v[i].genre1).find(genre1) != string::npos) {
                        found2ndPartialGenre1Vector.push_back(v[i]);
                    }
                }
                
                //print count
                cout << "\nWe've found " << found2ndPartialGenre1Vector.size() << " search(es)\n";
                
                //print result or not
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printPictureVector(found2ndPartialGenre1Vector);
                } else {
                    return;
                }
                
                break;
            case '5'://second partial search by genre 2 (worked!)
                //enter genre 2
                cout << "\nEnter your second partial search for genre 2\n";
                cin.ignore();
                getline(cin, genre2);
                
                //loop vector to find second match
                for (int i = 0; i < v.size(); i++) {
                    if ((v[i].genre2).find(genre2) != string::npos) {
                        found2ndPartialGenre2Vector.push_back(v[i]);
                    }
                }
                
                //print count
                cout << "\nWe've found " << found2ndPartialGenre2Vector.size() << " search(es)\n";
                
                //print or not
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printPictureVector(found2ndPartialGenre2Vector);
                } else {
                    return;
                }
                
                break;
            case '6'://second partial search by release month (worked!)
                //enter release
                cout << "\nEnter your second partial search for release month\n";
                cin.ignore();
                getline(cin, release);
                
                //loop vector to find second match
                for (int i = 0; i < v.size(); i++) {
                    if ((v[i].release).find(release) != string::npos) {
                        found2ndPartialReleaseVector.push_back(v[i]);
                    }
                }
                
                //print count
                cout << "\nWe've found " << found2ndPartialReleaseVector.size() << " search(es)\n";
                
                //print input
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printPictureVector(found2ndPartialReleaseVector);
                } else {
                    return;
                }
                
                break;
            case '7'://second partial search by metacritic (worked!)
                
                //enter metacritic
                while (!validMetacritic) {
                    cout << "\nEnter your second partial search for metacritic\n";
                    cin >> metacritic;
                    validMetacritic = validNumbers();
                }
                
                //loop vector to find second match
                for (int i = 0; i < v.size(); i++) {
                    if (to_string(v[i].metacritic).find(to_string(metacritic)) != string::npos) {
                        found2ndPartialMetacriticVector.push_back(v[i]);
                    }
                }
                
                //print size
                cout << "\nWe've found " << found2ndPartialMetacriticVector.size() << " search(es)\n";
                
                //print input
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printPictureVector(found2ndPartialMetacriticVector);
                } else {
                    return;
                }
                
                break;
            case '8'://second partial search by synopsis (worked!)
                //enter synopsis
                cout << "\nEnter your second partial search for synopsis\n";
                cin.ignore();
                getline(cin, synopsis);
                
                //loop vector to find second match
                for (int i = 0; i < v.size(); i++) {
                    if ((v[i].synopsis).find(synopsis) != string::npos) {
                        found2ndPartialSynopsisVector.push_back(v[i]);
                    }
                }
                
                //print size
                cout << "\nWe've found " << found2ndPartialSynopsisVector.size() << " search(es)\n";
                
                //print input
                while (!validInputPrint) {
                    cout << "\nDo you want to print final result? (y or n)\n";
                    cin >> print;
                    print = toupper(print);
                    validInputPrint = validYOrN(print);
                }
                
                //print
                if (print == 'Y') {
                    printPictureVector(found2ndPartialSynopsisVector);
                } else {
                    return;
                }
                
                break;
            case '9'://second partial search by name (worked!)
                //enter name
                cout << "\nEnter your second partial search for name\n";
                cin.ignore();
                getline(cin, name);
                
                //loop vector to find second match
                for (int i = 0; i < v.size(); i++) {
                    if ((v[i].name).find(name) != string::npos) {
                        found2ndPartialNameVector.push_back(v[i]);
                    }
                }
                
                //print size
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
                    printPictureVector(found2ndPartialNameVector);
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

//found partial search for int
void foundPartialIntSearch(Node<PictureData, int> *pictureNode, vector<PictureData> &v, int value) {
    
    //check for empty tree
    if (pictureNode == nullptr)
        return;
    
    //traverse left
    foundPartialIntSearch(pictureNode->Left(), v, value);
    
    //find partial match
    if (to_string(pictureNode->Key()).find(to_string(value)) != string::npos) {
        v.push_back(pictureNode->Data());
    }
    
    //traverse right
    foundPartialIntSearch(pictureNode->Right(), v, value);
}

//found partial search for double
void foundPartialDoubleSearch(Node<PictureData, double> *pictureNode, vector<PictureData> &v, double value) {
    //check for empty tree
    if (pictureNode == nullptr)
        return;
    
    //traverse left
    foundPartialDoubleSearch(pictureNode->Left(), v, value);
    
    //find partial match
    if (to_string(pictureNode->Key()).find(to_string(value)) != string::npos) {
        v.push_back(pictureNode->Data());
    }
    
    //traverse right
    foundPartialDoubleSearch(pictureNode->Right(), v, value);
}

//found partial search for string
void foundPartialStringSearch(Node<PictureData, string> *pictureNode, vector<PictureData> &v, string value) {
    //check for empty tree
    if (pictureNode == nullptr)
        return;
    
    //traverse left
    foundPartialStringSearch(pictureNode->Left(), v, value);
    
    //find partial match
    if (pictureNode->Key().find(value) != string::npos) {
        v.push_back(pictureNode->Data());
    }
    
    //traverse right
    foundPartialStringSearch(pictureNode->Right(), v, value);
}

//write to picture file (worked! done)
void writePicturesDatabase(BSTree<PictureData, string> *picturesTree) {
    
    //open file
    ofstream inFile("new-pictures.csv");

    vector<PictureData> picturesVector;
    
    //convert bst to vector
    bstToVector(picturesTree->Root(), picturesVector);
    
    //write first line
    inFile << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis\n";
    
    //write all nodes to file
    for (int i = 0; i < picturesVector.size(); i++) {
        inFile << picturesVector[i].name << "," <<  picturesVector[i].year << "," <<  picturesVector[i].nominations << "," <<  picturesVector[i].rating << "," <<  picturesVector[i].duration << "," << picturesVector[i].genre1 << "," << picturesVector[i].genre2 << "," << picturesVector[i].release << "," << picturesVector[i].metacritic << "," << picturesVector[i].synopsis << endl;
    }
    
    //success
    cout << "\nWrite file success!\n";
    
    //close file
    inFile.close();
}
