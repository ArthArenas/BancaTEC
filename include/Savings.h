#ifndef SAVINGS_H
#define SAVINGS_H
#include "Settings.h"
#include "Date.h"
#include "Account.h"
#include <fstream>


class Savings : public Account
{
    public:
        /// Constructors
        Savings();
        Savings(string sAccount, double dInterest, double dAvailBalance, Settings s);

        /// Destructor: The default destructor will do fine

        /// Setters & Getters
        void SetdAvailBalance(double dAvailBalance);
        void SetdInterest(double dInterest);

        double GetdInterest();
        double GetdAvailBalance();

        /// Operations
        void withdraw(double dAmount, Date someDate);
        void display();
        void printAS(ofstream& output);

    private:
        double dAvailBalance;
        double dInterest;
};

#endif // SAVINGS_H
