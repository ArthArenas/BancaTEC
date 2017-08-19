#include "Settings.h"
#include <iostream>
#include <fstream>

using namespace std;

/// Constructors
/*
Settings

This is the constructor without arguments

Parameters:
    void
Returns:
    It's a constructor
*/
Settings::Settings() {
    dInterest = 0;
    dCommission = 0;
    iMinBalance = 0;
    iBlockTime = 0;
}
/*
Settings

This is the constructor with arguments

Parameters:
        double dInterest    Stores the interest for savings accounts
        double dCommission  Stores the commission for checking accounts
        int iMinBalance     Stores the minimum balance for savings accounts to stay active
        int iBlockTime      Stores the blocking time
Returns:
    It's a constructor
*/
Settings::Settings(double dInterest, double dCommission, int iMinBalance, int iBlockTime) {
    this -> dInterest = dInterest;
    this -> dCommission = dCommission;
    this -> iMinBalance = iMinBalance;
    this -> iBlockTime = iBlockTime;
}

/// Destructor: The default destructor will do fine

/// Setters & Getters
/*
SetdInterest

This is the setter for the interest

Parameters:
    double dInterest    Stores the interest for savings accounts
Returns:
    void
*/
void Settings::SetdInterest(double dInterest) {
    this -> dInterest = dInterest;
}
/*
SetdCommission

This is the setter for the commission

Parameters:
    double dCommission    Stores the commission for checking accounts
Returns:
    void
*/
void Settings::SetdCommission(double dCommission) {
    this -> dCommission = dCommission;
}
/*
SetiMinBalance

This is the setter for the minimum balance

Parameters:
    int iMinBalance     Stores the minimum balance for savings accounts to stay active
Returns:
    void
*/
void Settings::SetiMinBalance(int iMinBalance) {
    this -> iMinBalance = iMinBalance;
}
/*
SetiBlockTime

This is the setter for the blocking time

Parameters:
    int iBlockTime      Stores the blocking time
Returns:
    void
*/
void Settings::SetiBlockTime(int iBlockTime) {
    this -> iBlockTime = iBlockTime;
}
/*
GetdInterest

This is the getter for the interest

Parameters:
    void
Returns:
    double dInterest    Stores the interest for savings accounts
*/
double Settings::GetdInterest() {
    return dInterest;
}
/*
GetdCommission

This is the getter for the commission

Parameters:
    void
Returns:
    double dCommission    Stores the commission for checking accounts
*/
double Settings::GetdCommission() {
    return dCommission;
}
/*
GetiMinBalance

This is the getter for the minimum balance

Parameters:
    void
Returns:
    int iMinBalance     Stores the minimum balance for savings accounts to stay active
*/
int Settings::GetiMinBalance() {
    return iMinBalance;
}
/*
GetiBlockTime

This is the getter for the blocking time

Parameters:
    void
Returns:
    int iBlockTime      Stores the blocking time
*/
int Settings::GetiBlockTime() {
    return iBlockTime;
}

/// Operations
/*
GetSettings

This is the getter for itself

Parameters:
    void
Returns:
    *this   Stores itself
*/
Settings Settings::GetSettings() {
    return *this;
}
/*
display

Displays all the variables stored

Parameters:
    void
Returns:
    void
*/
void Settings::display() {
    cout << "Interest: " << dInterest << endl;
    cout << "Commission: " << dCommission << endl;
    cout << "Minimum Balance: " << iMinBalance << endl;
    cout << "Blocking Time: " << iBlockTime << endl;
}
