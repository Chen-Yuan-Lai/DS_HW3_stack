#include <iostream>
#include "myStack.cpp"
#include "myStack.h"
using namespace std;

int main()
{
    Bag<int> a;
    myStack<int> b;
    a.Push(1);
    a.Push(2);
    a.Push(3);
    a.Push(4);
    a.Push(5);
    a.Pop();
    b.Push(1);
    b.Push(2);
    b.Push(3);
    b.Push(4);
    b.Push(5);
    b.Pop();
    cout << a << endl;
    cout << b << endl;
    cout << a.Element() << endl;
    cout << b.Element() << endl;
    cout << a.Size() << endl;
    cout << b.Size() << endl;
    return 0;
}