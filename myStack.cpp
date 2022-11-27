#include <iostream>
#include <iomanip>
#include "MYStack.h"
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
int Bag<T>::IsEmpty() const
{
    return Size() == 0;
}

template <class T>
T &Bag<T>::Element() const
{
    if (IsEmpty())
        throw "Bag is empty";
    return array[0];
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
        changeSize(2 * capacity);

    array[++top] = x;
}

template <class T>
void Bag<T>::Pop()
{
    if (IsEmpty())
        throw "Bag is empty, cannot delete";
    int deletePos = top / 2;
    // compact array
    copy(array + deletePos + 1, array + top + 1, array + deletePos);
    array[top--].~T();
}

template <class T>
ostream &operator<<(ostream &os, Bag<T> &s)
{
    for (int i = 0; i < s.capacity; i++)
    {
        string index = "[" + to_string(i) + "]";
        os << left << setw(6) << index;
    }
    os << endl;
    for (int i = 0; i < s.capacity; i++)
    {
        if (i < s.top + 1)
        {
            os << left << setw(6) << to_string(s.array[i]);
        }
        else
        {
            os << left << setw(6) << " ";
        }
    }
    os << endl;
    return os;
}

template <class T>
myStack<T>::myStack(int myStackCapacity) : Bag<T>(myStackCapacity) {}
// Constructors for Stack calls constructor for Bag

template <class T>
myStack<T>::~myStack() {}
// Destructor for Bag is automatically called when myStack
// is destroyed. This ensures array is deleted.

template <class T>
T &myStack<T>::Top() const
{
    if (this->IsEmpty())
        throw "Stack is empty";
    return this->array[this->top];
}

template <class T>
void myStack<T>::Pop()
{
    if (this->IsEmpty())
        throw "Stack is empty. Cannot delete";

    this->array[this->top--].~T();
}