/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW05
 Due Date: Mar 1 2018
 */

#ifndef LinkList_h
#define LinkList_h

#include<iostream>
using namespace std;

struct Node
{
    char data = 0;
    Node* nextPtr = nullptr;
};

class LinkedList
{
private:
    Node *headPtr;
public:
    LinkedList(): headPtr(nullptr){};
    ~LinkedList(){clear();};
    
    Node *getHeadPtr(){return this->headPtr;}
    
    bool insertAtFront(char value);
    bool insertBeforePosition(char value, int index);
    //first Node after headptr is 1
    //false if pos zero or out of range
    bool insertAtBack(char value);
    
    bool deleteAtFront();
    bool deletePosition(int index);
    //first Node after headptr is 1
    //false if pos zero or out of range
    bool deleteAtBack();
    //false if empty
    
    void clear(); //frees memory for entire list
    friend ostream& operator << (ostream &out, LinkedList &list);
};


#endif /* LinkList_h */
