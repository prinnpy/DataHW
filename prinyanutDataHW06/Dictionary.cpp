/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW06
 Due Date: Mar 8 2018
 */

//include
#include "Dictionary.h"

//function that loads in words from text file
void Dictionary::loadWords(){
    
    //loop that can read in both file separately
    for (int i = 0; i < 2; i++){
        
        //reading in for dict
        if (i == 0) {
            
            //open file
            ifstream inFile;
            inFile.open("dictionary.txt");
            
            //create temp
            DictEntry temp_dict;
            string temp_string;
            
            //loop to put data into dict list
            while (inFile >> temp_string) {
                temp_dict.setWord(temp_string);
                this->dictList.push_back(temp_dict);
            }
            //close file
            inFile.close();
            
        }
        
        //reading in for find words
        if (i == 1) {
            
            //open file
            ifstream inFile;
            inFile.open("findwords.txt");
            
            //temp vars
            DictEntry temp_dict;
            string temp_string;
            
            //loop that put data into find words list
            while (inFile >> temp_string) {
                temp_dict.setWord(temp_string);
                this->findWords.push_back(temp_dict);
            }
            
            //close file
            inFile.close();
        }
    }
}

//function that prints out dict list
void Dictionary::printDictList() {
    
    //sorted list
    this->dictList.sort();
    
    //loop to print out all items in sorted dict list
    list<DictEntry>::iterator i;
    for (i = this->dictList.begin(); i != this->dictList.end(); i++)
        cout << *i << endl;
    
}

//function that prints out find words list
void Dictionary::printFindWords() {
    
    //loop to print out all items in find words list
    list<DictEntry>::iterator i;
    for (i = this->findWords.begin(); i != this->findWords.end(); i++)
        cout << *i << endl;
    
}

//function that compare dict list and find word list from front
void Dictionary::compareFromFront() {
    
    //create iterator
    list<DictEntry>::iterator i;
    list<DictEntry>::iterator k;
    
    //start count
    int count = 0;
    
    //loop that compare 2 list from front
    for (i = findWords.begin(); i != findWords.end(); i++) {
        count = 0;
        for (k = dictList.begin(); k != dictList.end(); k++) {
            //if found count++ and print how many times it loop through before it's found
            if (k->getWord() == i->getWord()) {
                count++;
                cout << "Found: " << i->getWord() << endl;
                cout << "This searches " << count << " time(s) to find: " << i->getWord() << endl;
                break;
            }
            count++;
        }
    }
    
}

//function that compare dict list and find word list from front
void Dictionary::compareFromBack() {
    
    //create outfile for putting data into revsorted.txt
    ofstream outfile;
    outfile.open("revsorted.txt", std::fstream::app);
    string tempWord;
    
    //create iterator
    list<DictEntry>::reverse_iterator i;
    list<DictEntry>::reverse_iterator k;
    
    //start count
    int count = 0;
    
    //loop that compare 2 list from back(reverse)
    for (i = findWords.rbegin(); i != findWords.rend(); i++) {
        count = 0;
        for (k = dictList.rbegin(); k != dictList.rend(); k++) {
            //if found print the word to new file, and count++ also print how many times it loop through before it's found
            if (k->getWord() == i->getWord()) {
                tempWord = i->getWord();
                outfile << tempWord << " ";
                count++;
                cout << "Found: " << i->getWord() << endl;
                cout << "This searches " << count << " time(s) to find: " << i->getWord() << endl;
                break;
            }
            count++;
        }
    }
}


