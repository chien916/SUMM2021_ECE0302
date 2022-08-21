#include <cassert>

#include "dynamic_array_list.h"
#include "heap_priority_queue.h"

int main() {
    //https://www.youtube.com/watch?v=bFwnqGkxA7k&ab_channel=DeborahS
    HeapPriorityQueue<int> pq2;assert(pq2.isEmpty());
    pq2.toggleSwitch();pq2.toggleSwitch();
    std::puts("+++++Testing Inserting Method:+++++");
    pq2.add(22);assert(pq2.peek() == 22);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.add(55);assert(pq2.peek() == 55);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.add(99);assert(pq2.peek() == 99);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.add(66);assert(pq2.peek() == 99);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.add(11);assert(pq2.peek() == 99);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.add(33);assert(pq2.peek() == 99);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.add(77);assert(pq2.peek() == 99);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.add(44);assert(pq2.peek() == 99);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.add(88);assert(pq2.peek() == 99);assert(!pq2.isEmpty());std::puts("===BRK===");
    std::puts("+++++Testing Removing Method:+++++");
    pq2.remove();assert(pq2.peek()==88);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.remove();assert(pq2.peek()==77);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.remove();assert(pq2.peek()==66);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.remove();assert(pq2.peek()==55);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.remove();assert(pq2.peek()==44);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.remove();assert(pq2.peek()==33);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.remove();assert(pq2.peek()==22);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.remove();assert(pq2.peek()==11);assert(!pq2.isEmpty());std::puts("===BRK===");
    pq2.remove();assert(pq2.isEmpty());std::puts("===BRK===");
    //test some out-of-bound exception throwing cases:
    auto catchTestPassed = false;
    try{
        pq2.remove();
    } catch (std::logic_error &) {
        catchTestPassed=true;
    }
    assert(catchTestPassed);
    catchTestPassed = false;
    try{
        pq2.peek();
    } catch (std::logic_error &) {
        catchTestPassed=true;
    }
    assert(catchTestPassed);




    //TEST CASES GIVEN
    std::puts("+++++Testing Given Cases:+++++");

    HeapPriorityQueue<int> pq;
    pq.toggleSwitch();
    assert(pq.isEmpty());

    pq.add(25);
    assert(!pq.isEmpty());
    assert(pq.peek() == 25);
    pq.add(1);
    assert(pq.peek() == 25);

    pq.add(78);
    assert(pq.peek() == 78);

    pq.remove();
    pq.remove();
    pq.remove();
    assert(pq.isEmpty());

    return 0;
}
