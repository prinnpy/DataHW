/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: Oscar's Database final project
 Due Date: May 2 2018
 */

//include
#include "nominations.h"

//print all winner in a given year
void printWinner(BSTree<ActorData, string> *nominationsTree) {
    
    //vars and vectors
    bool validYear = false;
    int year = 0;
    vector<ActorData> yearVector;
    vector<ActorData> foundyearVector;
    vector<ActorData> foundWinner;
    BSTree<ActorData, int> *yearTree = new BSTree<ActorData, int>;
    
    //convert bst to vector
    bstToVector(nominationsTree->Root(), yearVector);
    
    //store into new bst
    for (int i = 0; i < yearVector.size(); i++) {
        yearTree->addNode(yearVector[i].year, yearVector[i]);
    }
    
    //get year input
    while (!validYear) {
        cout << "\nWhat year do you want to see all the winners?\n";
        cin >> year;
        validYear = validNumbers();
    }
    
    //found search
    foundCompleteIntSearch(yearTree->Root(), foundyearVector, year);
    
    //push back all winners
    for (int i = 0; i < foundyearVector.size();i++) {
        if (foundyearVector[i].winner) {
            foundWinner.push_back(foundyearVector[i]);
        }
    }
    
    //print found winner
    for (int i = 0; i < foundWinner.size();i++) {
        cout << endl;
        cout << i + 1 << ". " << endl;
        cout << "Name: " << foundWinner[i].name << endl;
        cout << "Award: " << foundWinner[i].award << endl;
    }
    
}

//function that prints all actor in leading role who won
void printWonActor(BSTree<ActorData, string> *nominationsTree) {
    
    //vars
    string actor = "Actor in a Leading Role";
    vector<ActorData> awardVector;
    vector<ActorData> foundActorWinner;
    
    //convert to bst
    bstToVector(nominationsTree->Root(), awardVector);
    
    //search to all director that is a winner
    for (int i = 0; i < awardVector.size();i++){
        if (awardVector[i].award == actor){
            if (awardVector[i].winner) {
                foundActorWinner.push_back(awardVector[i]);
            }
        }
    }
    
    //print out found
    for (int i = 0; i < foundActorWinner.size();i++) {
        cout << endl;
        cout << i + 1 << ". " << endl;
        cout << "Name: " << foundActorWinner[i].name << endl;
        cout << "Year: " << foundActorWinner[i].year << endl;
        cout << "Film: " << foundActorWinner[i].film << endl;
    }
    
    
}

//function that compare # of nominations between actor and actress
void ActorVSActressNominations(BSTree<ActorData, string> *nominationsTree) {
    
    //vars
    string actor = "Actor in a Leading Role";
    string actress = "Actress in a Leading Role";
    int actorCount = 0;
    int actressCount = 0;
    vector<ActorData> awardVector;
    
    //convert to bst
    bstToVector(nominationsTree->Root(), awardVector);
    
    //search to all director that is a winner
    for (int i = 0; i < awardVector.size();i++){
        if (awardVector[i].award == actor)
            actorCount++;
        else if (awardVector[i].award == actress)
            actressCount++;
    }
    
    //print out total of actor and actress nominations
    cout << "\nActor nominations total: " << actorCount << endl;
    cout << "Actress nominations total: " << actressCount << endl;

    //compute which has more nominations
    if (actorCount > actressCount){
        cout << "\nThere are more actor nominations!\n";
    } else {
        cout << "\nThere are more actress nominations!\n";
    }
    
}

//print movies that contain 'The'
void printTitleContainsThe(BSTree<ActorData, string> *nominationsTree) {
    
    //vars
    bool validInputPrint = false;
    char print = ' ';
    string title = "The";
    vector<ActorData> titleVector;
    vector<ActorData> foundTitle;
    
    //convert to bst
    bstToVector(nominationsTree->Root(), titleVector);
    
    //search to all director that is a winner
    for (int i = 0; i < titleVector.size();i++){
        if ((titleVector[i].film).find(title) != string::npos) {
            foundTitle.push_back(titleVector[i]);
        }
    }
    
    //print out the total search
    cout << "\nThere are " << foundTitle.size() << " films that starts with 'The'\n";
    
    //ask if user wants to print out the results
    while (!validInputPrint) {
        cout << "\nDo you want to print all " << foundTitle.size() << " films? (y or n)\n";
        cin >> print;
        print = toupper(print);
        validInputPrint = validYOrN(print);
    }
    
    //print out the results
    if (print == 'Y') {
        for (int i = 0; i < foundTitle.size();i++) {
            cout << endl;
            cout << i + 1 << ". " << endl;
            cout << "Film: " << foundTitle[i].film << endl;
            cout << "Year: " << foundTitle[i].year << endl;
            
        }
    } else {
        return;
    }
    
}
