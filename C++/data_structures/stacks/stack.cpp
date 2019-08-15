/* C++ program to implement basic stack operations */
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

class array_stack {
    int top;

    public:

        // maximum size of stack
        int stack[MAX];
        
        // constructor
        array_stack() {
            top = -1;
        }

        bool push(int item);
        bool pop();
        int top();
        bool is_empty();

};

/* Function to add an item to stack
*  It increase size of stack by 1
*/
bool array_stack::push(int item) {

    if(top >= (MAX-1)) {
        // Overflow condition
        return false;
    }

    // Insert item
    stack[++top] = item;
    return true;

}

/* Function to remove an item to stack
*  It decrease size of stack by 1
*/
bool array_stack::pop() {

    if(top < 0) {
        // Underflow condition
        return false;
    }

    // Delete item
    top--;
    return true;

}

/* Function to return top element of stack */
int array_stack::top() {

    if(top < 0) {
        // Empty array_stack
        return 0;
    }

    // return top element
    return stack[top];

}

/* Function to check if stack is empty */
bool array_stack::is_empty() {

    return top < 0;

}
