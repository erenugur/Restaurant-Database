/*--------------------------------------------------------------------------
      Driver program to test the functionalities of the database.
 -------------------------------------------------------------------------*/

#include <iostream>
#include "Restaurant.h"
using namespace std;

int main() {

    int profit;
    int tipsOfWaiter1;
    int tipsOfWaiter2;
    int tipsOfWaiter3;
    cout << "Enter the month's profit or loss (in dollars): ";
    cin >> profit;
    cout << "Enter the tips earned by the first waiter (in dollars): ";
    cin >> tipsOfWaiter1;
    cout << "Enter the tips earned by the second waiter (in dollars): ";
    cin >> tipsOfWaiter2;
    cout << "Enter the tips earned by the third waiter (in dollars): ";
    cin >> tipsOfWaiter3;

    LinkedList_Database myRestaurant;
    myRestaurant.insertOwner("Owen", 10001, 'O', 15000, profit);
    myRestaurant.insertChef("Caroline", 10002, 'C', 10000, "Italian", profit);
    myRestaurant.insertChef("Carl", 10003, 'C', 10000, "French", profit);
    myRestaurant.insertWaiter("Walter", 10004, 'W', 3000, 3, tipsOfWaiter1);
    myRestaurant.insertWaiter("William", 10005, 'W', 3000, 5, tipsOfWaiter2);
    myRestaurant.insertWaiter("Wendy", 10006, 'W', 3000, 7, tipsOfWaiter3);

    myRestaurant.displayStatistics(cout);
    
    return 0;
}
