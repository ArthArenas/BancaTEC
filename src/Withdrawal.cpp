#include "Withdrawal.h"
#include "Transaction.h"
#include "Date.h"
#include <fstream>
#include <iostream>

using namespace std;

/// Constructors
/*
Withdrawal

This is the constructor without arguments

Parameters:
    void
Returns:
    It's a constructor
*/
Withdrawal::Withdrawal() : Transaction() {
    // Nothing else to add here
}
/*
Withdrawal

This is the constructor with arguments

Parameters:
    Date someDate   Stores the date
    double dAmount  Stores the corresponding value
Returns:
    It's a constructor
*/
Withdrawal::Withdrawal(Date someDate, double dAmount) : Transaction(someDate, dAmount) {
    // Nothing else to add here
}

/// Destructor: The default destructor will do fine

/// Operations
/*
display

Displays the type of transaction (withdrawal) and the base display

Parameters:
    void
Returns:
    void
*/
void Withdrawal::display() {
    cout << "Withdrawal\t";
    Transaction::display();
}
/*
display

Displays the type of transaction (withdrawal) and the base display in an output file

Parameters:
    ofstream& output    Stores the keyword for output
Returns:
    void
*/
void Withdrawal::display(ofstream& output) {
    output << "Withdrawal\t";
    Transaction::display(output);
}
/*
save

Saves the withdrawal in the transactions file respecting its format

Parameters:
    ofstream& output    Stores the keyword for output
Returns:
    void
*/
void Withdrawal::save(ofstream& output) {
    output << "r\t";
    Transaction::save(output);
}
