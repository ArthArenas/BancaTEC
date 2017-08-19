#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H
#include "Transaction.h"
#include "Date.h"
#include <fstream>

class Withdrawal: public Transaction
{
    public:
        /// Constructors
        Withdrawal();
        Withdrawal(Date someDate, double dAmount);

        /// Destructor: The default destructor will do fine

        /// Operations
        void display();
        void display(ofstream& output);
        void save(ofstream& output);
};

#endif // WITHDRAWAL_H
