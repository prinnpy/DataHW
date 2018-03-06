/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW03
 Due Date: Feb 15 2018
 */

#ifndef functions_h
#define functions_h

//includes
#include <iostream>
#include <vector>
#include <fstream>
#include "Vehicle.h"
using namespace std;

//functions
void read_file(vector<Vehicle> &_car_info_vec);
void sort_func(vector<Vehicle> &_car_info_vec, int);
void swap(Vehicle &a, Vehicle &b);
void print_found(vector<Vehicle> vec, int found);

//recursive search
int binSearchRec(vector<Vehicle> vec, string target, int start, int last, int value);
int binSearchRecYear(vector<Vehicle> vec, int target, int start, int last);

//iteration search
int binarySearchIter(vector<Vehicle> vec, string target, int start, int last, int value);
int binarySearchIterYear(vector<Vehicle> vec, int target, int start, int last);



#endif /* functions_h */
