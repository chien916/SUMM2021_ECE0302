#include "linked_list.hpp"

template<typename T>
LinkedList<T>::LinkedList() {
    firstNodePointer = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    delete[] firstNodePointer;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &x) {
    firstNodePointer = nullptr;
    copyList(x);
}

template<typename T>
void LinkedList<T>::swap(LinkedList<T> &x, LinkedList<T> &y) {
    LinkedList tempList(y);
    y.operator=(x);
    x.operator=(tempList);
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &x) {
    if(!isEmpty()) clear();
    copyList(x);
    return *this;
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    std::size_t length = getLength();
    return length == 0;
}

template<typename T>
std::size_t LinkedList<T>::getLength() const {
    std::size_t toReturn = 0;
    Node<T> *currentNodePointer = firstNodePointer;
    while (currentNodePointer != nullptr) {
        toReturn++;
        currentNodePointer = (*currentNodePointer).getNext();
    }
    return toReturn;
}

template<typename T>
bool LinkedList<T>::insert(std::size_t position, const T &item) {
    if (position == 1 && getLength() == 0) {
        //std::cout<<"1\n";
        firstNodePointer = new Node<T>;
        (*firstNodePointer).setItem(item);
        return true;
    } else if (position == 1 && getLength() != 0) {//insert at beginning
        //std::cout<<"2\n";
        Node<T> *pointerRightShiftedNode = firstNodePointer;
        firstNodePointer = new Node<T>;
        (*firstNodePointer).setItem(item);
        (*firstNodePointer).setNext(pointerRightShiftedNode);
        return true;
    } else if (position == getLength() + 1) {//insert at very end
        //std::cout<<"\n3\n";
        Node<T> *addedNodePointer = new Node<T>;
        (*getPointer(position - 1)).setNext(addedNodePointer);
        (*addedNodePointer).setItem(item);
        return true;
    } else if (position >= 1 && position <= getLength()) {//insert at middle
        //std::cout<<"4\n";
        Node<T> *addedNodePointer = new Node<T>;
        (*addedNodePointer).setNext(getPointer(position));
        (*addedNodePointer).setItem(item);
        (*getPointer(position - 1)).setNext(addedNodePointer);
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool LinkedList<T>::remove(std::size_t position) {
    Node<T> *pointerOfDeletingNode;
    Node<T> *pointerOfTheNextAvailableNode;
    if (position < getLength() && position >= 1) {
        pointerOfTheNextAvailableNode = getPointer(position + 1);
        pointerOfDeletingNode = getPointer(position);
    } else if (position == getLength()) {
        pointerOfDeletingNode = getPointer(position);
        pointerOfTheNextAvailableNode = nullptr;
    } else {
        return false;
    }
    Node<T> *pointerOfPreviousNode;
    if (position == 1) {
        firstNodePointer = pointerOfTheNextAvailableNode;
    } else {
        pointerOfPreviousNode = getPointer(position - 1);
        (*pointerOfPreviousNode).setNext(pointerOfTheNextAvailableNode);
    }
    delete pointerOfDeletingNode;
    return true;
}

template<typename T>
void LinkedList<T>::clear() {
    std::size_t listLength = getLength();
    if (listLength > 0) {
        for (unsigned int i = listLength; i > 0; i--) {
            Node<T> *nodePointerToDelete = getPointer(i);
            nodePointerToDelete->setNext(nullptr);
            delete nodePointerToDelete;
        }
    }
    firstNodePointer = nullptr;//reclear pointer
}

template<typename T>
T LinkedList<T>::getEntry(std::size_t position) const {
    Node<T> *nodePointer = getPointer(position);
    return ((*nodePointer).getItem());
}

template<typename T>
void LinkedList<T>::setEntry(std::size_t position, const T &newValue) {
    Node<T> *nodePointer = getPointer(position);
    (*nodePointer).setItem(newValue);
}

template<typename T>
Node<T> *LinkedList<T>::getPointer(std::size_t position) const {
    //std::cout << "\n GETTING Pointer: " << (int) position << " " << ((int) getLength());
    if (position > getLength()) {
        std::cout << "\n Warning: " << (int) position << " " << ((int) getLength());
        exit(20);
    } else {
        position--;
        unsigned int counter = 0;
        Node<T> *currentNodePointer = firstNodePointer;
        while (currentNodePointer != nullptr && counter < position) {
            currentNodePointer = (*currentNodePointer).getNext();
            counter++;
        }
        return currentNodePointer;
    }
}

template<typename T>
void LinkedList<T>::copyList(const LinkedList<T> &x) {//custom private function
    std::size_t lengthList = x.getLength();
    for (unsigned int i = 1; i <= lengthList; i++) {
        T acquiredT=x.getEntry(i);
        insert(i,acquiredT);
    }
}