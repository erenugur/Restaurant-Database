/* Restaurant.cpp --------------------------------------------------------------
   Cpp file that defines the following public functions of the 
   LinkedList_Database class:
   constructor, destructor, empty(), insertOwner(), insertChef(), insertWaiter(),
   displayStatistics()
   -----------------------------------------------------------------------*/
#include <iostream>
#include "Restaurant.h"

//--- Definition of LinkedList_Database Constructor
LinkedList_Database::LinkedList_Database() {
    head = nullptr;
    tail = nullptr;
}

//--- Definition of LinkedList_Database Destructor
LinkedList_Database::~LinkedList_Database() { 
    Employee* prev = head;
    Employee* ptr;
    while (prev != nullptr) {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

//--- Definition of LinkedList_Database's empty()
bool LinkedList_Database::empty() const { 
   return (head == nullptr); 
}

//--- Definition of LinkedList_Database's insertOwner()
void LinkedList_Database::insertOwner(const string& name, const int& employeeID, const char& employeeClass, const double& salary, const int& profit) {
    Employee* newptr = new Owner(name, employeeID, employeeClass, salary, profit);
    if (empty()) {
        tail = newptr;
        head = newptr;
    }
    else {
        tail->next = newptr;
        tail = newptr;
    }
}

//--- Definition of LinkedList_Database's insertChef()
void LinkedList_Database::insertChef(const string& name, const int& employeeID, const char& employeeClass, const double& salary, const string& cuisineOfExpertise, const int& profit) {
    Employee* newptr = new Chef(name, employeeID, employeeClass, salary, cuisineOfExpertise, profit);
    if (empty()) {
        tail = newptr;
        head = newptr;
    }
    else {
        tail->next = newptr;
        tail = newptr;
    }
}

//--- Definition of LinkedList_Database's insertWaiter()
void LinkedList_Database::insertWaiter(const string& name, const int& employeeID, const char& employeeClass, const double& salary, const int& yearsOfService, const int& tips) {
    Employee* newptr = new Waiter(name, employeeID, employeeClass, salary, yearsOfService, tips);
    if (empty()) {
        tail = newptr;
        head = newptr;
    }
    else {
        tail->next = newptr;
        tail = newptr;
    }
}

//--- Definition of LinkedList_Database's displayStatistics()
void LinkedList_Database::displayStatistics(ostream & out) const {
   Employee* ptr;
   out << endl << " --- Statistics --- " << endl;
   for (ptr = head; ptr != nullptr; ptr = ptr->next) {
        ptr->display(out);
   }
   out << endl;
}



