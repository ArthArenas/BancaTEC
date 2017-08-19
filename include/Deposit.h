#ifndef DEPOSIT_H
#define DEPOSIT_H
#include "Transaction.h"
#include "Date.h"
#include <fstream>

class Deposit: public Transaction
{
    public:
        /// Constructors
        Deposit();
        Deposit(Date someDate, double dAmount);

        /// Destructor: The default destructor will do fine

        /// Operations
        void display();
        void display(ofstream& output);
        void save(ofstream& output);
};

#endif // DEPOSIT_H
