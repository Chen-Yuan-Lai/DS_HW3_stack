#include <iostream>
#include <iomanip>
#include "MYStack.h"
using namespace std;

template <class T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity)
{ // constructor
    if (capacity < 1)
        throw "Capacity must be > 0";
    array = new T[capacity];
    top = -1;
}

template <class T>
Bag<T>::~Bag()
{ // destructor
    delete[] array;
}
template <class T>
int Bag<T>::IsEmpty() const
{ // return true if bag is empty
    return Size() == 0;
}

template <class T>
T &Bag<T>::Element() const
{ // return an element tha is in the bag
    if (IsEmpty())
        throw "Bag is empty";
    return array[0];
}

template <class T>
void Bag<T>::changeSize(const int newSize)
{ // increase the size of the array
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
{ // insert an integer into the bag
    if (capacity == top + 1)
        changeSize(2 * capacity);

    array[++top] = x;
}

template <class T>
void Bag<T>::Pop()
{ // delete an integer from the bag
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
            os << left << setw(6) << to_string(s.array[i]);
        else
            os << left << setw(6) << " ";
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
{                        // override Bag's Top function
    if (this->IsEmpty()) // use IsEmpty of Bag
        throw "Stack is empty";
    return this->array[this->top]; // use array of Bag
}

template <class T>
void myStack<T>::Pop()
{                        // override Bag's Pop function
    if (this->IsEmpty()) // use IsEmpty of Bag
        throw "Stack is empty. Cannot delete";
    this->array[this->top--].~T(); // use array of Bag
}