#include "Deposit.h"
#include "Transaction.h"
#include "Date.h"
#include <fstream>
#include <iostream>

using namespace std;

/// Constructors
/*
Deposit

This is the constructor without arguments

Parameters:
    void
Returns:
    It's a constructor
*/
Deposit::Deposit() : Transaction() {
    // Nothing else to add here
}
/*
Deposit

This is the constructor with arguments

Parameters:
    Date someDate   Stores the date
    double dAmount  Stores the corresponding value
Returns:
    It's a constructor
*/
Deposit::Deposit(Date someDate, double dAmount) : Transaction(someDate, dAmount) {
    // Nothing else to add here
}

/// Destructor: The default destructor will do fine

/// Operations
/*
display

Displays the type of transaction (deposit) and the base display

Parameters:
    void
Returns:
    void
*/
void Deposit::display() {
    cout << "Deposit\t\t";
    Transaction::display();
}
/*
display

Displays the type of transaction (deposit) and the base display in an output file

Parameters:
    ofstream& output    Stores the keyword for output
Returns:
    void
*/
void Deposit::display(ofstream& output) {
    output << "Deposit\t\t";
    Transaction::display(output);
}
/*
save

Saves the deposit in the transactions file respecting its format

Parameters:
    ofstream& output    Stores the keyword for output
Returns:
    void
*/
void Deposit::save(ofstream& output) {
    output << "d\t";
    Transaction::save(output);
}
