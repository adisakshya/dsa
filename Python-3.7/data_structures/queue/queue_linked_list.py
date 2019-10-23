"""
OPERATIONS ON QUEUE

- ENQUEUE: Add an item in the queue. If queue is full then it is said to be Stack Overflow.
- DEQUEUE: Remove an item from the queue. If the queue is empty, then it is said to be an Underflow condition.
- FRONT: Return front element.
- REAR: Return rear element.
- ISFULL: Check if queue is full.
- ISEMPTY: Check if queue is empty.

TIME COMPLEXITY: 

- ENQUEUE: O(1)
- DEQUEUE: O(1)
- FRONT: O(1)
- REAR: O(1)
- ISFULL: O(1)
- ISEMPTY: O(1)

APPLICATIONS:

- Breadth First Search.
- CPU Scheduling.
- Disk Scheduling.
- IO Buffers.
- Pipes.
- File IO

IMPLEMENTATION WAYS:

- Using array
- Using linked-list
"""

# import modules
from sys import maxsize

"""
Implementation using Linked List

PROS:
- Easy to implement
- Memory saved as no pointers are involved

CONS:
- Not dynamic
"""
# Queue Node
class Node():

    # COnstructor
    def __init__(self, data):
        self.info = data
        self.next = None

# Queue
class Queue():

    # constructor
    # initialize front, rear, size, queue and capacity
    def __init__(self):
        self.front = None
        self.rear = None
    
    # Function to check if queue is empty
    # Returns: Bool
    def is_empty(self):
        return self.front == None
    
    # Function to add item in queue
    # Returns: item inserted in queue
    def en_queue(self, item):
        
        new_node = Node(item)

        if self.is_empty():
            self.front = self.rear = new_node
            return new_node.info
        
        self.rear.next = new_node
        self.rear = new_node
        return self.rear.info
    
    # Function to remove item in queue
    # Returns: (-inf) if underflow else item removed from queue
    def de_queue(self):
        if self.is_empty():
            # return minus infinite
            return str(-maxsize-1)

        temp = self.front
        self.front = self.front.next

        if self.front == None:
            self.rear = None
        return temp.info
    
    # Function to get front element from queue
    # Returns: (-inf) if queue is empty else front item in queue
    def get_front(self):
        if self.is_empty():
            # return minus infinite
            return str(-maxsize-1)
        return self.front.info
    
    # Function to get rear element from queue
    # Returns: (-inf) if queue is empty else rear item in queue
    def get_rear(self):
        if self.is_empty():
            # return minus infinite
            return str(-maxsize-1)
        return self.rear.info


# Driver Code to test above class 
# if __name__ == '__main__': 
  
#     # create Queue class object
#     queue = Queue() 

#     print('Queue: Empty ? ', queue.is_empty())
    
#     # add 10 to queue
#     print('inserting 10')
#     queue.en_queue(10) 
#     print('Front: ', queue.get_front())
#     print('Rear: ', queue.get_rear())
    
#     # add 20 to queue
#     print('inserting 20')
#     queue.en_queue(20) 
#     print('Front: ', queue.get_front())
#     print('Rear: ', queue.get_rear())
    
#     # add 30 to queue
#     print('inserting 30')
#     queue.en_queue(30) 
#     print('Front: ', queue.get_front())
#     print('Rear: ', queue.get_rear())
    
#     # add 40 to queue
#     print('inserting 40')
#     queue.en_queue(40) 
#     print('Front: ', queue.get_front())
#     print('Rear: ', queue.get_rear())
    
#     # remove item from queue
#     print('removing first item')
#     queue.de_queue()
#     print('Front: ', queue.get_front())
#     print('Rear: ', queue.get_rear())