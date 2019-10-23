/*
OPERATIONS ON STACK

- PUSH: Add an item in the stack. If stack is full then it is said to be Stack Overflow.
- POP: Remove an item from the stack. If the stack is empty, then it is said to be an Underflow condition.
- Peek or Top: Return top element.
- isEmpty: If stack is empty then return True, else return Falas.
- getMin: Return the minimum element from the stack

TIME & SPACE COMPLEXITY: 

- All Operations: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Stack {
    private:
        stack<int> s;
        int minimum_element;
    public:
        void push(int x);
        int pop();
        int get_top();
        bool isEmpty();
        int get_min();
};

void Stack :: push(int x)
{
    if(s.empty()) {
        s.push(x);
        minimum_element = x;
        return;
    }
    
    if(x <= minimum_element) {
        s.push((2 * x) - minimum_element);
        minimum_element = x;
        return;
    }
    
    s.push(x);
}

int Stack :: pop()
{
    
    if(s.empty()) {
        return INT_MIN;
    }
    
    int top_element = s.top();

    if(top_element == minimum_element) {
        minimum_element = 2 * minimum_element - top_element;
    }

    s.pop();
    return top_element;
}

int Stack :: get_top()
{
    
    if(s.empty()) {
        return INT_MIN;
    }
    
    int top = s.top();
    if(top <= minimum_element) {
        top = (s.top() + minimum_element) / 2;
    } else {
        top = s.top();
    }
    return top;
}

bool Stack :: isEmpty()
{
    
    if(s.empty()) {
        return true;
    } 
    
    return false;
}

int Stack :: get_min()
{
    
    if(s.empty()) {
        return INT_MIN;
    }
    
    return minimum_element;
}

// Driver code to test above code
// int main () {
 
//     Stack s = Stack();
//     s.push(4);
//     cout << "Min: " << s.get_min() << endl;
//     cout << "Top: " << s.get_top() << endl << endl;
    
//     s.push(3);
//     cout << "Min: " << s.get_min() << endl;
//     cout << "Top: " << s.get_top() << endl << endl;
    
    
//     s.push(2);
//     cout << "Min: " << s.get_min() << endl;
//     cout << "Top: " << s.get_top() << endl << endl;
    
//     s.push(1);
//     cout << "Min: " << s.get_min() << endl;
//     cout << "Top: " << s.get_top() << endl << endl;
    
//     return 0;
// }