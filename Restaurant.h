/* Restaurant.h --------------------------------------------------------------
   Header file that defines classes "Employee" and "LinkedList_Database" as well
   as derived classes of the "Employee" class called "Owner," "Chef," and "Waiter."
   Operations are: A constructor and an output operation.
   -----------------------------------------------------------------------*/
#include <iostream>
#include <math.h>
using namespace std;

class Employee {
    public:
        string name;
        int employeeID;
        char employeeClass;
        double salary;
        Employee* next;

        //--- Definition of Employee's Constructor
        Employee(string newName, int newEmployeeID, char newEmployeeClass, double newSalary, Employee* link = nullptr) {
            name = newName;
            employeeID = newEmployeeID;
            employeeClass = newEmployeeClass;
            salary = newSalary;
            next = link;
        }

        //--- Definition of Employee's display()
        virtual void display(ostream & out) const {
            out << "Name: " << name << endl 
                << "Employee ID: " << employeeID << endl
                << "Employee Class: " << employeeClass << endl 
                << "Salary: " << salary << " dollars" << endl << endl;
        }
};

class Owner: public Employee {
    public:
        int profit;

        //--- Definition of Owner's Constructor
        Owner(string newName, int newEmployeeID, char newEmployeeClass, double newSalary, int newProfit, Employee* link = nullptr): Employee(newName, newEmployeeID, newEmployeeClass, newSalary, link) {
            name = newName;
            employeeID = newEmployeeID;
            employeeClass = newEmployeeClass;
            salary = newSalary + (newProfit * 0.6);
            next = link;
        }

        //--- Definition of Owner's display()
        virtual void display(ostream & out) const {
            out << "Name: " << name << endl 
                << "Employee ID: " << employeeID << endl
                << "Employee Class: " << employeeClass << endl 
                << "Salary: " << salary << " dollars" << endl << endl;
        }

};

class Chef: public Employee {
    public:
        string cuisineOfExpertise;

        //--- Definition of Chef's Constructor
        Chef(string newName, int newEmployeeID, char newEmployeeClass, double newSalary, string newCuisineOfExpertise, int newProfit, Employee* link = nullptr): Employee(newName, newEmployeeID, newEmployeeClass, newSalary, link) {
            name = newName;
            employeeID = newEmployeeID;
            employeeClass = newEmployeeClass;
            salary = newSalary + (newProfit * 0.2);
            next = link;
            cuisineOfExpertise = newCuisineOfExpertise;
        }

        //--- Definition of Chef's display()
        virtual void display(ostream & out) const {
            out << "Name: " << name << endl 
                << "Employee ID: " << employeeID << endl
                << "Employee Class: " << employeeClass << endl 
                << "Salary: " << salary << " dollars" << endl
                << "Cuisine of Expertise: " << cuisineOfExpertise << endl << endl;
        }
};

class Waiter: public Employee {
    public:
        int yearsOfService;

        //--- Definition of Waiter's Constructor
        Waiter(string newName, int newEmployeeID, char newEmployeeClass, double newSalary, int newYearsOfService, int newTips, Employee* link = nullptr): Employee(newName, newEmployeeID, newEmployeeClass, newSalary, link) {
            name = newName;
            employeeID = newEmployeeID;
            employeeClass = newEmployeeClass;
            salary = newSalary + newTips;
            next = link;
            yearsOfService = newYearsOfService;
        }

        //--- Definition of Waiter's display()
        virtual void display(ostream & out) const {
            out << "Name: " << name << endl 
                << "Employee ID: " << employeeID << endl
                << "Employee Class: " << employeeClass << endl 
                << "Salary: " << salary << " dollars" << endl
                << "Years of Service: " << yearsOfService << " years" << endl << endl;
        }
};

class LinkedList_Database {
    public:
        /***** Constructor *****/
        LinkedList_Database();                        

        /***** Destructor *****/
        ~LinkedList_Database();

        /***** empty() *****/
        bool empty() const;

        /***** insertOwner() *****/
        void insertOwner(const string& name, const int& employeeID, const char& employeeClass, const double& salary, const int& profit);

        /***** insertChef() *****/
        void insertChef(const string& name, const int& employeeID, const char& employeeClass, const double& salary, const string& cuisineOfExpertise, const int& profit);

        /***** insertWaiter() *****/
        void insertWaiter(const string& name, const int& employeeID, const char& employeeClass, const double& salary, const int& yearsOfService, const int& tips);

        /***** displayStatistics() *****/
        void displayStatistics(ostream & out) const;

    private:
        Employee* head;
        Employee* tail;
};




