#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() {
    ptrPosition = nullptr;//empty bag if no parameter
}


template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag &x) {
    std::size_t sizeOfX = x.getCurrentSize();
    delete[] ptrPosition;
    ptrPosition = new T[sizeOfX];
    for (int i = 0; i < sizeOfX; i++) {//copy every element
        ptrPosition[i] = x[i];
    }
    currentSize = sizeOfX;
}

template<typename T>
DynamicBag<T>::~DynamicBag() {
    currentSize = 0;
    delete[] ptrPosition;
}

template<typename T>
DynamicBag<T> &DynamicBag<T>::operator=(DynamicBag<T> &x) {
    std::size_t sizeOfX = x.getCurrentSize();
    delete[] ptrPosition;
    ptrPosition = new T[sizeOfX];
    for (int i = 0; i < sizeOfX; i++) {//copy every element
        ptrPosition[i] = x[i];
    }
    currentSize = sizeOfX;
    return *this;
}

template<typename T>
bool DynamicBag<T>::add(const T &item) {
    T *ptrOld = ptrPosition;
    ptrPosition = new T[currentSize + 1];
    unsigned int i = 0;
    while (i < currentSize) {//copy every element
        ptrPosition[i] = ptrOld[i];
        i++;
    }
    ptrPosition[currentSize] = item;//copy new element
    currentSize++;
    delete[] ptrOld;
    return 1;
}

template<typename T>
bool DynamicBag<T>::remove(const T &item) {
    T *ptrOld = ptrPosition;
    ptrPosition = new T[currentSize - 1];
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
        int tempIndex = 0;
        for (int i = 0; i < currentSize; i++) {
            if (i != positionToRemove) {//copy every element BUT the removed one
                ptrPosition[tempIndex] = ptrOld[tempIndex];
                tempIndex++;
            }
        }
        delete[] ptrOld;
        currentSize--;
        return 1;
    }

}

template<typename T>
bool DynamicBag<T>::isEmpty() const {
    if (currentSize == 0) {
        return 1;
    } else {
        return 0;
    }
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const {
    return currentSize;
}

template<typename T>
bool DynamicBag<T>::contains(const T &item) const {
    std::size_t frequency = getFrequencyOf(item);
    if (frequency == 0) {
        return 0;
    } else {
        return 1;
    }
}

template<typename T>
void DynamicBag<T>::clear() {
    delete[] ptrPosition;//deallocate memory
    currentSize = 0;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T &item) const {
    std::size_t frequency = 0;
    for (int i = 0; i < currentSize; i++) {//search for required T
        if (ptrPosition[i] == item) {
            frequency++;
        }
    }
    return frequency;
};

template<typename T>
T &DynamicBag<T>::operator[](int index) const {
    return ptrPosition[index];//return the T with index "index"
}