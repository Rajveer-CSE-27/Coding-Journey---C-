// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**

https://www.youtube.com/watch?v=EoAsWbO7sqg&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=8

Level order traversal of binary tree :: 
With tree in the form of structure.

Time :: O(n)
Space :: O(n) for queue
**/

struct node {
    int data;
    struct node *left;
    struct node *right;
    
    node(int val) {
        data = val;
        left = right = NULL;
    }
};

void levelorder(struct node *root) {
    
    queue<struct node*> q;
    q.push(root);
    
    while(!q.empty()) {
        
        struct node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left != NULL) {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        }
    }
    
}

int main() {
    
    // forming a tree
    struct node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    
    root->right = new node(3);
    root->right->left = new node(7);
    root->right->right = new node(8);
    root->right->right->left = new node(9);
    root->right->right->right = new node(10);
    
    levelorder(root);
    
    return 0;
}
