#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"

template<typename T>
class Deque : public AbstractDeque<T> {
public:
    /** Constructor
     */
    Deque();

    /** Destructor
     */
    ~Deque();

    /** Returns true if the deque is empty, else false
     */
    bool isEmpty() const noexcept;

    /** Add item to the front of the deque
     * may throw std::bad_alloc
     */
    void pushFront(const T &item);

    /** Remove the item at the front of the deque
     * throws std::runtime_error if the deque is empty
     */
    void popFront();

    /** Returns the item at the front of the deque
     * throws std::runtime_error if the deque is empty
     */
    T front() const;

    /** Add item to the back of the deque
     * may throw std::bad_alloc
     */
    void pushBack(const T &item);

    /** Remove the item at the back of the deque
     * throws std::runtime_error if the deque is empty
     */
    void popBack();


    /** Returns the item at the back of the deque
     * throws std::runtime_error if the deque is empty
     */
    T back() const;

    bool ifContains(const T&item);

private:
    unsigned int queueSize = 0;
    T *arrayPointer = NULL;
};

#include "deque.tpp"

#endif
