#include "Savings.h"
#include "Settings.h"
#include "Date.h"
#include "Account.h"
#include "Withdrawal.h"
#include <fstream>


/// Constructors
/*
Savings

This is the constructor without arguments

Parameters:
    void
Returns:
    It's a constructor
*/
Savings::Savings() : Account()
{
    dInterest = 0;
    sType = "Savings";
    dAvailBalance = 0;
}
/*
Savings

This is the constructor with arguments

Parameters:
    void
Returns:
    string sAccount     Stores the account number
    double dInterest    Stores the interest on printing the Account Status
    double dTotBalance  Stores the total balance
    Settings s          Stores the settings
*/
Savings::Savings(string sAccount, double dInterest, double dTotBalance, Settings s) : Account(sAccount, dTotBalance, s)
{
    this -> dTotBalance = dTotBalance;
    this -> dInterest = dInterest;
    iTransactions = 0;
    sType = "Savings";
}

/// Destructor: The default destructor will do fine

/// Setters & Getters
/*
SetdAvailBalance

This is the setter for the available balance

Parameters:
    double dAvailBalance    Stores the available balance
Returns:
    void
*/
void Savings::SetdAvailBalance(double dAvailBalance)
{
    this -> dAvailBalance = dAvailBalance;
}
/*
SetdInterest

This is the setter for the interest

Parameters:
    double dInterest    Stores the interest on printing the Account Status
Returns:
    void
*/
void Savings::SetdInterest(double dInterest)
{
    this -> dInterest = dInterest;
}
/*
GetdAvailBalance

This is the getter for the available balance

Parameters:
    void
Returns:
    double dAvailBalance    Stores the available balance
*/
double Savings::GetdAvailBalance()
{
    return dTotBalance - s.GetiMinBalance();
}
/*
GetdInterest

This is the getter for the interest

Parameters:
    void
Returns:
    double dInterest    Stores the interest on printing the Account Status
*/
double Savings::GetdInterest()
{
    return dInterest;
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
void Savings::withdraw(double dAmount, Date someDate)
{
    if(dAmount <= GetdAvailBalance()){
        dTotBalance -= dAmount;
        Withdrawal* w = new Withdrawal(someDate, dAmount);
        t -> addElement(w);
        iTransactions++;
    }
    else{
        cout << "Unsuccessful withdrawal: not enough money to keep your account active" << endl;
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
void Savings::display()
{
    cout << "Savings account\t" << sAccount << endl;
}
/*
printAS

Prints the full account information and its transactions in an output file

Parameters:
    ofstream& output    Stores the output keyword
Returns:
    void
*/
void Savings::printAS(ofstream& output)
{
    double dTemp = dTotBalance;
    // Print full account information
    Account::printAS(output);
    output << "Past balance: $" << dTotBalance << endl;
    dTotBalance *= (1 + dInterest); // Pay interests
    output << "Available balance: $" << GetdAvailBalance() << endl;
    output << "Interests(+" << dInterest * 100 << "%): $" << dInterest * dTemp << endl;
    output << "Current balance: $" << dTotBalance << endl;
    output << endl;
    displayTransactions(output);
}
