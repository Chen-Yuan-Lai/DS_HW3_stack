#ifndef STACK_H
#define STACK_H
using namespace std;

template <class T>
class Bag
{
public:
    Bag(int bagCapacity = 10);
    ~Bag();
    int Size() const { return top + 1; }
    int IsEmpty() const { return size == 0; }
    T &Element() const;

    void changeSize(const int newSize);
    void Push(const T &x);
    void Pop();

private:
    T *array;
    int capacity;
    int top;
};
#endif