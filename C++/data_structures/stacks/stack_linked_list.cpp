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

/* Implementation of stack using linked lists */
class Node {
    public:
        int info;
        Node* next;
};

class stack {
        
        Node * head;    
        
    public:
    
        stack() {
            Node * head = NULL;
        }
        
        int push(int item);
        int pop();
        int top();
        bool is_empty();

};

int stack::push(int item) {

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

int stack::pop() {

    if(is_empty()) {
        return INT_MIN;
    }

    Node * temp = head;
    head = head->next;
    int popped = temp->info;
    free(temp);
    return popped;
}

int stack::top() {

    if(is_empty()) {
        return INT_MIN;
    }

    return head->info;
}

bool stack::is_empty() {
    return head == NULL;
}