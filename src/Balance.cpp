#include "Balance.h"
#include "Transaction.h"
#include "Date.h"
#include <fstream>
#include <iostream>

using namespace std;

/// Constructors
/*
Balance

This is the constructor without arguments

Parameters:
    void
Returns:
    It's a constructor
*/
Balance::Balance() : Transaction() {
    // Nothing else to add here
}
/*
Balance

This is the constructor with arguments

Parameters:
    Date someDate   Stores the date
    double dAmount  Stores the corresponding value
Returns:
    It's a constructor
*/
Balance::Balance(Date someDate, double dAmount) : Transaction(someDate, dAmount) {
    // Nothing else to add here
}

/// Destructor: The default destructor will do fine

/// Operations
/*
display

Displays the type of transaction (balance) and the base display

Parameters:
    void
Returns:
    void
*/
void Balance::display() {
    cout << "Balance\t\t";
    Transaction::display();
}
/*
display

Displays the type of transaction (balance) and the base display in an output file

Parameters:
    ofstream& output    Stores the keyword for output
Returns:
    void
*/
void Balance::display(ofstream& output) {
    output << "Balance\t\t";
    Transaction::display(output);
}
/*
save

Saves the balance in the transactions file respecting its format

Parameters:
    ofstream& output    Stores the keyword for output
Returns:
    void
*/
void Balance::save(ofstream& output) {
    output << "s\t";
    Transaction::save(output);
}
