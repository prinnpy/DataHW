/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW03
 Due Date: Feb 15 2018
 */

#include "Vehicle.h"
#include "functions.h"


//read in file function
void read_file(vector<Vehicle> &_car_info_vec) {
    
    //open file
    ifstream inFile;
    
    //open text file
    inFile.open("/Users/itzpr1nn/Desktop/vehiclein.txt");
    
    int temp_year;
    string temp_make, temp_model;
    
    //loop for reading in file
    while (inFile >> temp_year) {
        
        //create temp class
        Vehicle temp_car;
        
        //put in temp info
        inFile.ignore();
        getline(inFile, temp_make);
        getline(inFile, temp_model);
        
        //set values of temp car
        temp_car.set_year(temp_year);
        temp_car.set_make(temp_make);
        temp_car.set_model(temp_model);
        
        //put onject back into vector
        _car_info_vec.push_back(temp_car);
        
    }
    //close file
    inFile.close();
    
}


//sort function
void sort_func(vector<Vehicle> &_car_info_vec, int value) {
    
    //start bubble sort by make
    if (value == 1) {
        
        //bubble sort
        for (int i = 0 ; i < _car_info_vec.size() - 1; i++) {
            for (int k = 0 ; k < _car_info_vec.size() - 1 - i; k++) {
                if (_car_info_vec[k].get_make() > _car_info_vec[k + 1].get_make()) {
                    swap(_car_info_vec[k],_car_info_vec[k + 1]);
                }//if
            }//for
        }//for
        
    }
    
    //start bubble sort by model
    if (value == 2) {
        
        //bubble sort
        for (int i = 0 ; i < _car_info_vec.size() - 1; i++) {
            for (int k = 0 ; k < _car_info_vec.size() - 1 - i; k++) {
                if (_car_info_vec[k].get_model() > _car_info_vec[k + 1].get_model()) {
                    swap(_car_info_vec[k],_car_info_vec[k + 1]);
                }//if
            }//for
        }//for
        
    }
    
    //start bubble sort by model
    if (value == 3) {
        
        //bubble sort
        for (int i = 0 ; i < _car_info_vec.size() - 1; i++) {
            for (int k = 0 ; k < _car_info_vec.size() - 1 - i; k++) {
                if (_car_info_vec[k].get_year() > _car_info_vec[k + 1].get_year()) {
                    swap(_car_info_vec[k],_car_info_vec[k + 1]);
                }//if
            }//for
        }//for
        
    }
    
}

//swap func
void swap(Vehicle &a, Vehicle &b)
{
    Vehicle temp = a;
    a = b;
    b = temp;
}

//print function
void print_found(vector<Vehicle> vec, int found) {
    cout << "\nYear: " <<vec[found].get_year() << endl;
    cout << "Make: " <<vec[found].get_make() << endl;
    cout << "Model: " <<vec[found].get_model() << endl;
}

//recursive search for make and model
int binSearchRec(vector<Vehicle> vec, string target, int start, int last, int value) {
  
    int index = 0;
    
    //bin search rec for make
    if (value == 1) {
        
        //check for bounds
        if (start > last) {
            index = -1;
        }
        else {
            //calculate mid point
            int mid = start + (last - start) / 2;
            
            //compare
            if (vec[mid].get_make() == target) {
                index = mid;
            } else if (vec[mid].get_make() > target) {
                index =  binSearchRec(vec, target, start, mid - 1, value);
            } else {
                index = binSearchRec(vec, target, mid + 1,last, value);
            }
        }
    }
    
    //bin search rec for model
    if (value == 2) {
    
        //check for bounds
        if (start > last) {
            index = -1;
        }
        else {
            //calculate mid point
            int mid = start + (last - start) / 2;
            
            //compare
            if (vec[mid].get_model() == target) {
                index = mid;
            } else if (vec[mid].get_model() > target) {
                index =  binSearchRec(vec, target, start, mid - 1, value);
            } else {
                index = binSearchRec(vec, target, mid + 1, last, value);
            }
        }
    }
    
    return index;
    
}

//binary recursive for year
int binSearchRecYear(vector<Vehicle> vec, int target, int start, int last) {
    
    int index = 0;
    
    //check for bounds
    if (start > last) {
        index = -1;
    }
    else {
        //calculate mid point
        int mid = start + (last - start) / 2;
        
        //compare
        if (vec[mid].get_year() == target) {
            index = mid;
        } else if (vec[mid].get_year() > target) {
            index =  binSearchRecYear(vec, target, start, mid - 1);
        } else {
            index = binSearchRecYear(vec, target, mid + 1, last);
        }
    }
    
    return index;
}

//iteration search for make and model
int binarySearchIter(vector<Vehicle> vec, string target, int start, int last, int value) {
    
    bool found = false;
    int index = -1;
    
    //bin search iter for make
    if (value == 1) {
        
        //loop to find make matching index
        while (!found && start <= last) {
            
            //find midpoint
            int mid = start + (last - start) / 2;
            
            //compare
            if (vec[mid].get_make() == target) {
                index = mid;
                found = true;
            } else if (vec[mid].get_make() < target) {
                start = mid + 1;
            } else {
                last = mid - 1;
            }
        }//while
        
    }
    
    //bin search iter for model
    if (value == 2) {
        
        //loop to find model matching index
        while (!found && start <= last) {
            
            //find midpoint
            int mid = start + (last - start) / 2;
            
            //compare
            if (vec[mid].get_model() == target) {
                index = mid;
                found = true;
            } else if (vec[mid].get_model() < target) {
                start = mid + 1;
            } else {
                last = mid - 1;
            }
        }//while
        
    }
    
    return index;
    
}

//iteration search for year
int binarySearchIterYear(vector<Vehicle> vec, int target, int start, int last) {
    
    bool found = false;
    int index = -1;
    
    //loop to find year matching index
    while (!found && start <= last) {
        
        //find midpoint
        int mid = start + (last - start) / 2;
        
        //compare
        if (vec[mid].get_year() == target) {
            index = mid;
            found = true;
        } else if (vec[mid].get_year() < target) {
            start = mid + 1;
        } else {
            last = mid - 1;
        }
        
    }//while
    
    return index;
    
}



    




