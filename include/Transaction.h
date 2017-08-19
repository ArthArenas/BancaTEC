#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "Date.h"
#include <fstream>

class Transaction
{
    public:
        /// Constructors
        Transaction();
        Transaction(Date someDate, double dAmount);

        /// Destructor: The default destructor will do fine

        /// Setters & Getters
        void SetdAmount(double dAmount);
        double GetdAmount();

        void SetsomeDate(Date someDate);
        Date GetsomeDate();

        /// Operations
        virtual void display();
        virtual void display(ofstream& output);
        virtual void save(ofstream& output);

    protected:
        Date someDate;
        double dAmount;
};

#endif // TRANSACTION_H
