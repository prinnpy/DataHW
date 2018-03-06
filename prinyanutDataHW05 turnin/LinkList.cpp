/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW05
 Due Date: Mar 1 2018
 */

#include "LinkList.h"

//function for inserting value in front of list
bool LinkedList::insertAtFront(char value){
    
    bool insert = true; //f(1)
    
    //create temp new node
    Node *tempPtr = headPtr; //f(1)
    tempPtr = new Node; //f(1)
    tempPtr->data = value; //f(1)
    
    //if the list was empty
    if (tempPtr == nullptr) { //f(1)
        //create new node that headptr point to and set the value
        headPtr = new Node; //f(1)
        headPtr->data = value; //f(1)
        tempPtr->nextPtr = nullptr; //f(1)
    } else {
        //point next temp to what headptr used to point to then point headptr to new node
        tempPtr->nextPtr = headPtr; //f(1)
        headPtr = tempPtr; //f(1)
    }
    
    return insert; //f(1)
}

//function for inserting before a given index
bool LinkedList::insertBeforePosition(char value, int index) {
    
    bool insert = true;
    
    //create currentptr and tempptr for new node
    Node *currentPtr = headPtr;
    Node *tempPtr = new Node;
    tempPtr->data = value;
    
    //check if the list was empty
    if (currentPtr == nullptr) {
        cout << "no item in this list to insert\n";
        insert = false;
    }
    
    //case index = 0 return false
    if (index == 0) {
        insert = false;
    } else if (index == 1) { //if index is one use the insert front algorithm
        tempPtr->nextPtr = headPtr;
        headPtr = tempPtr;
    //if index is more than 1
    } else {
        //if index is more than 2 and check for out of bounds
        for (int i = 0; i < index - 2; i++) {
            currentPtr = currentPtr->nextPtr;
            if (currentPtr == nullptr || currentPtr->nextPtr == nullptr){
                cout << "Index for insert is out of bounds\n";
                return false;
            }
        }
        
        //new node = old node points to, then point old node to new node
        tempPtr->nextPtr = currentPtr->nextPtr;
        currentPtr->nextPtr = tempPtr;
//        delete currentPtr;
        
        
    }
    
    return insert;
}

//function that insert list to the back
bool LinkedList::insertAtBack(char value){
    bool insert = true; //f(1)
    
    //get currptr and create new node and set value to new node
    Node *currentPtr = headPtr; //f(1)
    Node *tempPtr = new Node; //f(1)
    tempPtr->data = value; //f(1)
    
    //check if the list was empty, set headptr to point to new node
    if (currentPtr == nullptr) { //f(1)
        headPtr = tempPtr; //f(1)
        delete currentPtr; //f(1)
    } else {//else get the last node in list 
        while (currentPtr->nextPtr != nullptr) { //f(n)
            currentPtr = currentPtr->nextPtr; //f(1)
        }
        //point last node to new node then point new node to null
        currentPtr->nextPtr = tempPtr; //f(1)
        tempPtr->nextPtr = nullptr; //f(1)
        
    }

    return insert; //f(1)
    
}

//function that delete node at the front
bool LinkedList::deleteAtFront() {
    bool remove = true;
    //create a currptr
    Node *wantToRemovePtr = headPtr;
    
    //check if the list is empty
    if (wantToRemovePtr == nullptr) {
        cout << "no item to delete at front\n";
        return false;
    } else {
        
        //headptr point to the next next one then delete the first node
        headPtr = wantToRemovePtr->nextPtr;
        delete wantToRemovePtr;
    }
    
    return remove;
}

//function that delete node at the back
bool LinkedList::deleteAtBack() {
    bool remove = true;
    
    //find the end and next to end node
    Node *nextToEndPtr = headPtr;
    Node *endPtr = nextToEndPtr;
    
    //check if there's no list in item
    if (nextToEndPtr == nullptr) {
        cout << "no item to delete at back\n";
        return false;
    }
    
    //if there's only 1 item in the list delete that and point head to null
    if (headPtr->nextPtr == nullptr) {
        delete headPtr;
        headPtr = nullptr;
    } else {
        while (endPtr->nextPtr != nullptr) {//get the next to end node
            nextToEndPtr = endPtr;
            endPtr = endPtr->nextPtr;
        }

        //point next to end node to null then delete end node (last node)
        nextToEndPtr->nextPtr = nullptr;
        delete endPtr;
    }
    
    return remove;
}

//function that delete at a given index
bool LinkedList::deletePosition(int index){
    bool remove = true;
    
    Node *currentPtr = headPtr;
    Node *wantToRemovePtr;
    
    //check if list is empty
    if (currentPtr == nullptr) {
        cout << "no item to delete at position\n";
        remove = false;
    }
    
    //index can't be 0
    if (index == 0){
        remove = false;
    } else if (index == 1) { //if index = 1 just delete the front
        this->headPtr = currentPtr->nextPtr;
        delete currentPtr;
    } else {
        //for loop check for if index is 3 or more
        for (int i = 0; i < index - 2; i++) {
            currentPtr = currentPtr->nextPtr;
            //check bounds for index
            if (currentPtr == nullptr || currentPtr->nextPtr == nullptr){
                cout << "Index for delete is out of bounds\n";
                return false;
            }
        }
        //remove ptr and delete node
        wantToRemovePtr = currentPtr->nextPtr;
        currentPtr->nextPtr = wantToRemovePtr->nextPtr;
        delete wantToRemovePtr;

        
    }
    
    return remove;
}

//function for destructors
void LinkedList::clear(){
    
    
    Node *wantToRemovePtr = headPtr;
    Node *temp = headPtr;
    
    //loop for deleting every item in the list
    while (wantToRemovePtr != nullptr) {
        temp = wantToRemovePtr;
        delete wantToRemovePtr;
        wantToRemovePtr = temp->nextPtr;
    }
    
    //set headptr to point to null
    headPtr = nullptr;
    
}

//overloading << operator for LinkedList class to print list
ostream& operator << (ostream& out, LinkedList &list) {
    
    //create temp
    Node *temp = list.getHeadPtr();
    
    //loop that keep print out items in list
    while (temp != nullptr) {
        out << temp->data << endl;
        temp = temp->nextPtr;
    }
    
    return out;
}
