#include "frontier_queue.hpp"
#include <algorithm>
// TODO implement the member functions here

template<typename T>
State<T> frontier_queue<T>::pop() {
    if (empty()) {
        throw std::logic_error("pop() failed: queue is empty");
    }
    State<T> toReturn = queue.front();
    for (int i = 0; i < queue.size()-1; i++) {
        queue.at(i)=queue.at(i+1);
    }
    queue.pop_back();
    return toReturn;
}

template<typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {
    if (contains(p)) {
        replaceif(p, cost);
    } else {
        State<T> toPushBack(p, cost, heur);
        queue.push_back(toPushBack);
    }
}

template<typename T>
bool frontier_queue<T>::empty() {
    bool toReturn = queue.size() == 0;
    return (toReturn);
}

template<typename T>
bool frontier_queue<T>::contains(const T &p) {
    if (empty()) { return false; }
    for (int indexTemp = 0; indexTemp < queue.size(); indexTemp++) {//寻找queue中等于p的元素
        State<T> stateTemp = queue.at(indexTemp);
        T stateTempTVal = stateTemp.getValue();
        if (stateTempTVal == p) {
            return true;
        }
    }
    return false;
}

template<typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {
    if (empty()) { return; }
    int indexFound = -1;
    for (int indexTemp = 0; indexTemp < queue.size(); indexTemp++) {//寻找queue中等于p的元素
        State<T> stateTemp = queue.at(indexTemp);
        T stateTempTVal = stateTemp.getValue();
        if (stateTempTVal == p) {
            indexFound = indexTemp;
            break;
        }
    }
    if (indexFound != -1) {//找到相应queue元素 && queue中元素cost比输入cost大
        queue[indexFound].updatePathCost(cost);
    }
}


