#ifndef BALANCE_H
#define BALANCE_H
#include "Transaction.h"
#include "Date.h"
#include <fstream>

class Balance: public Transaction
{
    public:
        /// Constructors
        Balance();
        Balance(Date someDate, double dAmount);

        /// Destructor: The default destructor will do fine

        /// Operations
        void display();
        void display(ofstream& output);
        void save(ofstream& output);
};

#endif // BALANCE_H
