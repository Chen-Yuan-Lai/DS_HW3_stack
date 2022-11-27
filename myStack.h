#ifndef MYSTACK_H
#define MYSTACK_H
using namespace std;

template <class T>
class Bag
{
public:
    Bag(int bagCapacity = 10);
    ~Bag();
    int Size() const { return top + 1; }
    int IsEmpty() const;
    T &Element() const;

    void changeSize(const int newSize);
    void Push(const T &x);
    void Pop();
    template <typename U>
    friend ostream &operator<<(ostream &os, Bag<U> &s);

protected:
    T *array;
    int capacity;
    int top;
};

template <class T>
class myStack : public Bag<T>
{
public:
    myStack(int myStackCapacity = 10);
    ~myStack();
    T &Top() const;
    void Pop();
};

#endif