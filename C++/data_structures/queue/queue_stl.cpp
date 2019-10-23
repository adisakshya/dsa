/*
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
*/

#include<bits/stdc++.h>
#include<queue>
using namespace std;

void print_queue(queue <int> q) {
    queue <int> tempq = q;
    while(!tempq.empty()) {
        cout << tempq.front() << " ";
        tempq.pop();
    }
}

int main()  
{  
    queue <int> q; 
    q.push(10); 
    q.push(20); 
    q.push(30); 
    q.push(40); 
  
    cout << "The queue is : "; 
    print_queue(q); 
  
    cout << "\nsize() : " << q.size(); 
    cout << "\nfront() : " << q.front(); 
    cout << "\nback() : " << q.back(); 
    q.pop(); 
    cout << "\nAfter pop() : "; 
    print_queue(q);
  
    return 0;  
}  