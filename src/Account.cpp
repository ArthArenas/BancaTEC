#include "Account.h"
#include "Withdrawal.h"
#include "Deposit.h"
#include "Balance.h"
#include "Date.h"
#include "Transaction.h"
#include "List.h"
#include "List.cpp"
#include "Settings.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
Account

This is the constructor without arguments

Parameters:
    void
Returns:
    It's a constructor
*/
/// Constructors
Account::Account() {
    Settings s;
    this -> s = s;
    sAccount = "Undefined";
    dTotBalance = 0;
    t = new List<Transaction>;
    iTransactions = 0;
}
/*
Account

This is the constructor with arguments

Parameters:
    void
Returns:
    string sAccount     Stores the account number
    double dTotBalance  Stores the total balance
    Settings s          Stores the settings
*/
Account::Account(string sAccount, double dTotBalance, Settings s) {
    this -> s = s;
    this -> sAccount = sAccount;
    this -> dTotBalance = dTotBalance;
    t = new List<Transaction>;
    iTransactions = 0;
}

/// Destructor
/*
~Account

This is the destructor

Parameters:
    void
Returns:
    void
*/
Account::~Account() {
    delete t;
    t = nullptr;
}

/// Setters & Getters
/*
GetsAccount

This is the getter for the account number

Parameters:
    void
Returns:
    string sAccount Stores the account number
*/
string Account::GetsAccount() {
    return sAccount;
}
/*
GetdTotBalance

This is the getter for the total balance

Parameters:
    void
Returns:
    double dTotBalance  Stores the total balance
*/
double Account::GetdTotBalance() {
    return dTotBalance;
}
/*
GetList

This is the getter for the list of transactions

Parameters:
    void
Returns:
    List<Transaction>* t    Stores the address of the list of transactions t
*/
List<Transaction>* Account::GetList() {
    return t;
}
/*
GetiTransactions

This is the getter for the number of transactions

Parameters:
    void
Returns:
    int iTransactions  Stores the number of transactions
*/
int Account::GetiTransactions() {
    return iTransactions;
}
/*
GetsType

This is the getter for the type of account

Parameters:
    void
Returns:
    string sType    Stores the type of account
*/
string Account::GetsType() {
    return sType;
}

/// Operations
/*
deposit

Creates a deposit object and does deposit into the account's balance

Parameters:
    double dAmount  Stores the amount deposited
    Date someDate   Stores the date of the deposit
Returns:
    void
*/
void Account::deposit(double dAmount, Date someDate) {
    Deposit* d = new Deposit(someDate, dAmount);
    t -> addElement(d);
    iTransactions++;
    dTotBalance += dAmount;
}
/*
balance

Creates a balance object and retrieves the account's balance

Parameters:
    double dAmount  Stores the account's balance
    Date someDate   Stores the date of the retrieval
Returns:
    void
*/
void Account::balance(double dAmount, Date someDate) {
    Balance* b = new Balance(someDate, dAmount);
    t -> addElement(b);
    iTransactions++;
}
/*
displayTransactions

Displays all the transactions that have been made sorted by date

Parameters:
    void
Returns:
    void
*/
void Account::displayTransactions() {
    int i;
    cout << "*** " << iTransactions << " Transactions ***" << endl;
    for(i = 0; i < iTransactions; i++){
        t -> GetElement(i) -> display();
    }
}
/*
displayTransactions

Displays all the transactions that have been made sorted by date with some format in an output file

Parameters:
    ofstream& output    Stores the output keyword
Returns:
    void
*/
void Account::displayTransactions(ofstream& output) {
    int i;
    if(iTransactions > 0) {
        // display the header of the format
        output << "\t\t*** " << iTransactions << " Transactions ***" << endl << endl;
        output << "TYPE\t\tDATE\t\t\tAMOUNT" << endl;
        // display each transaction
        for(i = 0; i < iTransactions; i++){
            t -> GetElement(i) -> display(output);
        }
    }
    // When there are no transactions, we display a notice of this
    else{
        output << "NO Transactions" << endl;
    }
}
/*
printAS

Prints the account number in an output file

Parameters:
    ofstream& output    Stores the output keyword
Returns:
    void
*/
void Account::printAS(ofstream& output) {
    output << "Account Number: " << sAccount << endl;
}
