/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW07
 Due Date: Mar 29 2018
*/

#ifndef Events_h
#define Events_h

//includes
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

//Events class
class Customer {
private:
    string action;
    int time;
public:
    
    //default constructor
    Customer(): action(""), time(0){};
    
    //set
    void setAction(string action){this->action = action;}
    void setTime(int time){this->time = time;}
    
    //get
    string getAction() const {return this->action;}
    int getTime() const {return this->time;}
    
};


#endif /* Events_h */
