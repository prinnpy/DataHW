/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW05
 Due Date: Mar 1 2018
 */

#include <iostream>
#include "LinkList.h"

int main() {
    
    //create linklist
    LinkedList list;
    
    //trying to delete empty list
    cout << "---------------------------\n";
    cout << "Trying to delete empty list\n";
    cout << "---------------------------\n\n";
    cout << "Deleting back: \n";
    list.deleteAtBack();
    cout << endl;
    cout << "Deleting front: \n";
    list.deleteAtFront();
    cout << endl;
    cout << "Deleting at index: \n";
    list.deletePosition(0);
    cout << endl;
    
    //trying to insert empty list
    cout << "-----------------------------------------\n";
    cout << "Trying to insert empty list at a position\n";
    cout << "-----------------------------------------\n\n";
    cout << "Insert at index 0: \n";
    list.insertBeforePosition('a', 0);
    cout << endl;
    
    //insert item to list
    cout << "-------------------\n";
    cout << "Insert item to list\n";
    cout << "-------------------\n\n";
    cout << "Insert 'b,a' to front: \n";
    list.insertAtFront('b');
    list.insertAtFront('a');
    cout << list;
    cout << endl;
    cout << "Insert 'c,d' to back: \n";
    list.insertAtBack('c');
    list.insertAtBack('d');
    cout << list;
    cout << endl;
    cout << "Insert 'e' to position 2: \n";
    list.insertBeforePosition('e', 2);
    cout << list;
    cout << endl;
    
    //delete item from list
    cout << "-------------------\n";
    cout << "Delete item to list\n";
    cout << "-------------------\n\n";
    cout << "Delete 'e' from position 2: \n";
    list.deletePosition(2);
    cout << list;
    cout << endl;
    cout << "Delete 'a' from front: \n";
    list.deleteAtFront();
    cout << list;
    cout << endl;
    cout << "Delete 'd' from back: \n";
    list.deleteAtBack();
    cout << list;
    cout << endl;
    
    //check for index bounds for insert and delete
    cout << "-------------------------------\n";
    cout << "Check if index is out of bounds\n";
    cout << "-------------------------------\n\n";
    cout << "Check out of bounds for insert at index 20:\n";
    list.insertBeforePosition('d', 20);
    cout << endl;
    cout << "Check out of bounds for delete at index 20:\n";
    list.deletePosition(20);
    cout << endl;
    
    //clear all items in list
    cout << "----------\n";
    cout << "Clear list\n";
    cout << "----------\n\n";
    cout << "Before clear list:\n";
    cout << list;
    cout << endl;
    list.~LinkedList();
    cout << "After clear list:\n";
    cout << list;
    cout << endl;
    
    
    return 0;
}
