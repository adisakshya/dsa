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
Implementation using Array

PROS:
- Easy to implement
- Memory saved as no pointers are involved

CONS:
- Not dynamic
"""
class Queue():

    # constructor
    # initialize front, rear, size, queue and capacity
    def __init__(self, capacity):
        self.front = 0
        self.size = 0
        self.rear = 0
        self.Q = [None] * capacity
        self.capacity = capacity
    
    # Function to check if queue is full
    # Returns: Bool
    def is_full(self):
        return self.size == self.capacity
    
    # Function to check if queue is empty
    # Returns: Bool
    def is_empty(self):
        return self.size == 0
    
    # Function to add item in queue
    # Returns: (-inf) if overflow else item inserted in queue
    def en_queue(self, item):
        if self.is_full():
            # return minus infinite
            return str(-maxsize-1)
        
        if self.is_empty():
            self.front = self.rear = 1
        else:
            self.rear += 1
        
        self.Q[self.rear] = item
        self.size += 1
        return self.Q[self.rear]
    
    # Function to remove item in queue
    # Returns: (-inf) if underflow else item removed from queue
    def de_queue(self):
        if self.is_empty():
            # return minus infinite
            return str(-maxsize-1)

        de_queued = self.Q[self.front]

        if self.front == self.rear:
            self.rear += 1
        
        self.front += 1
        self.size -= 1
        return de_queued
    
    # Function to get front element from queue
    # Returns: (-inf) if queue is empty else front item in queue
    def get_front(self):
        if self.is_empty():
            # return minus infinite
            return str(-maxsize-1)
        return self.Q[self.front]
    
    # Function to get rear element from queue
    # Returns: (-inf) if queue is empty else rear item in queue
    def get_rear(self):
        if self.is_empty():
            # return minus infinite
            return str(-maxsize-1)
        return self.Q[self.rear]


# Driver Code to test above class 
# if __name__ == '__main__': 
  
#     # create Queue class object
#     queue = Queue(30) 

#     print('Queue: Empty ? ', queue.is_empty(), ' FULL ? ', queue.is_full())
#     print('Front: ', queue.get_front())
#     print('Rear: ', queue.get_rear())
    
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