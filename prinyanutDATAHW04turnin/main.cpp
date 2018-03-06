/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW04
 Due Date: Feb 22 2018
 */


#include <iostream>
#include "MyVector.h"

int main() {
    
    //create vec
    HW4::MyVector vec;
    
    //check if it's empty
    cout << "Check is vector is empty using .empty\n";
    bool check = vec.empty();
    
    //print if vec was empty
    if (check) {
        cout << "Vector is empty\n";
    } else {
        cout << "Vector is not empty\n";
    }
    
    //push back vec
    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(300);
    
    //print out vec
    cout << "\nUsing .push_back\n";
    for (int i = 0; i < vec.size(); i++) {
        cout << "Item in index " << i << " = " << vec[i] << endl;
    }
    
    //pop back vec and print result
    vec.pop_back();
    cout << "\nUsing .pop_back\n";
    for (int i = 0; i < vec.size(); i++) {
        cout << "Item in index " << i << " = " << vec[i] << endl;
    }
    
    //search for 200
    cout << "\nSearch for 200\n";
    int num = vec.search(200);
    
    //if found print
    if (num < 0) {
        cout << "search not found\n\n";
    } else {
        cout << "search found!\n\n";
    }
 
}
