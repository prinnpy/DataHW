/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: Oscar's Database final project
 Due Date: May 2 2018
*/

//includes
#include <iostream>
#include <string>
#include "BSTree.h"
#include "functions.h"
using namespace std;

//main
int main() {
    
    //create 2 BST
    BSTree<ActorData, string> *actor = new BSTree<ActorData, string>;
    BSTree<PictureData, string> *pictures = new BSTree<PictureData, string>;
    BSTree<ActorData, string> *nominations = new BSTree<ActorData, string>;
    
    //read in files functions
    readActorActressFile(actor);
    readPicturesFile(pictures);
    readNominationFile(nominations);
    
    
    bool exit = false;
    
    //welcome message
    cout << "----------------------------\n";
    cout << "Welcome to Oscar's Database!\n";
    cout << "----------------------------\n";
    
    //main menu
    while (!exit) {
        
        bool validMenuInput = false;
        char menu = ' ';
        
        //valid menu input
        while (!validMenuInput) {
            cout << "\nMain Menu (Pick Database):\n";
            cout << "--------------------------\n";
            cout << "Enter A for Actor/Actress Database\n";
            cout << "Enter P for Pictures Database\n";
            cout << "Enter N for Nominations Database (Extra Credit)\n";
            cout << "Enter Q to Exit program\n";
            cin >> menu;
            menu = toupper(menu);
            validMenuInput = validMenu(menu);
            
        }//while
        
        switch (menu) {
            case 'A':
                //call function that opens up menu for Actor/Actress Database
                actorDatabase(actor);
                break;
            case 'P':
                //call function that opens up menu for Pictures Database
                picturesDatabase(pictures);
                break;
            case 'N':
                //call function that opens up menu for Nominations Database
                nominationsDatabase(nominations);
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
        
    }
}
