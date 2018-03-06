/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW06
 Due Date: Mar 8 2018
 */

//includes
#include "DictEntry.h"
#include "Dictionary.h"

//main func
int main() {
    
    //create object
    Dictionary obj;
    
    //load words
    obj.loadWords();
    
    //print sorted dict entry list
    cout << "Sorted Dictionary: \n";
    obj.printDictList();
    
    //print loaded in find words
    cout << "\nFind words: \n";
    obj.printFindWords();
    
    //compare find words to dict from front of list
    cout << "\nComparing from front: \n";
    obj.compareFromFront();
    
    //compare find words to dict from back of list
    cout << "\nComparing from back: \n";
    obj.compareFromBack();
    
    cout << endl;
    
}
