#include <iostream>
#include "include/stack_adt.h"

using namespace std;

int main(void) {
    string input;
    bool valid = true;
    cin >> input;

    summer_projects::stack<char> s;
    for (char c : input) {
        if (c == '(')
            s.push(c);
        else if (s.empty()) {
            valid = false;
            break;
        }
        else s.pop();
    }

    if (valid and s.empty())
        cout << "Valid!" << endl;
    else
        cout << "Not valid!" << endl;

    return 0;
}
