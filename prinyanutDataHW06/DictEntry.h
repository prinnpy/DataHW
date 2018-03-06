/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW06
 Due Date: Mar 8 2018
 */

#ifndef DICTENTRY_H
#define DICTENTRY_H

//includes
#include <string>
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

typedef std::string wordType;

class DictEntry
{
private:
    wordType word;
    wordType definition;
    
public:
    DictEntry(): word(""), definition(""){};
    wordType getWord(){return word;}
    void setWord(wordType _word){word = _word;}
    wordType getDef(){return definition;}
    void setDef(wordType _def){definition = _def;}
    bool operator < (const DictEntry &entry) const {
        return (word < entry.word);}
    
    //overloading << operator
    friend ostream& operator << (ostream &out, DictEntry &list) {
        out << list.getWord();
        return out;
    }
    
    
};

#endif

