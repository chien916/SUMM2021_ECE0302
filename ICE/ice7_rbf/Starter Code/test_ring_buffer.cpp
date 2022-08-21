#include "ring_buffer.h"

#include <cassert>

int main() {
    /*
     * To visualise the queue, I added a custom print() function
     * where each member values are shown. The bracket on the
     * right denotes if the front/back pointer is here.
     * F-Front Pointer is Here
     * B-Back Pointer is Here
     * D-Front AND Back Pointer is Here
     */

    //Test Constructor: //JUST TO MAKE SURE EVERYTHING WORKS AS PRECAUTIONS
    //RingBuffer<char> test(10);
    //assert(test.getCount() == 0);
    //for (unsigned int i = 0; i < 10; i++) {
    //    assert(test.enqueue_back('#') == true);
    //}
    //assert(test.enqueue_back('#') == false);

    //Test enqueue_front():
    RingBuffer<unsigned int> test2(10);
    for (unsigned int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            assert(test2.enqueue_back(i) == true);
        } else {
            assert(test2.enqueue_front(i) == true);
        }
        assert(test2.getCount()==i);
    }
    assert(test2.enqueue_front(9999) == false);
    assert(test2.enqueue_back(9999) == false);
    assert(test2.getCount()==10);

    unsigned int tempSize = 10;
    //Test dequene_back():
    assert(test2.getCount()==tempSize--);
    assert(test2.dequeue_back()==10);
    assert(test2.getCount()==tempSize--);
    assert(test2.dequeue_back()==8);
    assert(test2.getCount()==tempSize--);
    assert(test2.dequeue_front()==9);
    assert(test2.getCount()==tempSize--);
    assert(test2.dequeue_front()==7);
    assert(test2.getCount()==tempSize--);
    assert(test2.dequeue_front()==5);
    assert(test2.getCount()==tempSize--);
    assert(test2.dequeue_front()==3);
    assert(test2.getCount()==tempSize--);
    assert(test2.dequeue_front()==1);
    assert(test2.getCount()==tempSize--);
    assert(test2.dequeue_front()==2);
    assert(test2.getCount()==tempSize--);
    assert(test2.dequeue_front()==4);
    assert(test2.getCount()==tempSize--);
    assert(test2.dequeue_front()==6);
    assert(test2.getCount()==0);


/*
    RingBuffer<int> buff(6);

    buff.enqueue_front(1);
    buff.enqueue_front(2);
    buff.enqueue_front(3);
    buff.enqueue_front(4);
    buff.enqueue_front(5);
    buff.enqueue_front(6);

    //RingBuffer<int> buff2 = buff;

    assert(buff.getCount() == 6);
    assert(buff.dequeue_back() == 1);
    assert(buff.dequeue_back() == 2);
    assert(buff.dequeue_back() == 3);
    assert(buff.dequeue_back() == 4);
    assert(buff.dequeue_back() == 5);
    assert(buff.dequeue_back() == 6);
    assert(buff.getCount() == 0);
*/

    return 0;
}
