// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**

https://www.youtube.com/watch?v=RlUu72JrOCQ&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=5

Preorder traversal of binary tree :: root, left, right
With tree in the form of structure.

Time :: O(n)
Auxillary stack space :: O(n) in worst case tree skew bhi ho sakta hai
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

void preorder(struct node *root) {
    
    // base case 
    if(root == NULL) {
        return;
    }
    
    // print root
    cout << root->data << " ";
    // go left
    preorder(root->left);
    // go right
    preorder(root->right);
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
    
    preorder(root);
    
    return 0;
}
