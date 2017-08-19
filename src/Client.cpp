#include "Client.h"
#include <iostream>
#include <ctime>

/// Constructors
/*
Client

This is the constructor without arguments

Parameters:
    void
Returns:
    It's a constructor
*/
Client::Client() {
    sID = "Undetermined";
    sName = "Unnamed";
    sEmail = "name_template@nowhere.com";
    sPassword = "********";
    sPhone = "6141234567";
    iNumAccounts = 0;
    bBlocked = false;
    iBlockTime = 0;
    iAttempts = 0;
}
/*
Client

This is the constructor with arguments

Parameters:
    void
Returns:
    string sID          Stores the ID
    string sName        Stores the name
    string sPhone       Stores the phone
    string sEmail       Stores the email
    string sPassword    Stores the password
*/
Client::Client(string sID, string sName, string sPhone, string sEmail, string sPassword) {
    this -> sID = sID;
    this -> sName = sName;
    this -> sPhone = sPhone;
    this -> sEmail = sEmail;
    this -> sPassword = sPassword;
    iNumAccounts = 0;
    bBlocked = false;
    iBlockTime = 0;
    iAttempts = 0;
}

/// Destructor: The default destructor will do fine

/// Setters & Getters
/*
SetbBlocked

This is the setter for bBlocked

Parameters:
    bool bBlocked   Stores whether the account is blocked or not
Returns:
    void
*/
void Client::SetbBlocked(bool bBlocked) {
    this -> bBlocked = bBlocked;
}
/*
SetiBlockTime

This is the setter for the blocking time, it sets the seconds from 01/01/1990

Parameters:
    void
Returns:
    void
*/
void Client::SetiBlockTime() {
    iBlockTime = int( time(0) );
}
/*
SetiAttempts

This is the setter for the number of attempts to log in

Parameters:
    int iAttempts   Stores the number of attempts to log in
Returns:
    void
*/
void Client::SetiAttempts(int iAttempts) {
    this -> iAttempts = iAttempts;
}
/*
SetsID

This is the setter for the ID

Parameters:
    string sID  Stores the ID
Returns:
    void
*/
void Client::SetsID(string sID) {
    this -> sID = sID;
}
/*
SetsName

This is the setter for the name

Parameters:
    string sName    Stores the name
Returns:
    void
*/
void Client::SetsName(string sName) {
    this -> sName = sName;
}
/*
SetsPhone

This is the setter for the phone

Parameters:
    string sPhone   Stores the phone
Returns:
    void
*/
void Client::SetsPhone(string sPhone) {
    this -> sPhone = sPhone;
}
/*
SetsEmail

This is the setter for the email

Parameters:
    string sEmail   Stores the email
Returns:
    void
*/
void Client::SetsEmail(string sEmail) {
    this -> sEmail = sEmail;
}
/*
SetsPassword

This is the setter for the password

Parameters:
    string sPassword    Stores the password
Returns:
    void
*/
void Client::SetsPassword(string sPassword) {
    this -> sPassword = sPassword;
}
/*
SetaAccounts

This is the setter for the array of accounts

Parameters:
    Account* aAccountsB[]   Stores the accounts
    int iNumAccounts        Stores the number of accounts
Returns:
    void
*/
void Client::SetaAccounts(Account* aAccountsB[], int iNumAccounts) {
    this -> iNumAccounts = iNumAccounts;
    int i;
    for(i = 0; i < iNumAccounts; i++){
        aAccounts[i] = aAccountsB[i];
    }
}
/*
GetsID

This is the getter for the ID

Parameters:
    void
Returns:
    string sID  Stores the ID
*/
string Client::GetsID() {
    return sID;
}
/*
GetsName

This is the getter for the name

Parameters:
    void
Returns:
    string sName    Stores the name
*/
string Client::GetsName() {
    return sName;
}
/*
GetsPhone

This is the getter for the phone

Parameters:
    void
Returns:
    string sPhone   Stores the phone
*/
string Client::GetsPhone() {
    return sPhone;
}
/*
GetsEmail

This is the getter for the email

Parameters:
    void
Returns:
    string sEmail   Stores the email
*/
string Client::GetsEmail() {
    return sEmail;
}
/*
GetsPassword

This is the getter for the password

Parameters:
    void
Returns:
    string sPassword    Stores the password
*/
string Client::GetsPassword() {
    return sPassword;
}
/*
GetbBlocked

This is the getter for bBlocked

Parameters:
    void
Returns:
    bool bBlocked   Stores whether the account is blocked or not
*/
bool Client::GetbBlocked() {
    return bBlocked;
}
/*
GetiBlockTime

This is the getter for the blocking time

Parameters:
    void
Returns:
    int iBlockTime  Stores the blocking time
*/
int Client::GetiBlockTime() {
    return iBlockTime;
}
/*
GetiAttempts

This is the getter for the number of attempts to log in

Parameters:
    void
Returns:
    int iAttempts   Stores the number of attempts to log in
*/
int Client::GetiAttempts()
{
    return iAttempts;
}
/*
GetaAccounts

This is the getter for the array of accounts

Parameters:
    void
Returns:
    Account* aAccountsB[]   Stores the accounts
    int iNumAccounts        Stores the number of accounts
*/
void Client::GetaAccounts(Account* aAccountsB[], int& iNumAccounts) {
    int i;
    for(i = 0; i < iNumAccounts; i++){
        aAccountsB[i] = aAccounts[i];
    }
    iNumAccounts = this -> iNumAccounts;
}
/*
GetiNumAccounts

This is the getter for the number of accounts

Parameters:
    void
Returns:
    int iNumAccounts    Stores the number of accounts
*/
int Client::GetiNumAccounts() {
    return iNumAccounts;
}
/*
GetAccount

This is the getter for a particular indexed account

Parameters:
    int iIndex  Stores the index of the account from the array of accounts
Returns:
    Account* aAccounts[iIndex]  Stores the account required
*/
Account* Client::GetAccount(int iIndex) {
    return aAccounts[iIndex];
}

/// Operations
/*
addAccount

Adds a new account

Parameters:
    Account* a  Stores the pointer to the account to be added
Returns:
    void
*/
void Client::addAccount(Account* a) {
    aAccounts[iNumAccounts] = a;
    iNumAccounts++;
}
/*
display

Displays the name, ID, Password (each character as an '*'), email and phone of the client

Parameters:
    void
Returns:
    void
*/
void Client::display() {
    cout << "Name: " << sName << '\t' << "ID: " << sID << '\t' << "Password: " << string(int(sPassword.size()),'*') << endl;
    cout << "Email: " << sEmail << '\t' << "Phone: " << sPhone << endl;
}
/*
displayAccount

Displays the client's accounts

Parameters:
    void
Returns:
    void
*/
void Client::displayAccounts() {
    int i;
    cout << "Your accounts" << endl;
    for(i = 0; i < iNumAccounts; i++){
        cout << (i + 1) << ". ";
        GetAccount(i) -> display();
    }
}
