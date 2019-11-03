#include<bits/stdc++.h>
using namespace std;

// Linked List Node
class Node {
    public:
        int data;
        Node *next;
};

// Function to print the linked list
void print_list(Node *head_ref) {
    
    if(head_ref == NULL) {
        cout << "Empty List";
        return;
    }
    
    cout << "The Linked List is: ";
    Node *current = head_ref;
    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

// Function to insert new node at front of the list
void push(Node **head_ref, int info) {
    Node *new_node = new Node();
    new_node->data = info;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to insert new node after a given position
void insert(Node *prev_node, int info) {
    if(prev_node == NULL) {
        cout << "Previous node cannot be null";
        // or insert at head
        
        return;
    }

    Node *new_node = new Node();
    new_node->data = info;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to insert new node at end of list
void append(Node **head_ref, int info) {
    
    Node *new_node = new Node();
    new_node->data = info;
    new_node->next = NULL;
    
    if((*head_ref) == NULL) {
        (*head_ref) = new_node;
        return;
    }

    Node *current = (*head_ref);

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void delete_node(Node **head_ref, int key) {
    Node *current = (*head_ref), *prev = NULL;
    
    // If head node is to be deleted
    if(current != NULL && current->data == key) {
        (*head_ref) = current->next;
        free(current);
        return;
    }

    while(current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if(current == NULL) {
        // node not found
        return;
    }

    prev->next = current->next;
    free(current);
}

void delete_list(Node **head_ref) {
    
    // Empty linked list
    if((*head_ref) == NULL) {
        cout << "Empty List" << endl;
        return;
    }

    Node *current = (*head_ref);
    while((*head_ref) != NULL) {
        current = (*head_ref);
        (*head_ref) = (*head_ref)->next;
        free(current);
    }    
}

int list_length(Node *head_ref) {  
    int count = 0;  
    Node *current = head_ref;  
    while (current != NULL) {  
        count++;  
        current = current->next;  
    }  
    return count;  
}  

bool search(Node *head_ref, int info) {  
    Node *current = head_ref; 
    while (current != NULL) {  
        if (current->data == info) {
            return true;
        }  
        current = current->next;  
    }  
    return false;  
}  

int get_n_node(Node *head_ref, int req_index) {  
      
    Node *current = head_ref;  
      
    int index = 0;  
    while (current != NULL) {  
        if (index == req_index) {
            return(current->data);
        }  
        index++;  
        current = current->next;  
    }  
  
    return INT_MIN;    
}

int get_n_last_node(Node *head_ref, int req_index) {  
      
    Node *current = head_ref;  
    int length = list_length(head);

    int index = 0;
    while (current != NULL) {  
        if (index == (length - req_index + 1)) {
            return(current->data);
        }  
        index++;  
        current = current->next;  
    }  
  
    return INT_MIN;    
}

int middle_node(Node *head_ref) {  
      
    Node *slow = head_ref, *fast = head_ref;  

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int count(Node *head_ref, int key) {
    Node *current = head_ref;
    int count = 0;
    while(current != NULL) {
        if(current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
} 

bool detect_loop(Node *head_ref) {
    unordered_set<Node *> node_map;
    Node *current = head_ref;

    while(current != NULL) {
        if(node_map.find(current) != node_map.end()) {
            return true;
        } else {
            node_map.insert(current);
        }
        current = current->next;
    }

    return false;
}

bool floyd_warshall_cycle_detection(Node *head_ref) {
    Node *slow = head_ref;
    Node *fast = head_ref;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return true;
        }
    }

    return false;
}

int loop_list_length(Node *head_ref) {  
    int count = 1;  
    Node *current = head_ref;  
    while (current->next != head_ref) {  
        count++;  
        current = current->next;  
    }  
    return count;  
}

int loop_length(Node *head_ref) {
    
    if(!detect_loop(head_ref)) {
        return INT_MIN;
    }
    
    Node *slow = head_ref;
    Node *fast = head_ref;

    while(fast != NULL && fast->next != NULL) {
        if(slow == fast) {
            return loop_list_length(slow);
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return INT_MIN;
}

bool compare_lists(Node *head_ref_1, Node *head_ref_2) {
    
    Node *current_1 = head_ref_1;
    Node *current_2 = head_ref_2;

    while(current_1 != NULL && current_2 != NULL) {
        if(current_1->data != current_2->data) {
            return false;
        }
        current_1 = current_1->next;
        current_2 = current_2->next;
    }

    return true
}

bool is_palindrome(Node *head_ref) {
    
    Node *slow = head_ref; 
  
    stack <int> s; 
    
    while(slow != NULL) { 
        s.push(slow->data); 

        slow = slow->next; 
    } 

    while(head_ref != NULL ) { 
        int i = s.top(); 
        s.pop(); 
        if(head_ref->data != i) { 
            return false; 
        } 
        head_ref = head_ref->next; 
    }
    return true; 
}

void remove_duplicates_sorted(Node *head_ref) {
    Node *current = head_ref;

    while(current != NULL && current->next != NULL) {
        if(current->data == current->next->data) {
            Node *next_next = current->next->next;
            current->next->next = NULL;
            Node *temp = current->next;
            current->next = next_next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void remove_duplicates_unsorted(Node *head_ref) {
    Node *current = head_ref, *prev;
    unorderd_set <int> seen_nodes;

    while(current != NULL) {
        if(seen_nodes.find(current->data) != seen_nodes.end()) {
            prev->next = current->next;
            free(current);
        } else {
            seen_nodes.insert(current->data);
            prev = current;
        }
        current = prev->next;
    }
}

void swap_nodes(Node **head_ref, int key1, int key2) {
    Node *current = (*head_ref), *prev1 = NULL, *prev2 = NULL, *prev = NULL;

    while(current != NULL) {
        if(current->data == key1) {
            prev1 = prev;
        } else if(current->data == key2) {
            prev2 = prev;
        }

        prev = current;
        current = current->next;
    }

    Node *node1 = prev1->next, *node2 = prev2->next;
    node1->next = node2->next;
    node2->next = node1->next->next;

    prev1->next = node1;
    prev2->next = node2;

    if(prev1 == NULL) {
        (*head_ref) = node2;   
    } else if(prev2 == NULL) {
        (*head_ref) = node1;
    }

}

void make_last_first(Node *head_ref) {
    Node *current = (*head_ref), *prev = NULL;
    
    if((*head_ref) == NULL || (*head_ref)->next == NULL) {
        return;
    }

    while(current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    current->next = (*head_ref);
    (*head_ref) = current;

}

int intersection_point(Node *head_ref_1, Node *head_ref_2) {

    int len1 = list_length(head_ref_1);
    int len2 = list_length(head_ref_2);
    
    int k = (len1 > len2) ? (len1 - len2) : (len2 - len1);
    int flag = (len1 > len2) ? 1 : 2;

    Node *current1 = head_ref_1, *current2 = head_ref_2;
    while(k--) {
        if(flag == 1) {
            current1 = current1->next;
        } else if(flag == 2) {
            current2 = current2->next;
        }
    }
    
    while(current1 != NULL && current2 != NULL) {
        
        if(current1->data == current2->data) {
            return current1->data;
        }
        
        current1 = current1->next;
        current2 = current2->next;
    }
}

void reverse(Node *head_ref) {
    Node *current = (head_ref), *prev = NULL, *next_node = NULL;

    while(current != NULL) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    (head_ref) = prev;
}

// int main()  
// {  
//     /* Start with the empty list */
//     Node* head = NULL;  
      
//     // Insert 6. So linked list becomes 6->NULL  
//     append(&head, 6);  
      
//     // Insert 7 at the beginning.  
//     // So linked list becomes 7->6->NULL  
//     push(&head, 7);  
      
//     // Insert 1 at the beginning.  
//     // So linked list becomes 1->7->6->NULL  
//     push(&head, 1);  
      
//     // Insert 4 at the end. So  
//     // linked list becomes 1->7->6->4->NULL  
//     append(&head, 4);  
      
//     // Insert 8, after 7. So linked  
//     // list becomes 1->7->8->6->4->NULL  
//     insert(head->next, 8);  
      
//     print_list(head);  
//     cout<<endl;
    
//     delete_node(&head, 4);
//     print_list(head);  
//     cout << endl;
    
//     delete_list(&head);
//     print_list(head);
    
//     return 0;  
// }  