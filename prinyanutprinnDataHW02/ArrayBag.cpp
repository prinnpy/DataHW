//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove Template and Inheritance
/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW02
 Due Date: Feb 8 2018
 */

/** @file ArrayBag.cpp */

//includes
#include <iostream>
#include <fstream>
#include <sstream>
#include "ArrayBag.h"
using namespace std;

ArrayBag::ArrayBag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{
}  // end default constructor

//print function
void ArrayBag::print_object(){
    
    //loop items
    for (int i = 0; i < itemCount; i++){
        
        cout << items[i] << endl;
    }
}

//read file function
void ArrayBag::read_file(ArrayBag &obj1, ArrayBag &obj2){
    
    fstream infile;
    //open file
    infile.open("/Users/itzpr1nn/Desktop/setInput.txt");
    
    //loop for reading in 2 lines
    for (int i = 0; i < 2; i++){
        string temp_string;
        //read in line 1
        if (i == 0) {
            getline(infile, temp_string);
            stringstream ss(temp_string);
            int temp_int;
            //convert to integers
            while (ss >> temp_int) {
                //add to object
                obj1.add(temp_int);
            }
        } else {
            //read in line 2
            getline(infile, temp_string);
            stringstream ss(temp_string);
            int temp_int;
            //convert to integer
            while (ss >> temp_int) {
                //add to object
                obj2.add(temp_int);
            }//while
        }//else
    }//for
    //close file
    infile.close();
    
}

int ArrayBag::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize


bool ArrayBag::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


bool ArrayBag::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add


bool ArrayBag::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove


void ArrayBag::clear()
{
	itemCount = 0;
}  // end clear


int ArrayBag::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int searchIndex = 0;
   while (searchIndex < itemCount)
   {
      if (items[searchIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      searchIndex++;
   }  // end while
   
   return frequency;
}  // end getFrequencyOf


bool ArrayBag::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

// private

int ArrayBag::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   // if the ArrayBag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf


//overloading operator + function
ArrayBag ArrayBag::operator+(ArrayBag &obj_lhs) {
    
    ArrayBag obj3;
    
    //copy all values into obj3
    for (int i = 0; i < obj_lhs.getCurrentSize(); i++) {
        obj3.add(obj_lhs.items[i]);
    }
    
    //copy the other value into obj3
    for (int i = 0; i < getCurrentSize();i++) {
        obj3.add(items[i]);
    }
    
    //get new current size
    int current_size = obj3.getCurrentSize();
    // //delete duplicate
    for (int i = 0; i < current_size; i++) {
        int mark = obj3.items[i];//get item
        int show = obj3.getFrequencyOf(mark); //check for how many times this item has appear
        //if mark item appear more than 1
        if (show > 1) {
            //remove but only leave 1 item
            for (int k = 0; k < (show - 1); k++){
                obj3.remove(mark);
            }
        }
    }
    //return obj
    return obj3;
}
//overloading operator - function
ArrayBag ArrayBag::operator-(ArrayBag &obj_rhs) {
    
    ArrayBag obj4;
    //copy all values into obj4
    for (int i = 0; i < itemCount;i++) {
        obj4.add(items[i]);
    }
    
    int i = 0;
    //loop to subtract. If the right hand side has more numbers it will remove all items
    while (i < itemCount) {
        //check for duplicates
        for(int k = 0; k < obj_rhs.itemCount;k++) {
            //if same remove
            if (obj_rhs.items[k] == obj4.items[i]) {
                obj4.remove(obj4.items[i]);
            }
        }
        i++;
    }
    
    int current_size = obj4.getCurrentSize();
    //check for duplicates and remove them
    for (int i = 0; i < current_size; i++) {
        int mark = obj4.items[i];
        int show = obj4.getFrequencyOf(mark);
        
        if (show > 1) {
            //remove duplicates
            for (int k = 0; k < (show - 1); k++){
                obj4.remove(mark);
            }
        }
    }
    
    return obj4;
    
}
