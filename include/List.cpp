#include "List.h"
#include <iostream>

/// Constructors
template<class Type>
List<Type>::List()
{
    iSize = 0;
}

template<class Type>
List<Type>::List(Type* aElements[], int iSize)
{
    this -> aElements = aElements;
    this -> iSize = iSize;
}

/// Destructor: The default destructor will do fine

/// Setters & Getters
template<class Type>
Type* List<Type>::GetElement(int iIndex)
{
    return *(aElements + iIndex);
}

template<class Type>
int List<Type>::GetiSize()
{
    return iSize;
}

/// Operations
template<class Type>
void List<Type>::addElement(Type* t)
{
    aElements[iSize] = t;
    iSize++;
}

template<class Type>
void List<Type>::removeElement(Type* t)
{
    int iI;
    for(iI = 0; iI < iSize; iI++){
        if(t == aElements + iI){
            break;
        }
    }
    for(; iI < iSize - 1; iI++){
        aElements[iI] = aElements[iI + 1];
    }
    if(iSize > 0){
        iSize--;
    }
}

template<class Type>
int List<Type>::indexOf(Type* t)
{
    int iI = -1;
    for(iI = 0; iI < iSize; iI++){
        if(t == aElements + iI){
            break;
        }
    }
    if(iI == iSize){
        iI = -1;
    }
    return iI;
}
