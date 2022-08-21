
#ifndef _HEAP_PRIORITY_QUEUE_H_
#define _HEAP_PRIORITY_QUEUE_H_

#include "abstract_priority_queue.h"
#include "dynamic_array_list.h"

template<typename T>
class HeapPriorityQueue : public AbstractPriorityQueue<T> {
public:

    // return true if the priority queue is empty
    bool isEmpty();

    // insert item into the queue
    void add(const T &item);

    // remove highest priority item from the queue
    void remove();

    // get the item with the highest priority from the queue
    T peek();

    void toggleSwitch();

private:

    DynamicArrayList<T> lst;
};

template<typename T>
void HeapPriorityQueue<T>::toggleSwitch() {
    lst.printSwitch=(!lst.printSwitch);
    if(lst.printSwitch){
        puts("Success: Toggle Print Switch - TRUE");
    }else{
        puts("Success: Toggle Print Switch - FALSE");
    }
}

template<typename T>
bool HeapPriorityQueue<T>::isEmpty() {
    bool toReturn = lst.isEmpty();
    return toReturn;
}

template<typename T>
void HeapPriorityQueue<T>::add(const T &item) {
    std::size_t thisIndex = lst.getLength() + 1;//1-based index
    lst.insert(thisIndex - 1, item);//CONVERTED 0-based index
    swapThisWithParent:
    if (thisIndex > 1) {
        std::size_t parentIndex = thisIndex / 2;//1-based index
        T parentValue = lst.getEntry(parentIndex - 1);//CONVERTED 0-based index
        T thisValue = lst.getEntry(thisIndex - 1);//CONVERTED 0-based index
        if (thisValue > parentValue) {
            lst.setEntry(thisIndex - 1, parentValue);//CONVERTED 0-based index
            lst.setEntry(parentIndex - 1, thisValue);//CONVERTED 0-based index
            thisIndex = parentIndex;//1-based index
            goto swapThisWithParent;
        }
    }
}

template<typename T>
void HeapPriorityQueue<T>::remove() {
    if (isEmpty()) {
        std::puts("remove() failed: Heap is empty!");
        throw std::logic_error("HIE_REMOVE");
    }
    lst.setEntry(0, lst.getEntry(lst.getLength() - 1));//copy last element to root
    lst.remove(lst.getLength() - 1);//remove last element since it's already copied to root
    std::size_t thisIndex = 1;//1-based index
    swapThisWithLargerChild:
    if (lst.getLength() == 0) {
        return;
    } else if ((thisIndex * 2 - 1 + 1) <= (lst.getLength() - 1)) {//CONVERTED 0-based index
        std::size_t leftChildIndex = thisIndex * 2;//1-based index
        std::size_t rightChildIndex = thisIndex * 2 + 1;//1-based index
        T leftChildValue = lst.getEntry(leftChildIndex - 1);//CONVERTED 0-based index
        T rightChildValue = lst.getEntry(rightChildIndex - 1);//CONVERTED 0-based index
        T thisValue = lst.getEntry(thisIndex - 1);//CONVERTED 0-based index
        if (leftChildValue >= rightChildValue) {
            lst.setEntry(leftChildIndex - 1, thisValue);//CONVERTED 0-based index
            lst.setEntry(thisIndex - 1, leftChildValue);//CONVERTED 0-based index
            thisIndex = leftChildIndex;
            goto swapThisWithLargerChild;
        } else if (leftChildValue < rightChildValue) {
            lst.setEntry(rightChildIndex - 1, thisValue);//CONVERTED 0-based index
            lst.setEntry(thisIndex - 1, rightChildValue);//CONVERTED 0-based index
            thisIndex = rightChildIndex;
            goto swapThisWithLargerChild;
        }
    } else if ((thisIndex * 2 - 1) == (lst.getLength() - 1)) {
        std::size_t leftChildIndex = thisIndex * 2;//1-based index
        T thisValue = lst.getEntry(thisIndex - 1);//CONVERTED 0-based index
        T leftChildValue = lst.getEntry(leftChildIndex - 1);//CONVERTED 0-based index
        thisIndex = leftChildIndex;
        goto swapThisWithLargerChild;
    }
}

template<typename T>
T HeapPriorityQueue<T>::peek() {
    if (isEmpty()) {
        std::puts("peek() failed: Heap is empty!");
        throw std::logic_error("HIE_PEK");
    }
    T toReturn = lst.getEntry(0);
    return toReturn;
}


#endif // _HEAP_PRIORITY_QUEUE_H_
