#ifndef LIST_H
#define LIST_H
#include "Transaction.h"
#include <iostream>

const int MAX_SIZE = 20;

template<class Type>
class List
{
    public:
        /// Constructors
        List();
        List(Type* aElements[], int iSize);

        /// Destructor: The default destructor will do fine

        /// Setters & Getters
        Type* GetElement(int iIndex);
        int GetiSize();

        /// Operations
        void addElement(Type* t);
        void removeElement(Type* t);
        int indexOf(Type* t);

    private:
        int iSize;
        Type* aElements[MAX_SIZE];
};

#endif // LIST_H
