/**************************************************************
* Name        : Midterm project final version
* Author      : Kenny Murrell, Ian Folger, Scott Grigsby, Brennan Hydorn, Alexis Meis
* Created     : 02/07/2022 - revised 3/1/2022
* Course      : CIS 164- advanced C++
* EMAIL       : krcutkomp@dmacc.edu
**************************************************/
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<array>
#include<fstream>
#include<vector>
#include<cctype>
using namespace std;

//class object to store table information
class table {
    private:
    int tableNumber;
    int seatsAvailable;
    bool isAvailable;
    string partyName;
    public:
    table(int number, int seats) {
        tableNumber = number;
        seatsAvailable = seats;
        isAvailable = true;
        partyName = "None";
    }
    int getTableNumber() {
        return tableNumber;
    }
    int getTableSeats() {
        return seatsAvailable;
    }
    bool getIsAvailable() {
        return isAvailable;
    }
    string getPartyName() {
        return partyName;
    }
    void setPartyName(string name) {
        partyName = name;
    }
    void setAvailable(bool x) {
        isAvailable = x;
    }
    };

//function to print the vector of available tables
void printTable(vector<vector<table>>tables) {
    cout << "Table number and (seats)" << endl;
    for (unsigned int i = 0; i < tables.size(); i++) {
        cout << i + 1 << " PM: ";
        for(unsigned int j = 0; j < tables[i].size(); j++) {
            table currentTable = tables[i][j];
            if(!currentTable.getIsAvailable()) {
                cout << "(" << currentTable.getPartyName() << ")" << "  ";
            }
            else{
                cout << currentTable.getTableNumber() << "(" << currentTable.getTableSeats() << ")" << " ";
            }
        }
        cout << endl;
    }
}

//function to print the top menu
void printMenu () {
    cout << "press 1 to show tables" << endl;
    cout << "press 2 to reserve" << endl;
    cout << "press 3 to seat" << endl;
    cout << "press 4 to cancel a reservation" << endl;
    cout << "press 0 to quit for the day (resets all reservations to none)" << endl;
    }

//function to make sure table choice is in range
int tableChoiceValidator() {
    int choice;
    cout << "What Table? (see tables)" << endl;
    cin >> choice;

    while (choice < 0 || choice > 13) {
        cout << "Enter valid option, 1 - 13" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> choice;
    }

    return choice;
}

//function to get input for name
string getNameInput() {
    string name;
    cout << "What name is the reservation under?"<< endl;
    cin >> name;
    return name;
}

//function to make sure time is in range
int timeChoiceValidator() {
    int choice;

    cout << "What Time? 1 - 10" << endl;
    cin >> choice;

    while (choice < 1 || choice > 10) {
        cout << "Enter valid option, 1-10:" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> choice;
    }

    return choice;
}

//function to find if a name is in the vector
bool hasTable(vector<vector<table>>tables, string x) {
    for (unsigned int i = 0; i < tables.size(); i++) {
        for(unsigned int j = 0; j < tables[i].size(); j++) {
            table currentTable = tables[i][j];
            string currParty = currentTable.getPartyName();
            if(currParty.compare(x) == 0) {
                return true;
            }
        }
    }return 0;
}

int main()
{
    //variables for later use in the menu
      int menuChoice; //sets the choice so the while loop menu below runs
      int tableChoice;
      int timeChoice;

      //creating the table object
      //5 tables with 4 chairs
      //5 tables with 2 chairs
      //3 tables with 10 chairs
      table table1(1,4);
      table table2(2,4);
      table table3(3,4);
      table table4(4,4);
      table table5(5,4);
      table table6(6,2);
      table table7(7,2);
      table table8(8,2);
      table table9(9,2);
      table table10(10,2);
      table table11(11,10);
      table table12(12,10);
      table table13(13,10);


      vector<vector<table>>tables //creates 2d vector and fills it with the tables
        {
        {table1,table2,table3,table4,table5,table6,table7,table8,table9,table10,table11,table12,table13},
        {table1,table2,table3,table4,table5,table6,table7,table8,table9,table10,table11,table12,table13},
        {table1,table2,table3,table4,table5,table6,table7,table8,table9,table10,table11,table12,table13},
        {table1,table2,table3,table4,table5,table6,table7,table8,table9,table10,table11,table12,table13},
        {table1,table2,table3,table4,table5,table6,table7,table8,table9,table10,table11,table12,table13},
        {table1,table2,table3,table4,table5,table6,table7,table8,table9,table10,table11,table12,table13},
        {table1,table2,table3,table4,table5,table6,table7,table8,table9,table10,table11,table12,table13},
        {table1,table2,table3,table4,table5,table6,table7,table8,table9,table10,table11,table12,table13},
        {table1,table2,table3,table4,table5,table6,table7,table8,table9,table10,table11,table12,table13},
        {table1,table2,table3,table4,table5,table6,table7,table8,table9,table10,table11,table12,table13},
        };

        //running program main loop
        do {
            printMenu();
            cin >> menuChoice;

            //print main menu
            if(menuChoice == 1) {
                printTable(tables);
            //to make a reservation
            }else if(menuChoice == 2) {
                printTable(tables);
                timeChoice = timeChoiceValidator();
                tableChoice = tableChoiceValidator();
                table currTable = tables[timeChoice-1][tableChoice-1];
                //checks that table is empty
                if(currTable.getIsAvailable()) {
                    //changes the bool to false aka unavailable
                    tables[timeChoice-1][tableChoice-1].setPartyName(getNameInput());
                    tables[timeChoice-1][tableChoice-1].setAvailable(false);
                    cout << "Your reservation is at " << timeChoice << "PM and table " << tableChoice << endl;
                }else{//if an unavailable table is chosen then we get an error and sent back to top menu
                    cout << "Sorry that time and table are taken. Please check availiable tables" << endl;
                }

                //to seat
            }else if(menuChoice == 3) {//for reservations
                printTable(tables);
                char choice;
                string nameToSearch;
                cout << "Is there a reservation? (y/n)" << endl;
                cin >> choice;
                //this section checks for the reservation and returns the table number if found
                if(choice == 'y'){
                    cout << "What name is the reservation under?" << endl;
                    cin >> nameToSearch;
                    for (unsigned int i = 0; i < tables.size(); i++) {
                        for(unsigned int j = 0; j < tables[i].size(); j++) {
                            table currentTable = tables[i][j];
                            string currParty = currentTable.getPartyName();
                            //cout << currParty;//this line is for testing
                            if(currParty == nameToSearch) {
                               int currTableNum = currentTable.getTableNumber();
                               int currTime = i+ 1;
                               cout << "Please seat the " << nameToSearch << " party at table " << currTableNum << " for " << currTime << "PM"<< endl;
                            }

                    }}

                //if choice is anything but y then it goes into the reservation method again
                }else{
                timeChoice = timeChoiceValidator();
                tableChoice = tableChoiceValidator();
                table currTable = tables[timeChoice-1][tableChoice-1];
                if(currTable.getIsAvailable()) {
                    tables[timeChoice-1][tableChoice-1].setAvailable(false);
                    cout << "Your reservation is at " << timeChoice << "PM and table " << tableChoice;
                }else{
                    cout << "Sorry that time and table are taken. Please check availiable tables" << endl;
                }
                }

                //to clear a reservation
            }else if(menuChoice == 4){
                cout << "What table and time do you want to clear?" << endl;
                timeChoice = timeChoiceValidator();
                tableChoice = tableChoiceValidator();
                table currTable = tables[timeChoice-1][tableChoice-1];
                if(currTable.getIsAvailable()){
                    cout << "The table is already clear"<< endl;
                }else{
                    cout << "Table " << tableChoice << " for " << currTable.getPartyName() << " at " << timeChoice << " PM is now clear and ready for new reservation" << endl;
                    currTable.setAvailable(true);
                    currTable.setPartyName("NONE");
                }

                //to close and end the program
            }else if(menuChoice == 0) {
                char choice;
                cout << "are you sure y/n (this will reset all reservations to zero)" << endl;  //this verifies they actually want to close
                cin >> choice;
                if(choice == 'y') {
                    cout << "Thank you have a nice day! *** PROGRAM TERMINATED ***" << endl;
                }else {
                    menuChoice = 9;
                    cout << "Program exit cancelled" << endl;
                }

                //catch for any invalid input on menu choice
            }else{
                cout << "please enter valid choice" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }while(menuChoice != 0 );


return 0;
}


//Testing
/*
 * Entered 0 at top menu then y and program terminated with exit message
 * Entered 2 at top menu then 3 and 4 for time/table, greg for name,  and received reservation confirmation.
 * Enter 3 at top menu, then y, greg, and recieved message to seat greg at correct table and time
 * Entered 1 at top menu after adding a few names to reservations and saw the names displayed on the tables correctly
 * Entered 9 at top menu and received error message without crashing
 * Entered 4 at top menu, entered reserved table information, and received successful message. Printed tables and reservation cleared as expected.
 * ***ADDED and changed FOR FINAL SUBMISSION:
 * -changed main program from while loop to a do while loop.
-added a bool variable to the table class to make the available tables check more efficient.
-added string variable to table class to hold name of group who reserved
-changed named function setTable to a default constructor
-added ability to seat by reservation that finds the table number and time
-ability to clear a reservation by time and table.
-added exit cancelled condition with output message
-update print function to show party name of reserved tables instead of just x
*/

