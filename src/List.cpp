#include "List.h"
#include <iostream>

/// Constructors
/*
List

This is the constructor without arguments

Parameters:
    void
Returns:
    It's a constructor
*/
template<class Type>
List<Type>::List() {
    iSize = 0;
}
/*
List

This is the constructor with arguments

Parameters:
    Type* aElements[]   Stores the array of pointers to elements of type 'Type'
    int iSize           Stores the amount of elements used in the array member
Returns:
    It's a constructor
*/
template<class Type>
List<Type>::List(Type* aElements[], int iSize) {
    this -> aElements = aElements;
    this -> iSize = iSize;
}

/// Destructor: The default destructor will do fine

/// Setters & Getters
/*
GetElement

Retrieves an element from the member array

Parameters:
    int iIndex                  Stores the index of the element to be retrieved from the member array
Returns:
    Type* (Elements + iIndex)   Stores the element to be retrieved
*/
template<class Type>
Type* List<Type>::GetElement(int iIndex) {
    return *(aElements + iIndex);
}
/*
GetiSize

This is the getter for the size of the member array

Parameters:
    void
Returns:
    int iSize   Stores the size of the member array
*/
template<class Type>
int List<Type>::GetiSize() {
    return iSize;
}

/// Operations
/*
addElement

Adds a new element to the array

Parameters:
    Type* t Stores the element to be added
Returns:
    void
*/
template<class Type>
void List<Type>::addElement(Type* t) {
    aElements[iSize] = t;
    iSize++;
}
/*
removeElement

Removes an element from the array

Parameters:
    Type* t Stores the element to be removed
Returns:
    void
*/
template<class Type>
void List<Type>::removeElement(Type* t) {
    int i;
    // Search the element
    for(i = 0; i < iSize; i++){
        if(t == aElements + i){
            break;
        }
    }
    // Displace the following elements
    for(; i < iSize - 1; i++){
        aElements[i] = aElements[i + 1];
    }
    // Update size
    if(iSize > 0){
        iSize--;
    }
}
/*
indexOf

Retrieves the index from the member array of a given element

Parameters:
    Type* t Stores the given element
Returns:
    int iI  Stores the index
*/
template<class Type>
int List<Type>::indexOf(Type* t) {
    int i = -1;
    for(i = 0; i < iSize; i++){
        if(t == aElements + i){
            break;
        }
    }
    if(i == iSize){
        i = -1;
    }
    return i;
}
