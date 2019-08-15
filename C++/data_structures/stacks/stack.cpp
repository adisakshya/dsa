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
#define MAX 1000
using namespace std;

// Implementation of stack using array
class array_stack {

    // top counter
    int top;

    public:

        // maximum size of stack
        int stack[MAX];
        
        // constructor
        array_stack() {
            top = -1;
        }

        // stack operations
        int push(int item);
        int pop();
        int get_top();
        bool is_empty();

};

/* Function to add an item to stack
*  It increase size of stack by 1
*/
int array_stack::push(int item) {

    if(top >= (MAX-1)) {
        // Overflow condition
        return INT_MIN;
    }

    // Insert item
    stack[++top] = item;
    return stack[top];

}

/* Function to remove an item to stack
*  It decrease size of stack by 1
*/
int array_stack::pop() {

    if(top < 0) {
        // Underflow condition
        return INT_MIN;
    }

    // Delete item
    int popped = stack[top];
    top--;
    return popped;

}

/* Function to return top element of stack */
int array_stack::get_top() {

    if(top < 0) {
        // Empty stack
        return INT_MIN;
    }

    // return top element
    return stack[top];

}

/* Function to check if stack is empty */
bool array_stack::is_empty() {

    return top < 0;

}


/* Implementation of stack using linked lists */
class Node {
    public:
        int info;
        Node* next;
};

class linked_list_stack {
        
        Node * head;    
        
    public:
    
        linked_list_stack() {
            Node * head = NULL;
        }
        
        int push(int item);
        int pop();
        int top();
        bool is_empty();

};

int linked_list_stack::push(int item) {

    Node * new_node = new Node;
    new_node->info = item;
    new_node->next = NULL;

    if(is_empty()) {
        head = new_node;
        return new_node->info;
    }

    new_node->next = head;
    head = new_node;
    return new_node->info;
}

int linked_list_stack::pop() {

    if(is_empty()) {
        return INT_MIN;
    }

    Node * temp = head;
    head = head->next;
    int popped = temp->info;
    free(temp);
    return popped;
}

int linked_list_stack::top() {

    if(is_empty()) {
        return INT_MIN;
    }

    return head->info;
}

bool linked_list_stack::is_empty() {
    return head == NULL;
}