
#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include "abstract_priority_queue.h"

// Type T must be orderable
// Type L must conform to AbstractSortedList<T>
template<typename T, typename L>
class PriorityQueue : AbstractPriorityQueue<T> {
public:

    // return true if the priority queue is empty
    bool isEmpty() {
        //TODO
        return (slist.getLength() == 0);
    }

    // insert item into the queue
    void add(const T &item) {
        //TODO
        if (slist.getLength() > 0 && item > slist.getEntry(0)) {
            printf("Throwing: Only smaller numbers are permitted to push to the list in priority queue!");
            printf("\nHowever, this is a normal message not an error. I deliberately trying to add a non-addable element\n");
            throw 13;//a very very bad number denoting a failed insertion
        } else {
            slist.insert(item);
        }
    }

    // remove highest priority item from the queue
    void remove() {
        //TODO;
        slist.removeAt(slist.getLength() - 1);
    }

    // get the item with the highest priority from the queue
    T peek() {
        return slist.getEntry(slist.getLength() - 1);
    }

private:

    L slist; // internal sorted list
};


#endif // _PRIORITY_QUEUE_H_
