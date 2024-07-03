// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=Bfqd8BsPVuw&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=9

Iterative pre order traversal of binary tree :: Without recursion using stack
With tree in the form of structure.

Time :: O(n)
Space :: O(n) for stack
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
    
    stack<struct node*> st;
    st.push(root);
    
    while(!st.empty()) {
        struct node *temp = st.top();
        st.pop();
        
        cout << temp->data << " ";
        if(temp->right != NULL) {
            st.push(temp->right);
        }
        if(temp->left != NULL) {
            st.push(temp->left);
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
    
    preorder(root);
    
    return 0;
}
