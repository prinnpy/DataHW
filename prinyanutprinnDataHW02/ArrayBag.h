//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove templates and Inheritance

/** ADT bag: Array-based implementation.
 @file ArrayBag.h */
/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW02
 Due Date: Feb 8 2018
 */

#ifndef BAG_H
#define BAG_H

#include <vector>

typedef int ItemType;

//class arraybag
class ArrayBag {
private:
    static const int DEFAULT_BAG_SIZE = 100;
	ItemType items[DEFAULT_BAG_SIZE]; // array of bag items
    int itemCount;                    // current count of bag items
    int maxItems;                     // max capacity of the bag
   
    // Returns either the index of the element in the array items that
    // contains the given target or -1, if the array does not contain
    // the target.
    int getIndexOf(const ItemType& target) const;

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
    
    //my functions
    void read_file(ArrayBag &obj1, ArrayBag &obj2);
    void print_object();
    //overloading operator functions
    ArrayBag operator + (ArrayBag &obj_plus);
    ArrayBag operator - (ArrayBag &obj_minus);
    
};  // end Bag


#endif
