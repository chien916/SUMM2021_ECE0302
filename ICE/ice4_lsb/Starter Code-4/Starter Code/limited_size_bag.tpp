#include "limited_size_bag.hpp"

#define sizeOfBag 10

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {
    ptrPosition = new T[sizeOfBag];
    currentSize = 0;
}


template<typename T>
LimitedSizeBag<T>::LimitedSizeBag(const LimitedSizeBag &x) {
    ptrPosition = new T[sizeOfBag];
    for (int i = 0; i < sizeOfBag; i++) {//copy every element
        ptrPosition[i] = x[i];
    }
    currentSize = x.getCurrentSize();
}

template<typename T>
LimitedSizeBag<T>::~LimitedSizeBag() {
    delete[] ptrPosition;
}

template<typename T>

LimitedSizeBag<T> &LimitedSizeBag<T>::operator=(LimitedSizeBag<T> &x) {
    for (int i = 0; i < sizeOfBag; i++) {//copy every element
        ptrPosition[i] = x[i];
    }
    currentSize = x.getCurrentSize();
    return *this;
}

template<typename T>
bool LimitedSizeBag<T>::add(const T &item) {
    if(currentSize>=sizeOfBag){//when size exceeds capacity
        return 0;
    }
    else{//when size does not exceed capacity
        ptrPosition[currentSize] = item;
        currentSize++;
        return 1;
    }
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T &item) {
    int positionToRemove = -1;
    for (int i = 0; i < currentSize; i++) {//find element needs to be removed
        if (ptrPosition[i] == item) {
            positionToRemove = i;
            break;
        }
    }
    if (positionToRemove == -1) {
        return 0;
    } else {
        ptrPosition[positionToRemove]=ptrPosition[currentSize-1];//simply replace instead of deleting
        currentSize--;
        return 1;
    }

}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const {
    if (currentSize == 0) {
        return 1;
    } else {
        return 0;
    }
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const {
    return currentSize;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T &item) const {
    std::size_t frequency = getFrequencyOf(item);
    if (frequency == 0) {
        return 0;
    } else {
        return 1;
    }
}

template<typename T>
void LimitedSizeBag<T>::clear() {
    currentSize = 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T &item) const {
    std::size_t frequency = 0;
    for (int i = 0; i < currentSize; i++) {//search for required T
        if (ptrPosition[i] == item) {
            frequency++;
        }
    }
    return frequency;
};

template<typename T>
T &LimitedSizeBag<T>::operator[](int index) const {
    return ptrPosition[index];//return the T with index "index"
}
