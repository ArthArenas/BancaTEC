#include "Transaction.h"
#include "Date.h"
#include <iostream>
#include <fstream>

using namespace std;

/// Constructors
/*
Transaction

This is the constructor without arguments

Parameters:
    void
Returns:
    It's a constructor
*/
Transaction::Transaction() {
    Date rightNow;
    someDate = rightNow;
    dAmount = 0;
}
/*
Transaction

This is the constructor with arguments

Parameters:
    Date someDate   Stores the date
    double dAmount  Stores the corresponding value
Returns:
    It's a constructor
*/
Transaction::Transaction(Date someDate, double dAmount) {
    this -> someDate = someDate;
    this -> dAmount = dAmount;
}

/// Destructor: The default destructor will do fine

/// Setters & Getters
/*
SetdAmount

This is the setter for dAmount

Parameters:
    double dAmount  Stores the corresponding value
Returns:
    void
*/
void Transaction::SetdAmount(double dAmount) {
    this -> dAmount = dAmount;
}
/*
GetdAmount

This is the getter for dAmount

Parameters:
    void
Returns:
    double dAmount  Stores the corresponding value
*/
double Transaction::GetdAmount() {
    return dAmount;
}
/*
SetsomeDate

This is the setter for the date

Parameters:
    Date someDate   Stores the date
Returns:
    void
*/
void Transaction::SetsomeDate(Date someDate) {
    this -> someDate = someDate;
}
/*
GetsomeDate

This is the getter for the date

Parameters:
    void
Returns:
    Date someDate   Stores the date
*/
Date Transaction::GetsomeDate() {
    return someDate;
}

/// Operations
/*
display

Displays the date and the amount stored

Parameters:
    void
Returns:
    void
*/
void Transaction::display() {
    someDate.display();
    cout << "\t$" << dAmount << endl;
}
/*
display

Displays the date and the amount stored in an output file

Parameters:
    ofstream& output    Stores the keyword for output
Returns:
    void
*/
void Transaction::display(ofstream& output) {
    someDate.save(output);
    output << "\t$" << dAmount << endl;
}
/*
save

Saves the transaction in the transactions file respecting its format

Parameters:
    ofstream& output    Stores the keyword for output
Returns:
    void
*/
void Transaction::save(ofstream& output) {
    output << someDate.GetiDay() << '\t' << someDate.GetiMonth() << '\t' << someDate.GetiYear() << '\t';
    output << someDate.GetiHour() << '\t' << someDate.GetiMinute() << '\t'<< someDate.GetiSecond() << '\t' << dAmount << endl;
}
