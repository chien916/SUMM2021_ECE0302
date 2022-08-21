#include "deque.hpp"
#include "coordinate.yiq25"
#include <iostream>

template<typename T>
bool Deque<T>::isEmpty() const noexcept {
    return queueSize == 0;
}

template<typename T>
void Deque<T>::pushBack(const T &item) {
    if (queueSize == 0) {
        arrayPointer = new T[1];
        arrayPointer[0] = item;
        queueSize = 1;
    } else {
        T *arrayPointerOld = arrayPointer;
        arrayPointer = new T[queueSize + 1];
        for (unsigned int i = 0; i < queueSize; i++) {
            arrayPointer[i] = arrayPointerOld[i];
        }
        arrayPointer[queueSize] = item;
        delete[] arrayPointerOld;
        queueSize++;
    }
}

template<typename T>
void Deque<T>::pushFront(const T &item) {
    if (queueSize == 0) {
        arrayPointer = new T[1];
        arrayPointer[0] = item;
        queueSize = 1;
    } else {
        T *arrayPointerOld = arrayPointer;
        arrayPointer = new T[queueSize + 1];
        for (unsigned int i = 0; i < queueSize; i++) {
            arrayPointer[i + 1] = arrayPointerOld[i];
        }
        arrayPointer[0] = item;
        delete[] arrayPointerOld;
        queueSize++;
    }
}

template<typename T>
void Deque<T>::popFront() {
    if (queueSize == 0) {
        throw std::logic_error("popFront(): array is empty thus cannot pop");
    } else {
        T *arrayPointerOld = arrayPointer;
        arrayPointer = new T[queueSize - 1];
        for (unsigned int i = 0; i < queueSize - 1; i++) {
            arrayPointer[i] = arrayPointerOld[i + 1];
        }
        delete[] arrayPointerOld;
        queueSize--;
    }
}

template<typename T>
void Deque<T>::popBack() {
    if (queueSize == 0) {
        throw std::logic_error("popFront(): array is empty thus cannot pop");
    } else {
        T *arrayPointerOld = arrayPointer;
        arrayPointer = new T[queueSize - 1];
        for (unsigned int i = 0; i < queueSize - 1; i++) {
            arrayPointer[i] = arrayPointerOld[i];
        }
        delete[] arrayPointerOld;
        queueSize--;
    }
}

template<typename T>
T Deque<T>::front() const {
    return arrayPointer[0];
}

template<typename T>
T Deque<T>::back() const {
    return arrayPointer[queueSize - 1];
}


template<typename T>
Deque<T>::Deque() {
    queueSize = 0;
    arrayPointer = NULL;
}

template<typename T>
Deque<T>::~Deque() {
    if (arrayPointer != NULL)
        delete[] arrayPointer;
}

template<typename T>
bool Deque<T>::ifContains(const T &item) {
    for (int i = 0; i < queueSize; i++) {
        if (arrayPointer[i] == item) return true;
    }
    return false;
}
