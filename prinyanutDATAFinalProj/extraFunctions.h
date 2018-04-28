/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: Oscar's Database final project
 Due Date: May 2 2018
 */

#ifndef extraFunctions_h
#define extraFunctions_h

//includes
#include <iostream>
#include <sstream>
#include <vector>
#include "Node.h"
using namespace std;

//extra functions
bool validMenu(char menu);
bool validYOrN(char input);
bool validNumbers();
bool stringToBool(string value);
int stringToInt(string num);
double stringToDouble(string num);
void printActorVector(vector<ActorData> &v);
void printPictureVector(vector<PictureData> &v);

#endif /* extraFunctions_h */
