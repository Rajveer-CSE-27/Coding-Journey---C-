// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=nKggNAiEpBE&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=25

Check whether the binary tree is symmetric or not.
That is whether it forms its mirror arround its root node or not. See video for explaination

Left subtree and right subtree ka BFS karo and compare karte jao in each iteration.

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
    
    struct node *root= new node(1);
    root->left = new node(2);
    root->right = new node(2);
    
    root->left->left = new node(3);
    root->left->right = new node(4);
    
    root->right->left = new node(4);
    root->right->right = new node(3);
    
    return root;
}
struct node *tree3() {
    
    // IMP example This is not symmetric. 
    // due to these types of examples you cannot use BFS
    
    struct node *root= new node(1);
    root->left = new node(2);
    root->right = new node(2);
    
    root->left->right = new node(3);
    
    root->right->right = new node(3);
    
    return root;
    
}

bool check(struct node *l, struct node *r) {
    
    if(l == NULL and r == NULL) {
        return true;
    }
    if(l == NULL or r == NULL) {
        return false;
    }
    
    if(l->data != r->data) {
        return false;
    }
    
    // at any node check the left child of first node and right child of second
    // also check right child of first node and left child of second node.
    
    bool flag1 = check(l->left, r->right);
    bool flag2 = check(l->right, r->left);
    
    return flag1 and flag2;
    
}

bool isSymmetrical(struct node *root) {
    
    if(root == NULL) {
        return true;
    }
    return check(root->left, root->right);
}


int main() {
    
    struct node *root1 = tree1();
    struct node *root2 = tree2();
    struct node *root3 = tree3();
   
    (isSymmetrical(root1)) ? cout << "YES\n" : cout << "NO\n";
    (isSymmetrical(root2)) ? cout << "YES\n" : cout << "NO\n";
    (isSymmetrical(root3)) ? cout << "YES\n" : cout << "NO\n";
   
    return 0;
}
