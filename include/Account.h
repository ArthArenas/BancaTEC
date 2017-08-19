#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Settings.h"
#include "Date.h"
#include "List.h"
#include "Transaction.h"

class Account
{
    public:
        /// Constructors
        Account();
        Account(string sAccount, double dTotBalance, Settings s);

        /// Destructor
        virtual ~Account();

        /// Setters & Getters
        string GetsAccount();
        double GetdTotBalance();
        List<Transaction>* GetList();
        int GetiTransactions();
        string GetsType();

        /// Operations
        void deposit(double dAmount, Date someDate);
        virtual void withdraw(double dAmount, Date someDate) = 0;
        void balance(double dAmount, Date someDate);
        virtual void display() = 0;
        void displayTransactions();
        void displayTransactions(ofstream& output);
        virtual void printAS(ofstream& output);

    protected:
        string sAccount;
        double dTotBalance;
        List<Transaction>* t;
        int iTransactions;
        Settings s;
        string sType;
};

#endif // ACCOUNT_H
