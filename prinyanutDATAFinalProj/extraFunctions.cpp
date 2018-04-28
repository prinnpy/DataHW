/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: Oscar's Database final project
 Due Date: May 2 2018
 */

#include "extraFunctions.h"

//valid menu
bool validMenu(char menu) {
    
    bool validMenuInput = false;
    
    //check for match
    if (isdigit(menu) || menu == 'Q' || menu == 'A' || menu == 'P' || menu == 'N') {
        validMenuInput = true;
    } else {
        cout << "Invalid input! Try again!\n";
    }
    
    //return
    return validMenuInput;
}

//valid input for yes or no
bool validYOrN(char input) {
    
    bool validReturn = false;
    
    //check for match
    if (input == 'Y' || input == 'N') {
        validReturn = true;
    } else {
        cout << "Invalid input! Try again!\n";
    }
    
    //return
    return validReturn;
}

//valid numbers when cin
bool validNumbers() {
    bool validValue = false;
    
    //check for valid input
    if (!cin) {
        cin.clear();
        cin.ignore();
        cout << "\nInvalid Input\n";
    } else {
        validValue = true;
    }
    
    //return
    return validValue;
}

//converting string to double
double stringToDouble(string num) {
    double number;
    //convert to double
    stringstream ss(num);
    ss >> number;
    //return
    return number;
}

//converting string to int
int stringToInt(string num) {
    
    int number;
    //convert to int
    stringstream ss(num);
    ss >> number;
    //return
    return number;
    
}

//convert string to bool
bool stringToBool(string value) {
    bool TorF;
    //if for return bool
    if (value == "1") {
        TorF = true;
    } else {
        TorF = false;
    }
    //return
    return TorF;
}

//print vector for actor/actress
void printActorVector(vector<ActorData> &v) {
    
    //print out vector
    cout << "\nSearch Result(s): \n";
    cout << "---------------\n";
    for (int i = 0; i < v.size();i++) {
        cout << i + 1 << ". " << v[i].year << ", " <<  v[i].award << ", " <<  v[i].winner << ", " <<  v[i].name << ", " <<  v[i].film << endl << endl;
    }
}

//print vector for picture
void printPictureVector(vector<PictureData> &v) {
    
    //print out vector
    cout << "\nSearch Result(s): \n";
    cout << "---------------\n";
    for (int i = 0; i < v.size();i++) {
        cout << i + 1 << ". " << v[i].name << ", " << v[i].year << ", " << v[i].nominations << ", " << v[i].rating << ", " << v[i].duration << ", " << v[i].genre1 << ", " << v[i].genre2 << ", " << v[i].release << ", " << v[i].metacritic << ", " << v[i].synopsis << endl << endl;
    }
}


