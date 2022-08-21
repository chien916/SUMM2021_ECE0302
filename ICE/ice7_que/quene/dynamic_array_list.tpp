#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template<typename T>
DynamicArrayList<T>::DynamicArrayList() {
    Data = nullptr;
    size = 0;
    capacity = 32;
}

template<typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T> &x) {
    int arrayLength = x.getLengthConst();
    clear();
    size = arrayLength;
    Data = new T[size];
    for (int i = 1; i <= size; i++) {//directly copy every elements
        Data[i - 1] = x.getEntryConst(i - 1);
    }
}

template<typename T>
DynamicArrayList<T>::~DynamicArrayList() {
    std::clog << "DynamicArrayList Destructor called." << std::endl;
    delete[] Data;
    Data= nullptr;
}



template<typename T>
DynamicArrayList<T> &DynamicArrayList<T>::operator=(DynamicArrayList<T> x) {
    int arrayLength = x.getLengthConst();
    clear();
    size = arrayLength;
    Data = new T[size];
    for (int i = 1; i <= size; i++) {//directly copy every elements
        Data[i - 1] = x.getEntryConst(i - 1);
    }
    return *this;
}

template<typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T> &x, DynamicArrayList<T> &y) {
    DynamicArrayList<T> tempList = x;
    x = y;
    y = tempList;
}

template<typename T>
bool DynamicArrayList<T>::isEmpty() {
    return (size == (size_t) 0);
}

template<typename T>
std::size_t DynamicArrayList<T>::getLength() {
    return size;
}

template<typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T &item) {
    position = position + 1;//convert to 1-base index from 0-base index
    T *oldPointer = Data;
    Data = new T[size + 1];
    for (int i = 1; i < position; i++) {
        Data[i - 1] = oldPointer[i - 1];
    }
    Data[position - 1] = item;
    for (int i = position + 1; i <= size + 1; i++) {
        Data[i - 1] = oldPointer[i - 2];
    }
    size = size + 1;

    std::cout << "\nIND-INSERTED LIST: ";
    for (int i = 1; i <= (size); i++) {//copy elements with modification
        std::cout << Data[i - 1] << " ";
    }
    std::cout << std::endl;
    delete[] oldPointer;
}

template<typename T>
void DynamicArrayList<T>::remove(std::size_t position) {
    position = position + 1;//convert to 1-base index from 0-base index
    T *oldPointer = Data;
    Data = new T[size - 1];
    for (int i = 1; i <= size + 1; i++) {//copy new array with modifications
        if (i < position) {
            Data[i - 1] = oldPointer[i - 1];
        } else if (i > position) {
            Data[i - 2] = oldPointer[i - 1];
        };
    }
    std::cout << "\nREMOVEDED LIST: ";
    size--;
    for (int i = 1; i <= (size); i++) {//copy elements with modification
        std::cout << Data[i - 1] << " ";
    }
    std::cout << std::endl;
    delete[] oldPointer;
}

template<typename T>
void DynamicArrayList<T>::clear() {
    if (Data != nullptr)
        delete[] Data;
    Data = nullptr;
    size = (size_t) 0;
}

template<typename T>
T DynamicArrayList<T>::getEntry(std::size_t position) {
    position = position + 1;//convert to 1-base index from 0-base index
    if (position > size || position <= 0) {
        throw std::out_of_range("getEntry() index out of bound!");
    } else {
        return Data[position - 1];
    }
}

template<typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T &newValue) {
    position = position + 1;//convert to 1-base index from 0-base index
    if (position > size || position <= 0) {
        throw std::out_of_range("setEntry() index out of bound!");
    } else {
        Data[position - 1] = newValue;
    }
}

template<typename T>
std::size_t DynamicArrayList<T>::getLengthConst() const {
    return size;
}

template<typename T>
T DynamicArrayList<T>::getEntryConst(std::size_t position) const {
    position = position + 1;//convert to 1-base index from 0-base index
    if (position > size || position <= 0) {
        throw std::out_of_range("getEntry() index out of bound!");
    } else {
        return Data[position - 1];
    }
}