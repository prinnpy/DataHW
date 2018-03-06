/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW06
 Due Date: Mar 8 2018
 */

#ifndef Dictionary_h
#define Dictionary_h

//include
#include "DictEntry.h"

class Dictionary {
private:
    list<DictEntry> dictList;
    list<DictEntry> findWords;
public:
    //default constructor
    Dictionary(): dictList(), findWords(){};
    
    //member functions prototypes
    void loadWords();
    void printDictList();
    void printFindWords();
    void compareFromFront();
    void compareFromBack();
    
};

#endif /* Dictionary_h */
