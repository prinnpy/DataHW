/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW03
 Due Date: Feb 15 2018
 */

#include <iostream>
#include "Vehicle.h"
#include "functions.h"
using namespace std;

int main() {
    
    //car vec
    vector<Vehicle> car_list;
    read_file(car_list);
    
//    for (int i = 0; i < car_list.size();i++) {
//        cout << "\nYear: " <<car_list[i].get_year() << endl;
//        cout << "Make: " <<car_list[i].get_make() << endl;
//        cout << "Model: " <<car_list[i].get_model() << endl;
//
//    }
    
    //set values
    int make = 1, model = 2, year = 3;
    
    //welcome message
    std::cout << "-----------------------------" << endl;
    std::cout << "Welcome to the search Program" << endl;
    std::cout << "-----------------------------" << endl;
    //init this for the do-while loop
    char done = 'n';
    
    //do-while loop
    do {
        
        //start menu
        std::cout << "\nPlease enter your option below." << endl;
        std::cout << "Enter 1 for recursive search by make" << endl;
        std::cout << "Enter 2 for recursive search by model" << endl;
        std::cout << "Enter 3 for recursive search by year" << endl;
        std::cout << "Enter 4 for iterative search by make" << endl;
        std::cout << "Enter 5 for iterative search by model" << endl;
        std::cout << "Enter 6 for iterative search by year" << endl;
        std::cout << "Enter 7 to exit program" << endl;
        int menu;
        std::cin >> menu;
        
        
        //start switch case to call functions menus
        switch (menu) {
                
            case 1: {
                //recursive search by make
                string target;
                cout << "What is the car make you want to search?" << endl;
                cin.ignore();
                getline(cin, target);
                
                //sort funciton pass in vec and make
                sort_func(car_list, make);
                
                //search function
                int found = binSearchRec(car_list, target, 0, car_list.size() - 1, make);
                
                //check is found > 0
                if (found < 0) {
                    cout << "\nRecord not found!" << endl;
                }
                else {
                    print_found(car_list, found);
                }
                
                break;
            }
                
            case 2: {
                //recursive search by model
                string target;
                cout << "What is the car model you want to search?" << endl;
                cin.ignore();
                getline(cin, target);
                
                //sort funciton pass in vec and model
                sort_func(car_list, model);
                
                //recursive func for model
                int found = binSearchRec(car_list, target, 0, car_list.size() - 1, model);
                
                //check is found > 0
                if (found < 0) {
                    cout << "\nRecord not found!" << endl;
                }
                else {
                    print_found(car_list, found);
                }
                break;
            }
                
            case 3: {
                //recursive search by year
                int target;
                cout << "What is the car year you want to search?" << endl;
                cin >> target;
                
                //sort funciton pass in vec and year
                sort_func(car_list, year);
                
                //recursive func for year
                int found = binSearchRecYear(car_list, target, 0, car_list.size() - 1);
                
                //check is found > 0
                if (found < 0) {
                    cout << "\nRecord not found!" << endl;
                }
                else {
                    print_found(car_list, found);
                }
                break;
            }
                
            case 4: {
                //iterative search by make
                string target;
                cout << "What is the car make you want to search?" << endl;
                cin.ignore();
                getline(cin, target);
                
                //sort funciton pass vec and make
                sort_func(car_list, make);
                
                //iter func for make
                int found = binarySearchIter(car_list, target, 0, car_list.size() - 1, make);
               
                //check is found > 0
                if (found < 0) {
                    cout << "\nRecord not found!" << endl;
                }
                else {
                    print_found(car_list, found);
                }
                break;
            }
            
            case 5: {
                //iterative search by model
                string target;
                cout << "What is the car model you want to search?" << endl;
                cin.ignore();
                getline(cin, target);
                
                //sort funciton pass in vec and model
                sort_func(car_list, model);
                
                //iter func for model
                int found = binarySearchIter(car_list, target, 0, car_list.size() - 1, model);
                
                //check is found > 0
                if (found < 0) {
                    cout << "\nRecord not found!" << endl;
                }
                else {
                    print_found(car_list, found);
                }
                break;
            }
            
            case 6: {
                //iterative search by year
                int target;
                cout << "What is the car year you want to search?" << endl;
                cin >> target;
                
                //sort funciton pass in vec and year
                sort_func(car_list, year);
                
                //iter func for year
                int found = binarySearchIterYear(car_list, target, 0, car_list.size() - 1);
                
                //check is found > 0
                if (found < 0) {
                    cout << "\nRecord not found!" << endl;
                }
                else {
                    print_found(car_list, found);
                }
                break;
            }
                
            case 7: {
                //exit program
                done = 'y';
                break;
            }
                
            //validation for the menu
            default:
                cout << "Invalid response. Please enter again" << endl; //make sure user enter the right input
                
        }//switch
        
    }//do
    
    while (done != 'y');
    
    //clear vec after
    car_list.clear();
    
    return 0;
    
    
}
