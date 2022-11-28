#include <iostream>
#include "myStack.cpp"
#include "myStack.h"
using namespace std;

int main()
{
    // uses Bag constructor to create array of  capacity
    Bag<int> b(3);
    // uses myStack constructor to create array of  capacity
    myStack<int> s(3);
    // use Bag::Push
    b.Push(1);
    b.Push(2);
    b.Push(3);
    cout << b << endl;
    // myStack::Push not defined, so use  Bag::Push
    s.Push(1);
    s.Push(2);
    s.Push(3);
    cout << s << endl;
    // uses Bag::Pop, which calls Bag::IsEmpty
    b.Pop();
    cout << b << endl;
    // uses myStack::Pop,which calls Bag::IsEmpty because IsEmpty
    // has not been defined in myStack
    s.Pop();
    cout << s << endl;
    cout << s.Size() << endl;    // uses Bag::Size
    cout << s.Element() << endl; // uses Bag::Element
    return 0;
}