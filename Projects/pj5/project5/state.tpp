#include "state.hpp"

template<typename T>
State<T>::State(const T &p, std::size_t cost, std::size_t heur)
        : value(p), g(cost), h(heur) {
    f = g + h;
}

template<typename T>
bool State<T>::ifSame(const State<T> &rhs) const {
    bool ifSame_g = g == rhs.getPathCost();
    bool ifSame_f = f == rhs.getFCost();
    bool ifSame_val = value == rhs.getValue();
    return (ifSame_f && ifSame_g && ifSame_val);//必须三个值完全一样才返回true
}

template<typename T>
State<T> &State<T>::operator=(const State<T> &rhs) {
    if (!ifSame(rhs)) {
        value = rhs.value;
        g = rhs.getPathCost();
        h = rhs.getFCost() - rhs.getPathCost();
        f = rhs.getFCost();
    }
    return *this;
}

template<typename T>
T State<T>::getValue() const { return value; }

template<typename T>
void State<T>::updatePathCost(std::size_t cost) {
    g = cost;
    f = g + h;
}

template<typename T>
std::size_t State<T>::getPathCost() const { return g; }

template<typename T>
std::size_t State<T>::getFCost() const { return f; }
