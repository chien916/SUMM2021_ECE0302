#include "sorted_linked_list.hpp"
#include <stdexcept>

template<typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>() {//nothing needs to be done

}

template<typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> &x)://nothing needs to be done
        LinkedList<T>(x) {

}

template<typename T>
SortedLinkedList<T> &SortedLinkedList<T>::operator=(const SortedLinkedList<T> &x) {//nothing needs to be done
    LinkedList<T>::operator=(x);
    return *this;
}

template<typename T>
SortedLinkedList<T>::~SortedLinkedList() {//nothing needs to be done
    // base destructor gets called automatically
}

template<typename T>
bool SortedLinkedList<T>::isEmpty() {//nothing needs to be done
    return LinkedList<T>::isEmpty();

}

template<typename T>
std::size_t SortedLinkedList<T>::getLength() {//nothing needs to be done
    return LinkedList<T>::getLength();
}

template<typename T>
void SortedLinkedList<T>::insert(const T &item) {//done and checked
    size_t indexMax = getLength();
    size_t indexCounter = 1;
    T valueExtracted;
    if (isEmpty()) goto insert_loopEnd;
    insert_loopStart:
    if (indexCounter > indexMax) goto insert_loopEnd;
    valueExtracted = LinkedList<T>::getEntry(indexCounter);
    if (item < valueExtracted) goto insert_loopEnd;
    indexCounter = indexCounter + 1;
    goto insert_loopStart;
    insert_loopEnd:
    LinkedList<T>::insert(indexCounter, item);


}

template<typename T>
void SortedLinkedList<T>::remove(const T &item) {//done and checked
    if (LinkedList<T>::isEmpty()) throw std::range_error("empty list found while removing");
    size_t indexMax = getLength();
    size_t indexCounter = 1;
    T valueExtracted;
    remove_loopStart:
    if (indexCounter > indexMax) goto remove_loopEnd_didNotFound;
    valueExtracted = LinkedList<T>::getEntry(indexCounter);
    if (item == valueExtracted) goto remove_loopEnd_foundAndDeleted;
    indexCounter = indexCounter + 1;
    goto remove_loopStart;
    remove_loopEnd_didNotFound:
    if (MASTER_SWITCH_2) throw std::logic_error("item is not found in the list while removing");
    remove_loopEnd_foundAndDeleted:
    LinkedList<T>::remove(indexCounter);
}

template<typename T>
void SortedLinkedList<T>::removeAt(std::size_t position) {//done and checked
    if (LinkedList<T>::isEmpty()) throw std::range_error("empty list found while removing at");
    position = position + 1;//convert index to 1-base from 0-base
    if (position > LinkedList<T>::getLength() || position < 1)
        throw std::range_error("given index is out of boundary while removing");
    LinkedList<T>::remove(position);
}

template<typename T>
void SortedLinkedList<T>::clear() {//nothing needs to be done
    LinkedList<T>::clear();
}

template<typename T>
T SortedLinkedList<T>::operator[](std::size_t position) const {//done and checked
    if (LinkedList<T>::isEmpty()) throw std::range_error("empty list found while acquiring");
    position = position + 1;//convert index to 1-base from 0-base
    if (position > LinkedList<T>::getLength() || position < 1) {
        auto s = LinkedList<T>::getLength();
        throw std::range_error("given index is out of boundary while acquiring");
    }

    return LinkedList<T>::getEntry(position);
}

template<typename T>
long int SortedLinkedList<T>::getPosition(const T &newValue) {//done and checked
    if (LinkedList<T>::isEmpty()) throw std::range_error("empty list found while getting position");
    size_t indexMax = getLength();
    size_t indexCounter = 1;
    T valueExtracted;
    getPosition_loopStart:
    if (indexCounter > indexMax) goto getPosition_loopEnd_didNotFound;
    valueExtracted = LinkedList<T>::getEntry(indexCounter);
    if (newValue == valueExtracted) goto getPosition_loopEnd_found;
    indexCounter = indexCounter + 1;
    goto getPosition_loopStart;
    getPosition_loopEnd_didNotFound:
    throw std::logic_error("item is not found in the list while getting position");
    getPosition_loopEnd_found:
    return indexCounter;
}
