/*
OPERATIONS ON STACK

- PUSH: Add an item in the stack. If stack is full then it is said to be Stack Overflow.
- POP: Remove an item from the stack. If the stack is empty, then it is said to be an Underflow condition.
- Peek or Top: Return top element.
- isEmpty: If stack is empty then return True, else return Falas.

TIME COMPLEXITY: 

- PUSH: O(1)
- POP: O(1)
- Peek or Top: O(1)
- isEmpty: O(1)

APPLICATIONS:

- Balancing of Symbols.
- Infix to Postfix/Prefix conversions.
- Redo-Undo feature at many places like editors, photoshop etc.
- Forward & backward feature in web browsers.
- Tree traversals
- Backtracking
- Soduku Solver
- Topological Sort & Strongly Connected Components in graph algorithms.

IMPLEMENTATION WAYS:

- Using array
- Using linked-list
*/

#include<bits/stdc++.h>
#include<stack>
using namespace std;

void print_stack(stack <int> s) {

    while (!s.empty()) {

        cout << '\t' << s.top();
        s.pop();

    }
    cout << '\n';
}

int main() {

    stack <int> s;
    s.push(20);
    s.push(10);
    s.push(15);
    s.push(1);
    s.push(3);

    cout << "The Stack: ";
    print_stack(s);

    cout << "\nSize of stack: " << s.size();
    cout << "\nTop: " << s.top();

    cout << "\ns.pop(): ";
    s.pop();

    cout << "Now the stack: ";
    print_stack(s);

    return 0;    

}