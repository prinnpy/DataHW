/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW04
 Due Date: Feb 22 2018
 */

//include
#include "MyVector.h"

//for overloading the operator
HW4::T HW4::MyVector::operator[](int index) {
    
    //check if index is bigger than size
    if (index >= vsize){ //f(1)
        cout << "out of bounds\n";//f(1)
    }
    return vec[index];//f(1)
    
    //total = f(3)
    //O(1)
}

//function for pop back
void HW4::MyVector::pop_back() {
    //create a temp pointer
    int *ptr;//f(1)
    //if size = 0 print empty
    if (vsize == 0) {//f(1)
        cout << "This is empty\n";//f(1)
    }
    //else - 1 from size then use new pointer to point to it
    else if (vsize != 0) {//f(1)
        vsize -= 1;//f(1)
        ptr = new T[vsize - 1];//f(1)
    }
    
    //total = f(6)
    //O(1)

}

//function for push back
void HW4::MyVector::push_back(T value) {
    //if empty add 1 to size then set index 0 to value
    if (vsize == 0) {//f(1)
        vsize += 1;//f(1)
        vec = new T[vsize];//f(1)
        vec[0] = value;//f(1)
    }
    //else add 1 to size then set value to the end of vec
    else if (vsize != 0) {//f(1)
        vsize += 1;//f(1)
        vec[vsize - 1] = value;//f(1)
    }
    
    //total = f(7)
    //O(1)

}

//funciton to check if vec is empty
bool HW4::MyVector::empty() {
    
    bool empty = false;
    
    //check if size = 0
    if (vsize == 0) {
        empty = true;
    }
    
    //return bool value
    return empty;
    
}

//function for searching in vec
int HW4::MyVector::search(T Value) {
    
    //set search to -1 in case of not found
    int search = -1; //f(1)
    
    //linear search
    for (int i = 0; i < this->size(); i++) {//f(n)
        if (Value == vec[i]) {//f(1)
            search = Value;//f(1)
        }
    }
    //return value
    return search;//f(1)

    //total = f(4) + f(n)
    //O(n)
  
}
