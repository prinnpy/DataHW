/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: Oscar's Database final project
 Due Date: May 2 2018
 */

#ifndef actor_h
#define actor_h

//includes
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Node.h"
#include "BSTree.h"
#include "BSTree.hpp"
#include "extraFunctions.h"

//add (worked!)
void actorAdd(BSTree<ActorData, string> *actorTree);
//modify (worked!)
void actorModify(BSTree<ActorData, string> *actorTree);
//delete (worked!)
void actorDelete(BSTree<ActorData, string> *actorTree);
//sort (worked!)
void actorSort(BSTree<ActorData, string> *actorTree);
void bstToVector(Node<ActorData, string> *actorNode, vector<ActorData> &v);
//complete (worked!)
void actorCompleteSearch(BSTree<ActorData, string> *actorTree);
void foundCompleteIntSearch(Node<ActorData, int> *actorNode, vector<ActorData> &v, int value);
void foundCompleteStringSearch(Node<ActorData, string> *actorNode, vector<ActorData> &v, string value);
void secondCompleteSearch(vector<ActorData> &v);
//partial search (worked!)
void actorPartialSearch(BSTree<ActorData, string> *actorTree);
void foundPartialIntSearch(Node<ActorData, int> *actorNode, vector<ActorData> &v, int value);
void foundPartialStringSearch(Node<ActorData, string> *actorNode, vector<ActorData> &v, string value);
void secondPartialSearch(vector<ActorData> &v);
//print to file (worked!)
void writeActorDatabase(BSTree<ActorData, string> *actorTree);

#endif /* options_h */
