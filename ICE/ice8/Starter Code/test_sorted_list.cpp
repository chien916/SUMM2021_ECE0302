#include "dynamic_array_list.h"
#include "sorted_list.h"
#include <cassert>

int main() {
    typedef SortedList<int, DynamicArrayList<int> > slst;
    slst test;
    //test insert():
    for (int i = 0; i < 20; i++) {
        if (i % 2 == 0) {
            test.insert(i);
        } else {
            test.insert(20 - i);
        }
    }
    for (int i = 0; i < 20; i++) {
        assert(test.getEntry(i) == i);
    }
    assert(test.getLength() == 20);
    assert(!test.isEmpty());

    //test remove():
    for (int i = 0; i < 20; i += 5) {
        test.remove(i);//0,5,10,15
    }
    assert(test.getPosition(0) == -1);
    assert(test.getPosition(5) == -1);
    assert(test.getPosition(1) == 0);


    //test getEntry():
    assert(test.getEntry(0) == 1);
    assert(test.getEntry(4) == 6);
    assert(test.getEntry(5) == 7);
    assert(test.getEntry(6) == 8);

    //test removeAt():
    test.removeAt(0);
    assert(test.getPosition(1) == -1);
    test.removeAt(0);
    assert(test.getPosition(2) == -1);

    //test getPosition():
    slst test2;
    for(int i=0;i<20;i++){
        test2.insert(i);
    }
    for(int i=0;i<20;i++){
        assert(i==test2.getPosition(i));
    }



    return 0;
}
