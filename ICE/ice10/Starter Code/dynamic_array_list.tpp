#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template<typename T>
DynamicArrayList<T>::DynamicArrayList(): data(nullptr), capacity(0), size(0) {}

template<typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T> &x) {
    capacity = x.capacity;
    size = x.size;
    data = capacity ? new T[capacity] : nullptr;
    std::copy(x.data, x.data + x.capacity, data);
}

template<typename T>
DynamicArrayList<T>::~DynamicArrayList() {
    delete[] data;
}

template<typename T>
DynamicArrayList<T> &DynamicArrayList<T>::operator=(DynamicArrayList<T> x) {
    swap(*this, x);
    return *this;
}

template<typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T> &x, DynamicArrayList<T> &y) {
    std::swap(x.data, y.data);
    std::swap(x.capacity, y.capacity);
    std::swap(x.size, y.size);
}

template<typename T>
bool DynamicArrayList<T>::isEmpty() {
    return (size == 0);
}

template<typename T>
std::size_t DynamicArrayList<T>::getLength() {
    return size;
}

template<typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T &item) {
    //std::clog << "Insert at " << position << " with size " << size << std::endl;

    if(!printSwitch){
        std::printf("insert  (%7d) called:  ",position);
    }
    else{
        std::printf("insert  (%3d,%3d) called:  ",position,item);
    }

    if (position > size) throw std::range_error("position out of range in insert");

    if (size == capacity) { // need to realloc
        std::size_t newcapacity = capacity ? 2 * capacity : 1;
        T *newdata = new T[newcapacity];
        std::copy(data, data + capacity, newdata);
        delete[] data;
        capacity = newcapacity;
        data = newdata;
    }

    for (long i = size - 1; i >= static_cast<long>(position); --i) {
        data[i + 1] = data[i];
        //std::clog << "Shifting " << i << " > " << position << std::endl;
    }
    //std::clog << std::endl;
    data[position] = item;
    ++size;
    print();
}

template<typename T>
void DynamicArrayList<T>::remove(std::size_t position) {
    std::printf("remove  (%7d) called:  ",position);
    if (isEmpty()) throw std::range_error("empty list in remove");
    if (position >= size) throw std::range_error("position out of range in remove");

    for (long i = position; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
    print();
}

template<typename T>
void DynamicArrayList<T>::clear() {
    std::printf("clear   (       ) called:  ");
    size = 0;
    print();
}

template<typename T>
T DynamicArrayList<T>::getEntry(std::size_t position) {
    if (position >= size) throw std::range_error("position out of range in getEntry");

    return data[position];
}

template<typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T &newValue) {
    if(!printSwitch){
        std::printf("setEntry(%7d) called:  ",position);
    }
    else{
        std::printf("setEntry(%3d,%3d) called:  ",position,newValue);
    }
    if (position >= size) throw std::range_error("position out of range in setEntry");
    data[position] = newValue;
    print();
}

template<typename T>
void DynamicArrayList<T>::print() {
    if (!printSwitch) {
        std::printf("\n");
        return;
    }
    std::printf("LIST:");
    for (int i = 0; i < getLength(); i = i + 1) {
        std::printf(" ");
        std::cout << getEntry(i);
    }
    std::printf("\n");
}