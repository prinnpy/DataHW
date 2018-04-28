/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: Oscar's Database final project
 Due Date: May 2 2018
 */

#ifndef functions_h
#define functions_h

//includes
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Node.h"
#include "BSTree.h"
#include "actor.h"
#include "pictures.h"
#include "nominations.h"
#include "extraFunctions.h"
using namespace std;

//reading in from files (worked!)
void readActorActressFile(BSTree<ActorData, string> *actorTree);
void readPicturesFile(BSTree<PictureData, string> *picturesTree);
void readNominationFile(BSTree<ActorData, string> *nominationsTree);

//access databases (worked!)
void actorDatabase(BSTree<ActorData, string> *actorTree);
void picturesDatabase(BSTree<PictureData, string> *picturesTree);
void nominationsDatabase(BSTree<ActorData, string> *nominationsTree);


#endif /* functions_h */
