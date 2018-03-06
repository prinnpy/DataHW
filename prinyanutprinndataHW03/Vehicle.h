/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW03
 Due Date: Feb 15 2018
 */

#ifndef Vehicle_h
#define Vehicle_h

//includes
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//Vehicle class
class Vehicle {
    
private:
    int year;
    string make;
    string model;
public:
    //constructors
    Vehicle(): year(0), make(" "), model(" "){};
    
    //set
    void set_year(int _year) {year = _year;}
    void set_make(string _make) {make = _make;}
    void set_model(string _model) {model = _model;}
    
    //get
    int get_year(){return year;}
    string get_make(){return make;}
    string get_model(){return model;}
    
};

#endif /* Vehicle_h */
