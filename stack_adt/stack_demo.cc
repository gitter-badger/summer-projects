#include <iostream>
#include "include/stack_adt.h"
#include "src/stack_adt.cc"

using namespace std;

int main(int argc, char *argv[])
{
    stack<int> s;
    cout << "stack size: " << s.size() << endl;
    for (int i = 0; i < 10; ++i)
        s.push(i);
    cout << "stack size: " << s.size() << endl;

    while (not s.empty())
        cout << "Frame content: " << s.pop() << endl;

    cout << "stack size: " << s.size() << endl;

    try {
        s.pop();
    } catch (StackEmptyException& e) {
        cout << "Stack is empty!" << endl;
    }

    return 0;
}
