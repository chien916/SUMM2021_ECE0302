#include "array_list.hpp"

template<typename T>
ArrayList<T>::ArrayList() {
    arrayPointer = nullptr;
    numberOfElements = 0;
}

template<typename T>
ArrayList<T>::~ArrayList() {
    if (arrayPointer != nullptr)
        delete[] arrayPointer;
}


template<typename T>
ArrayList<T>::ArrayList(const ArrayList &rhs) {
    int arrayLength = rhs.getLength();
    clear();
    numberOfElements = arrayLength;
    arrayPointer = new T[numberOfElements];
    for (int i = 1; i <= numberOfElements; i++) {//directly copy every elements
        arrayPointer[i - 1] = rhs.getEntry(i);
    }
}

template<typename T>
ArrayList<T> &ArrayList<T>::operator=(const ArrayList &rhs) {
    int arrayLength = rhs.getLength();
    clear();
    numberOfElements = arrayLength;
    arrayPointer = new T[numberOfElements];
    for (int i = 1; i <= numberOfElements; i++) {//directly copy every elements
        arrayPointer[i - 1] = rhs.getEntry(i);
    }
    return *this;
}

template<typename T>
bool ArrayList<T>::isEmpty() const {
    return (numberOfElements == 0);
}

template<typename T>
std::size_t ArrayList<T>::getLength() const {
    return numberOfElements;
}

template<typename T>
bool ArrayList<T>::insert(const T &item) {//THIS INSERT FUNCTION COULD ORDER THE LIST AUTOMATICALLY
    int positionToInsert = numberOfElements;
    for (int i = 1; i <= numberOfElements; i++) {//find proper position to insert
        if (item < arrayPointer[i - 1]) {//compare value (valid for most primitive data types)
            positionToInsert = (i - 1);
            break;
        }
    }
    T *oldPointer = arrayPointer;
    arrayPointer = new T[numberOfElements + 1];
    for (int i = 1; i <= (numberOfElements + 1); i++) {//copy elements with modification
        if ((i - 1) < positionToInsert) {//before position
            arrayPointer[i - 1] = oldPointer[i - 1];
        } else if ((i - 1) == positionToInsert) {//right on position
            arrayPointer[i - 1] = item;
        } else {//after position
            arrayPointer[i - 1] = oldPointer[i - 2];
        };
    }
    numberOfElements++;
    std::cout << "\nADDED LIST: ";
    for (int i = 1; i <= (numberOfElements); i++) {//copy elements with modification
        std::cout << arrayPointer[i - 1] << " ";
    }
    std::cout<<std::endl;
}

template<typename T>
bool ArrayList<T>::remove(std::size_t position) {
    T *oldPointer = arrayPointer;
    arrayPointer = new T[numberOfElements - 1];
    for (int i = 1; i <= numberOfElements + 1; i++) {//copy new array with modifications
        if (i < position) {
            arrayPointer[i - 1] = oldPointer[i - 1];
        } else if (i > position) {
            arrayPointer[i - 2] = oldPointer[i - 1];
        };
    }
    std::cout << "\nREMOVEDED LIST: ";
    numberOfElements--;
    for (int i = 1; i <= (numberOfElements); i++) {//copy elements with modification
        std::cout << arrayPointer[i - 1] << " ";
    }
    std::cout<<std::endl;
    delete[] oldPointer;
}

template<typename T>
void ArrayList<T>::clear() {
    arrayPointer = nullptr;
    numberOfElements = 0;
}

template<typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
    if (position > numberOfElements || position <= 0) {
        exit(10);
    } else {
        return arrayPointer[position - 1];
    }
}

template<typename T>
void ArrayList<T>::setEntry(std::size_t position, const T &newValue) {
    if (position > numberOfElements || position <= 0) {
        exit(11);
    } else {
        arrayPointer[position - 1] = newValue;
    }
}
