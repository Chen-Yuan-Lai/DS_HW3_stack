#include <iostream>
#include "stack.h"
using namespace std;

template <class T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity)
{
    if (capacity < 1)
        throw "Capacity must be > 0";
    array = new T[capacity];
    top = -1;
}

template <class T>
Bag<T>::~Bag()
{
    delete[] array;
}

template <class T>
void Bag<T>::changeSize(const int newSize)
{
    if (newSize < capacity)
        throw "New length must be > bag size";

    T *temp = new T[newSize];
    copy(array, array + capacity, temp);
    delete[] array;
    array = temp;
    capacity = newSize;
}

template <class T>
void Bag<T>::Push(const T &x)
{
    if (capacity == top + 1)
    {
        changeSize(2 * capacity);
    }
    array[++top] = x;
}

template <class T>
void Bag<T>::Pop()
{
    if (IsEmpty())
        throw "Bag is empty, cannot delete";
    int deletePos = top / 2;
    copy(array + deletePos + 1, array + tep + 1, array + deletePos)
}
