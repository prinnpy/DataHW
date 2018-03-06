/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW02
 Due Date: Feb 8 2018
 */

//includes
#include <iostream>
#include <fstream>
#include "ArrayBag.h"
using namespace std;

//main
int main () {
    
    //creat 4 objects
    ArrayBag obj1, obj2, obj3, obj4;
    
    //call read file then pass in object 1 and 2
    obj1.read_file(obj1, obj2);
    
    //print object 1 and 2 (which are from the input files)
    cout << "Obj1:\n";
    obj1.print_object();
    cout << endl;
    cout << "Obj2:\n";
    obj2.print_object();
    
    //use the + operator
    obj3 = obj1 + obj2;
    
    //print out obj3 results
    cout << endl;
    cout << "OBJ3: \n";
    obj3.print_object();
    
    //use the - operator
    obj4 = obj1 - obj2;
    
    //print out obj4 results
    cout << endl;
    cout << "OBJ4: \n";
    obj4.print_object();
    
    
    return 0;
}
