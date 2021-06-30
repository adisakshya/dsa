#include<bits/stdc++.h>
using namespace std;

// Binary Tree Node
class Node {
    public:
        int data;
        Node *left;
        Node *right;
};

// Traversals
void inOrder(Node* root)
{
    if(root == NULL) {
        return;    
    }
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
  
}

void preOrder(Node* root)
{
    if(root == NULL) {
        return;    
    }
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
  
}

void postOrder(Node* root)
{
    
    if(root == NULL) {
        return;    
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}