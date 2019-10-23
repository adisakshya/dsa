#include<bits/stdc++.h>
using namespace std;

class StackQueue {
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        void push(int B);
        int pop();
        int get_front();
        int get_rear();
};

void StackQueue :: push(int x)
 {
    
    while(!s1.empty()) {
        int top = s1.top();
        s2.push(top);
        s1.pop();
    }
    
    s1.push(x);
    while(!s2.empty()) {
        int top = s2.top();
        s1.push(top);
        s2.pop();
    }
}

int StackQueue :: pop()
{
    
    if(s1.empty()) {
        return INT_MIN;
    }
    
    int front = s1.top();
    s1.pop();
    return front;
}

int StackQueue :: get_front()
{
    
    if(s1.empty()) {
        return INT_MIN;
    }
    
    int front = s1.top();
    return front;
}

int StackQueue :: get_rear()
{
    
    if(s1.empty()) {
        return INT_MIN;
    }
    
    int rear = -1;
    while(!s1.empty()) {
        int top = s1.top();
        rear = top;
        s2.push(top);
        s1.pop();
    }
    
    while(!s2.empty()) {
        int top = s2.top();
        s1.push(top);
        s2.pop();
    }

    return rear;
}