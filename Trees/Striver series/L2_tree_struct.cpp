// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=ctCpP0RFDFc&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=2

This structure is true for only binary trees
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

int main() {
    
    struct node *root = new node(1);
    root->left = new node(0);
    root->right = new node(2);
    
    root->right->right = new node(3);
    
    cout << root->left->data << " " << root->data << " " << root->right->data << " " << root->right->right->data;
    
    return 0;
}
