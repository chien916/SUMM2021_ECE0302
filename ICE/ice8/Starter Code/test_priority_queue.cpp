#include "dynamic_array_list.h"
#include "sorted_list.h"
#include "priority_queue.h"
#include <cassert>

int main() {
    typedef SortedList<int, DynamicArrayList<int> > SortedListType;
    typedef PriorityQueue<int, SortedListType> PriorityQueueType;

    PriorityQueueType pq;

    //test isEmpty():
    assert(pq.isEmpty());
    pq.add(10);
    assert(!pq.isEmpty());

    //test add():
    pq.add(9);
    try {
        pq.add(100);
    } catch (int numbctch) {
        assert(numbctch == 13);
    };
    for (int i = 8; i <= 0; i--) {
        assert(pq.peek() == 10);
        pq.add(i);
    }

    //test remove():
    while (!pq.isEmpty()) {
        int peekTemp = pq.peek();
        pq.remove();
        if (!pq.isEmpty()) {
            int peekTemp2 = pq.peek();
            assert(peekTemp2=peekTemp-1);
        }
    }
    assert(pq.isEmpty());

}
