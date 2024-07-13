// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=80Zug6D1_r4&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=37

Morris Traversal.
Can do inorder, preorder and postorder Morris traversal.

Time complexity:: O(n) 
        At each node we try to reach rightmost element of leftsubtree. Overall amortized complexity of this will be : O(n)
        Total node O(n)
        
        Total time :: O(n) + O(n) = O(n).
 
Space complexity :: O(1) Hence this is space efficient.

**/
struct node {
    int data;
    struct node *left;
    struct node *right;
    
    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct node *tree1() {
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
    
    
    return root;
}
struct node *tree2() {
    
    struct node *root = new node(1);
    root->left = new node(2);
    
    
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->left->left = new node(5);
    root->right->left->left->left = new node(6);
    
    root->right->right = new node(7);
    root->right->right->right = new node(8);
    root->right->right->right->right = new node(10);
    
    return root;
}

struct node *tree3() {
    
    struct node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);

    
    root->right = new node(3);
    
    return root;
}

struct node *tree4() {
    struct node *root = new node(-10);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);
    
    
    return root;
}

struct node *tree5() {
    struct node *root = new node(15);
    root->left = new node(10);
    root->right = new node(20);
    root->right->left = new node(-30);
    root->right->right = new node(-15);
    
    
    return root;
}

void inorder_morris(struct node *root) {
    
    struct node *temp = root;
    
    while(temp != NULL) {
        // first check if left child is NULL
        if(temp->left == NULL) {

            cout << temp->data << " "; // because its inorder Hence print node
            temp = temp->right;
            
        } else {
            // first go to the extreme right of this subtree.
            struct node *it = temp->left;
            
            while(it->right != NULL and it->right != temp) {
                it = it->right;
            }
            
            if(it->right == NULL) {
                // make thread to prev root
                it->right = temp;
                temp = temp->left;
            } else {
                
                // delete the thread
                it->right = NULL;
                cout << temp->data << " ";
                temp = temp->right;
            }
        }
        
       
    }
     cout << '\n';
}

void preorder_morris(struct node *root) {
    
    struct node *temp = root;
    
    while(temp != NULL) {
        
        //preorder hence first print root
        
        if(temp->left == NULL) {
            cout << temp->data << " ";
            temp = temp->right;
            
        } else {
            
            
            struct node *it = temp->left;
            while(it->right != NULL and it->right != temp) {
                it = it->right;
            }
            
            if(it->right == NULL) {
                
                it->right = temp;
                // this line gives us guarantee that we are at temp Node for the first time hence print it.
                cout << temp->data << " ";
                temp = temp->left;
            } else {
                it->right = NULL;
                temp = temp->right;
            }
        }
        
    }
    cout << '\n';
    
}

int main() {
    
    inorder_morris(tree1());
    inorder_morris(tree2());
    inorder_morris(tree3());
    inorder_morris(tree4());
    inorder_morris(tree5());
    
    cout << '\n';
    preorder_morris(tree1());
    preorder_morris(tree2());
    preorder_morris(tree3());
    preorder_morris(tree4());
    preorder_morris(tree5());
        
    
    return 0;
}
