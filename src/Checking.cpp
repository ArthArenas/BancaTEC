#include "Checking.h"
#include "Date.h"
#include "Account.h"
#include "Withdrawal.h"
#include "Settings.h"
#include <fstream>

/// Constructors
/*
Checking

This is the constructor without arguments

Parameters:
    void
Returns:
    It's a constructor
*/
Checking::Checking() : Account() {
    dCommission = 0;
    sType = "Checking";
}
/*
Checking

This is the constructor with arguments

Parameters:
    void
Returns:
    string sAccount     Stores the account number
    double dCommission  Stores the commission on printing Account Status
    double dTotBalance  Stores the total balance
    Settings s          Stores the settings
*/
Checking::Checking(string sAccount, double dCommission, int dTotBalance, Settings s) : Account(sAccount, dTotBalance, s) {
    this -> dCommission = dCommission;
    iTransactions = 0;
    sType = "Checking";
}

/// Destructor: The default destructor will do fine

/// Setters & Getters
/*
SetdCommission

This is the setter for the commission

Parameters:
    double dCommission  Stores the commission
Returns:
    void
*/
void Checking::SetdCommission(double dCommission) {
    this -> dCommission = dCommission;
}
/*
GetdCommission

This is the getter for the commission

Parameters:
    void
Returns:
    double dCommission  Stores the commission
*/
double Checking::GetdCommission() {
    return dCommission;
}

/// Operations
/*
withdraw

Creates a withdraw object and does withdraw into the account's balance after validation
If validation fails, we display a feedback message

Parameters:
    double dAmount  Stores the amount withdrawn
    Date someDate   Stores the date of the withdrawal
Returns:
    void
*/
void Checking::withdraw(double dAmount, Date someDate) {
    if(dAmount <= dTotBalance){
        dTotBalance -= dAmount;
        Withdrawal* w = new Withdrawal(someDate, dAmount);
        t -> addElement(w);
        iTransactions++;
    }
    else{
        cout << "Unsuccessful withdrawal: not enough money in your account" << endl;
    }
}
/*
display

Displays the type of account and its number

Parameters:
    void
Returns:
    void
*/
void Checking::display() {
    cout << "Checking account\t" << sAccount << endl;
}
/*
printAS

Prints the full account information and its transactions in an output file

Parameters:
    ofstream& output    Stores the output keyword
Returns:
    void
*/
void Checking::printAS(ofstream& output) {
    double dTemp = dTotBalance;
    // Collect commission
    dTotBalance -= dCommission;
    // Print full account information
    Account::printAS(output);
    output << "Past balance: $" << dTemp << endl;
    output << "Commission: -$" << dCommission << endl;
    output << "Current balance: $" << dTotBalance << endl;
    output << endl;
    // Print transactions
    displayTransactions(output);
}
