#include "bag.hpp"

// empty implementation

template <typename T>
Bag<T>::Bag()
{
      v_numObjects = 0;    //default 0 objects for T
      T *t_pointer = new T[0]; //allocate empty but not null for T
      p_bag_start = t_pointer;
}

template <typename T>
Bag<T>::~Bag()
{
      delete[] p_bag_start;
}

template <typename T>
std::size_t Bag<T>::getCurrentSize() const
{
      size_t toReturn = v_numObjects;
      return toReturn;
}

template <typename T>
bool Bag<T>::isEmpty() const
{
      return ((getCurrentSize() == 0) ? true : false);
}

template <typename T>
bool Bag<T>::add(const T &entry)
{
      p_bag_start[v_numObjects] = entry;
      v_numObjects++;
      return true;
}

template <typename T>
bool Bag<T>::remove(const T &entry)
{
      bool ifFoundAndRemoved = 0;
      for (int index = 0; index < v_numObjects; index++)
      {
            if (entry == p_bag_start[index])
            {
                  p_bag_start[index] = p_bag_start[v_numObjects - 1]; //remove last item to current positiion
                  v_numObjects--;                                     //decrease operational index by 1
                  ifFoundAndRemoved = 1;
                  return 1;
            }
      }
      return ifFoundAndRemoved;
}

template <typename T>
void Bag<T>::clear()
{
      delete[] p_bag_start;
      v_numObjects = 0;    //default 0 objects for T
      T *t_pointer = new T[0]; //allocate empty but not null for T
      p_bag_start = t_pointer;
}

template <typename T>
std::size_t Bag<T>::getFrequencyOf(const T &entry) const
{
      size_t howMany = 0;
      for (int index = 0; index < v_numObjects; index++)
      {
            if (entry == p_bag_start[index])
            {
                  howMany++;
            }
      }
      return howMany;
}

template <typename T>
bool Bag<T>::contains(const T &entry) const
{
      size_t freq = getFrequencyOf(entry);
      bool toReturn = ((freq==0)?0:1);
      return toReturn;
}
