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
using namespace std;

class Node {
    public:
        int info;
        Node * next;

        Node(int item) {
            info = item;
            next = NULL;
        }
};

class Queue {

    Node *front, *rear;
    unsigned int capacity, size;
    
    public:

        Queue(unsigned int limit) {
            
            front = NULL;
            rear = NULL;
            capacity = limit;
            size = 0;
        }

        bool is_empty();
        bool is_full();
        int en_queue(int item);
        int de_queue();
        int get_front();
        int get_rear();

};

bool Queue::is_empty() {
    return front == NULL;
}

bool Queue::is_full() {
    return capacity == size;
}

int Queue::en_queue(int item) {

    if(is_full()) {
        return INT_MIN;
    }

    Node * new_node = new Node(item);

    if(is_empty()) {
        front = rear = new_node;
        size += 1;
        return rear->info;
    }
    
    rear->next = new_node;
    rear = new_node;
    size += 1;
    return rear->info;

}

int Queue::de_queue() {

    if(is_empty()) {
        return INT_MIN;
    }

    Node * temp = front;
    front = front->next;

    if(front == NULL) {
        rear = NULL;
    }
    
    size--;
    return temp->info;

}

int Queue::get_front() {
    if(is_empty()) {
        return INT_MIN;
    }
    return front->info;
}

int Queue::get_rear() {
    if(is_empty()) {
        return INT_MIN;
    }
    return rear->info;
}

// Driver code to test above class
// int main()  
// {  
//     Queue queue = Queue(100000);  
  
//     cout << "EN-QUEUE: " << queue.en_queue(10) << endl;  
//     cout << "Front item is " << queue.get_front() << endl;  
//     cout << "Rear item is " << queue.get_rear() << endl;  
    
//     cout << "EN-QUEUE: " << queue.en_queue(20) << endl;  
//     cout << "Front item is " << queue.get_front() << endl;  
//     cout << "Rear item is " << queue.get_rear() << endl;  
    
//     cout << "EN-QUEUE: " << queue.en_queue(30) << endl;  
//     cout << "Front item is " << queue.get_front() << endl;  
//     cout << "Rear item is " << queue.get_rear() << endl;  
  
//     cout << "EN-QUEUE: " << queue.en_queue(40) << endl;  
//     cout << "Front item is " << queue.get_front() << endl;  
//     cout << "Rear item is " << queue.get_rear() << endl;  
  
//     cout << queue.de_queue() << " dequeued from queue\n";  
//     cout << "Front item is " << queue.get_front() << endl;  
//     cout << "Rear item is " << queue.get_rear() << endl;  
  
//     return 0;  
// }  