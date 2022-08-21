//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() //done
{
    headPtr = nullptr;//set headPtr to nullptr
    currentSize = 0;
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack() //done
{
    clear();//delete all nodes
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const//done
{
    return (size() == 0);
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const//done
{
    return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType &newItem) {//done
    Node<ItemType> *newPtr = new Node<ItemType>(newItem, nullptr);
    if (isEmpty() == 1) {//if stack is empty
        headPtr = newPtr;
        currentSize = currentSize + 1;
    } else {//if stack is not empty
        (*getNodePtr(currentSize - 1)).setNext(newPtr);
        currentSize = currentSize + 1;
    }
    return 1;

}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const {//done
    ItemType returnItem;
    if (isEmpty() == 1) {
        throw (
                logic_error("peek() - Stack is empty")
        );
    } else {
        Node<ItemType> *previousPtr = getCurrentPtr();
        returnItem = (*previousPtr).getItem();
    }
    return returnItem;
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
ItemType Stack<ItemType>::pop() {
    ItemType returnItem;
    if (isEmpty() == 1) {
        throw (
                logic_error("pop() - Stack is empty")
        );
    } else if (currentSize == 1) {
        returnItem = (*headPtr).getItem();
        delete headPtr;
        currentSize = currentSize - 1;
    } else {
        returnItem = peek();
        Node<ItemType> *deletingPtr = getNodePtr(currentSize - 1);
        delete deletingPtr;
        deletingPtr = (getNodePtr(currentSize - 2));
        deletingPtr->setNext(nullptr);
        currentSize = currentSize - 1;
    }
    return returnItem;

}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear() {
    while (!isEmpty()) {
        pop();
    }
}  // end clear

template<class ItemType>
Node<ItemType> *Stack<ItemType>::getNodePtr(int i) const {//done
    if ((i + 1) > currentSize || i < 0) {
        cout << "\nCALLED i: " << i;
        throw (
                out_of_range("getNodePtr() - Requested index is OFR")
        );
    } else if (i == 0) {
        return headPtr;
    } else {
        Node<ItemType> *tempPointer = headPtr;
        unsigned int counter = 0;
        while (((*tempPointer).getNext() != nullptr) && (counter < i)) {
            tempPointer = (*tempPointer).getNext();
            counter++;
        }
        return tempPointer;
    }
}


template<class ItemType>
Node<ItemType> *Stack<ItemType>::getCurrentPtr() const {//done
    if (currentSize == 0)
        throw (
                logic_error("getCurrentPtr() - Stack is empty")
        );
    else {
        Node<ItemType> *toReturn = getNodePtr(currentSize - 1);
        return toReturn;
    }
}