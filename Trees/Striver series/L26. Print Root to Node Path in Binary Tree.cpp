// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=fmflMqVOC7k&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=26

PRINT PATH TO ROOT NODE FROM TARGET NODE.

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

void findPath(struct node *root, stack<int>& path, int tar, bool& flag) {
    
    path.push(root->data);
    
    if(root->data == tar) {
        
        while(!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        
        flag = true;
        return;
    } 
    
    if(flag == false and root->left != NULL) {
        findPath(root->left, path, tar, flag);
    }
    
    if(flag == false and root->right != NULL) {
        findPath(root->right, path, tar, flag);
    }
    
    path.pop();
}

int main() {
    
    struct node *root1 = tree1();
    struct node *root2 = tree2();

   
    stack<int> path;
    bool flag = false;
    findPath(root1, path, 6, flag);
    

    return 0;
}
