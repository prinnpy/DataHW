
/*
 Name: Prinn Prinyanut
 Description: Final project outline for hw08
 Class: CSCI 2412
 Due Date: Apr 12,2018
 */

#include <iostream>
#include "BSTree.h"
#include "BSTree.hpp"
using namespace std;

int main()
{
    //MY PLAN
    
    //call function that reads in both actor/actress and pictures csv files
    
    bool exit = false;
    
    //main menu
    while (!exit) {
        
        //text
        cout << "\nPick your database to modify" << endl;
        cout << "Enter 1 for Actor/Actress Database" << endl;
        cout << "Enter 2 for Pictures Database" << endl;
        cout << "Enter 3 to Exit program" << endl;
        int menu;
        cin >> menu;
        
        switch (menu) {
            case 1:
                //call function that opens up menu for Actor/Actress Database
                cout << "This is Actor/Actress Database" << endl;
                break;
            case 2:
                //call function that opens up menu for Pictures Database
                cout << "This is Pictures Database" << endl;
                break;
            case 3:
                //exit program
                exit = true;
                break;
            default:
                //incorret
                cout << "Incorrect input. Try again!" << endl;
                break;
        }
        
    }
    
    
    //Given code!!!
//    BSTree<GeneralData, int> *tree = new BSTree<GeneralData, int>;
//    cout << "Adding Nodes...\n";
//    GeneralData tempData;
//    tempData.number = 10;
//    tempData.name = "Gamma";
//    tree->addNode(tempData.number, tempData);
//
//    tempData.number = 5;
//    tempData.name = "Gamma";
//    tree->addNode(tempData.number, tempData);
//
//    tempData.number = 1;
//    tempData.name = "Alpha";
//    tree->addNode(tempData.number, tempData);
//
//    tempData.number = 20;
//    tempData.name = "Delta";
//    tree->addNode(tempData.number, tempData);
//
//    tempData.number = 30;
//    tempData.name = "Eta";
//    tree->addNode(tempData.number, tempData);
//
//    tempData.number = 25;
//    tempData.name = "Epsilon";
//    tree->addNode(tempData.number, tempData);
//
//    tempData.number = 2;
//    tempData.name = "Beta";
//    tree->addNode(tempData.number, tempData);
//
//    cout << "Printing in order...\n";
//    tree->printInorder();
//
//    if (tree->findNode(25) != nullptr)
//        cout << "25 found\n";
//    else
//        cout << "25 not found\n";
//
//    if (tree->findNode(26) != nullptr)
//        cout << "26 found\n";
//    else
//        cout << "26 not found\n";
//
//    cout << "After Deleting 1...\n";
//    tree->deleteNode(1);
//    tree->printInorder();
//
//    cout << "After Deleting 10...\n";
//    tree->deleteNode(10);
//    tree->printInorder();
//
//    cout << "After Deleting 25...\n";
//    tree->deleteNode(25);
//    tree->printInorder();
//
//    cout << "After Deleting 2...\n";
//    tree->deleteNode(2);
//    tree->printInorder();
//
//    cout << "After Deleting 5...\n";
//    tree->deleteNode(5);
//    tree->printInorder();
//
//    cout << "After Deleting 20...\n";
//    tree->deleteNode(20);
//    tree->printInorder();
//
//    cout << "After Deleting 30...\n";
//    tree->deleteNode(30);
//    tree->printInorder();
}
