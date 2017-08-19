#ifndef CHECKING_H
#define CHECKING_H
#include "Settings.h"
#include "Date.h"
#include "Account.h"
#include <fstream>

class Checking : public Account
{
    public:
        /// Constructors
        Checking();
        Checking(string sAccount, double dCommission, int dTotBalance, Settings s);

        /// Destructor: The default destructor will do fine

        /// Setters & Getters
        void SetdCommission(double dCommission);

        double GetdCommission();

        /// Operations
        void withdraw(double dAmount, Date someDate);
        void display();
        void printAS(ofstream& output);

    private:
        double dCommission;
};

#endif // CHECKING_H
