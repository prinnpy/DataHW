/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: HW07
 Due Date: Mar 29 2018
*/

#include "function.h"

//got steps from stackoverflow, but I implemented this myself
bool operator < (const Customer& a, const Customer& b) {
    
    Customer temp1 = a,temp2 = b;
    
    if (a.getTime() != b.getTime())
        return a.getTime() > b.getTime();
    else {
        return temp2.getAction().append(temp1.getAction()) > temp1.getAction().append(temp2.getAction());
    }
    
}

//run simulation function
void runSimulation() {
    
    //create priority_queue
    priority_queue<Customer> q;
    
    //vars
    int inputCustomerArriveTime, inputTimeWait, nextStartServing = 0;
    Customer customer;
    bool firstArrival = true;
    int cusomterCount = 0;
    float waitTimeCount = 0.0;
    
    //open file
    ifstream inFile("hw7input.txt");
    
    //while input data
    while (inFile >> inputCustomerArriveTime >> inputTimeWait){
        
        //this only applies for the first customer
        if (firstArrival) {
            nextStartServing = inputCustomerArriveTime;
            firstArrival = false;
        }
        
        //set arrival action and time then push to queue
        customer.setAction("an arrival");
        customer.setTime(inputCustomerArriveTime);
        q.push(customer);
        
        //do total wait time calculation and save the last departure to be new start
        if (nextStartServing > inputCustomerArriveTime){
            waitTimeCount += nextStartServing - inputCustomerArriveTime;
            inputCustomerArriveTime = nextStartServing;
        } else {
            nextStartServing = inputCustomerArriveTime;
        }
        
        //set departure action and time then push to queue
        nextStartServing += inputTimeWait;
        customer.setAction("a departure");
        customer.setTime(nextStartServing);
        q.push(customer);
        
        //count customer
        cusomterCount += 1;
        
    }
    
    //get size
    unsigned long size = q.size();
    
    //print out results
    cout << "\nSimilation Begins\n";
    cout << "-----------------\n";
    for (int i = 0; i < size; i++) { //loop for printing out items in queue
        cout<< "Processing " << q.top().getAction() << " event at time: " << q.top().getTime() <<"\n";
        q.pop();
    }
    cout << "---------------\n";
    cout << "Simulation Ends\n\n";
    cout << "Final Statistics:\n";
    cout << "=================\n";
    cout << "Total number of people processed: " << cusomterCount << endl;
    cout << "Average amount of time spent waiting: " << waitTimeCount / cusomterCount << endl << endl;
    

}

