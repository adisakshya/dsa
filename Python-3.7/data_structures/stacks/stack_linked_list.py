"""
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
"""

# import modules
from sys import maxsize

"""
Implementation using Linked List

PROS:
- Dynamic

CONS:
- Require more space as pointers are involved
"""

# Class for stack node
class Node():

    def __init__(self, item):
        self.info = item
        self.next = None

# Stack using linked lists
class stack():

    # constructor creating an empty stack
    def __init__(self):
        self.head = None

    # Function to check if stack is empty
    def is_empty(self):
        return self.head is None
    
    # Function to push new item in the stack
    def push(self, item):
        new_node = Node(item)
        new_node.next = self.head
        self.head = new_node
        return new_node.info
    
    # Function to pop element from stack
    def pop(self):
        if self.is_empty():
            # return minus infinite
            return str(-maxsize-1)
        
        temp = self.head
        self.head = self.head.next
        popped = temp.info
        return popped
    
    # Function to return top-most element from stack
    def top(self):
        if self.is_empty():
            return False
        return self.head.info