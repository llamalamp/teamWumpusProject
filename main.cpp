/**************************************************************
* Name        : Midterm project working model
* Author      : Kenny Murrell, Ian Folger, Scott Grigsby, Brennan Hydorn, Alexis Meis
* Created     : 02/07/2022
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
using namespace std;

//class object to store table information
class table {
    private:
    int tableNumber;
    int seatsAvailable;
    public:
    void setTable (int number, int seats) {
        tableNumber = number;
        seatsAvailable = seats;
    }
    int getTableNumber() {
        return tableNumber;
    }
    int getTableSeats() {
        return seatsAvailable;
    }
    };

//function to print the vector of available tables
void printTable(vector<vector<table>>tables) {
    cout << "Table number and (seats)" << endl;
    for (int i = 0; i < tables.size(); i++) {
        cout << i + 1 << " PM: ";
        for(int j = 0; j < tables[i].size(); j++) {
            table currentTable = tables[i][j];
            if(currentTable.getTableNumber() == 0) {
                cout << "(" << "X" << ")" << "  ";
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
    cout << "press 2 to seat walk in" << endl;
    cout << "press 3 to reserve call in" << endl;
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

//function to make sure table selected is empty
bool isTableEmpty(table currentTable) {
    if(currentTable.getTableNumber() == 0) {
        return false;
    }else{
        return true;
    }
    }


int main()
{
    //variables for later use in the menu
      int menuChoice = 9; //sets the choice so the while loop menu below runs
      int tableChoice;
      int timeChoice;

      //creating the table object
      //5 tables with 4 chairs
      //5 tables with 2 chairs
      //3 tables with 10 chairs
      table table1;
      table1.setTable(1,4);
      table table2;
      table2.setTable(2,4);
      table table3;
      table3.setTable(3,4);
      table table4;
      table4.setTable(4,4);
      table table5;
      table5.setTable(5,4);
      table table6;
      table6.setTable(6,2);
      table table7;
      table7.setTable(7,2);
      table table8;
      table8.setTable(8,2);
      table table9;
      table9.setTable(9,2);
      table table10;
      table10.setTable(10,2);
      table table11;
      table11.setTable(11,10);
      table table12;
      table12.setTable(12,10);
      table table13;
      table13.setTable(13,10);
      //table 0 is a placeholder for a table that is unavilable
      table table0;
      table0.setTable(0,0);

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

        //final version could have second vector that stores tables reserved and names of those who reserved them
        //or additional parameter something like 'avaliable' that can flag the table as taken
        while(menuChoice != 0 ) {
            printMenu();
            cin >> menuChoice;

            if(menuChoice == 1) {//prints menu
                printTable(tables);
            }else if(menuChoice == 2) {//for walk ins
                printTable(tables);
                timeChoice = timeChoiceValidator();
                tableChoice = tableChoiceValidator();
                if(isTableEmpty(tables[timeChoice-1][tableChoice-1])) { //checks that table is empty
                    tables[timeChoice-1][tableChoice-1] = table0;
                     //this will remove the table from the vector and replace it with table0
                    cout << "Your reservation is at " << timeChoice << "PM and table " << tableChoice << endl;
                }else{//if an unavailable table is chosen then we get an error and sent back to top menu
                    cout << "Sorry that time and table are taken. Please check availiable tables" << endl;
                }

            }else if(menuChoice == 3) {//for reservations
                printTable(tables);
                timeChoice = timeChoiceValidator();
                tableChoice = tableChoiceValidator();
                if(isTableEmpty(tables[timeChoice-1][tableChoice-1])) {
                    tables[timeChoice-1][tableChoice-1] = table0;
                    cout << "Your reservation is at " << timeChoice << "PM and table " << tableChoice;
                }else{
                    cout << "Sorry that time and table are taken. Please check availiable tables" << endl;
                }
                //menu choices 2 and 3 do the same thing for now but seperating it gives us more flexibility for changes
                //and additions later
            }else if(menuChoice == 0) {//to close and end the program
                char choice;
                cout << "are you sure y/n (this will reset all reservations to zero)" << endl;  //this verifies they actually want to close
                cin >> choice;
                if(choice == 'y') {
                    cout << "Thank you have a nice day! *** PROGRAM TERMINATED ***" << endl;
                    break;
                } //no need for else since anything but y will just send the loop back to the top menu
            }else{
                cout << "please enter valid choice" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }


return 0;
}


//Testing
/*
 * Entered 0 at top menu then y and program terminated with exit message
 * Entered 2 at top menu then 3 and 4 for time/table and received reservation confirmation. Table successfuly replaced with table 0 in vector
 * Tried to reserve table0 and received error message, sent back to top menu.
*/

