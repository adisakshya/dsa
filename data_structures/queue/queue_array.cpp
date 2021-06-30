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

class Queue {

    int front, rear, size;
    unsigned capacity;
    int* array;

    public:

        Queue(unsigned limit) {
            
            capacity = limit;
            front = 0;
            size = 0;
            rear = 0;
            array = new int[capacity * sizeof(int)];

        }

        bool is_full();
        bool is_empty();
        int en_queue(int item);
        int de_queue();
        int get_front();
        int get_rear();

};

bool Queue::is_full() {
    return size == capacity;
}

bool Queue::is_empty() {
    return size == 0;
}

int Queue::en_queue(int item) {

    if(is_full()) {
        return INT_MIN;
    }

    if(is_empty()) {
        front = rear = 1;
    }
    else {
        rear += 1;
    }

    array[rear] = item;
    size += 1;
    return array[rear];

}

int Queue::de_queue() {

    if(is_empty()) {
        return INT_MIN;
    }

    if(front == rear) {
        rear += 1;
    }

    int item = array[front];
    front += 1;
    size -= 1;
    return item;

}

int Queue::get_front() {
    if(is_empty()) {
        return INT_MIN;
    }
    return array[front];
}

int Queue::get_rear() {
    if(is_empty()) {
        return INT_MIN;
    }
    return array[rear];
}

// Driver code to test above class
// int main()  
// {  
//     Queue queue = Queue(1000);  
  
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
  
//     cout<<queue.de_queue()<<" dequeued from queue\n";  
//     cout << "Front item is " << queue.get_front() << endl;  
//     cout << "Rear item is " << queue.get_rear() << endl;  
  
//     return 0;  
// }  