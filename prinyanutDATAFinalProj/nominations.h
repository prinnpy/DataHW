/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: Oscar's Database final project
 Due Date: May 2 2018
 */

#ifndef nominations_h
#define nominations_h

//include
#include "actor.h"

//prototypes
void printWinner(BSTree<ActorData, string> *nominationsTree);
void printWonActor(BSTree<ActorData, string> *nominationsTree);
void ActorVSActressNominations(BSTree<ActorData, string> *nominationsTree);
void printTitleContainsThe(BSTree<ActorData, string> *nominationsTree);


#endif /* nominations_h */
