#include "ring_buffer.h"

#include <cassert>
#include <iostream>

template<typename T>
RingBuffer<T>::RingBuffer(std::size_t size) {
    queueLength = size;
    data.reset(new T[queueLength]);
    front = 0;
    back = queueLength - 1;
    count = 0;
    std::cout<<"\nCST|| ";
    print();
}

template<typename T>
bool RingBuffer<T>::enqueue_back(const T &item) {
    if (count != queueLength) {
        back = (back + 1) % queueLength;
        data[back] = item;
        ++count;
        std::cout<<"\nBEQ|| ";
        print();
        return true;
    }
    return false;
}

template<typename T>
bool RingBuffer<T>::enqueue_front(const T &item) {
    if (count != queueLength) {
        if (front == 0) front = queueLength - 1;
        else front = front - 1;
        data[front] = item;
        ++count;
        std::cout<<"\nFEQ|| ";
        print();
        return true;
    }
    return false;
}

template<typename T>
T RingBuffer<T>::dequeue_front() {
    assert(count > 0);

    T value;

    value = data[front];
    front = (front + 1) % queueLength;
    --count;
    std::cout<<"\nFDQ|| ";
    print();
    return value;
}

template<typename T>
T RingBuffer<T>::dequeue_back() {
    assert(count > 0);

    T value;

    value = data[back];
    if (back == 0) back = queueLength - 1;
    else back = back - 1;
    --count;
    std::cout<<"\nBDQ|| ";
    print();
    return value;
}

template<typename T>
long int RingBuffer<T>::getCount() {
    return count;
}

template<typename T>
void RingBuffer<T>::print() {
    std::cout << "QUEUE: ";
    for (int i = 0; i < queueLength; i++) {
        std::cout <<data[i];
        if(i==front&&i==back){
            std::cout<<"(D) ";
        }
        else if(i==front)
            std::cout<<"(F) ";
        else if (i==back)
            std::cout<<"(B) ";
        else
            std::cout<<"( ) ";
    }
}