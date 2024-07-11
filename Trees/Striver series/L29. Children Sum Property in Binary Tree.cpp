// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=fnmisPM6cVo&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=29

Bottom up solution.
    -> Each leaf node follows the property.
    -> For each non leaf node :: 
            if left child sum + right child sum == root->data then return.
                                                 >            then increment root->data and return.
                                                 <            then let diff = root->data - (l + r) 
                                                                    now go to any one of its child, increment its value by diff.
                                                                    again go to any of the child, increment its value by diff.
                                                                    continue till leaf node.

Time :: O(n*h)
Space :: O(n)
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
	struct node *root = new node(2);
    root->left = new node(35);
    root->left->left = new node(2);
    root->left->right = new node(3);
    
    root->right = new node(10);
    root->right->left = new node(5);
    root->right->right = new node(2); 
    return root;
}
struct node *tree2() {
    
    struct node *root = new node(50);
    root->left = new node(7);
    root->right = new node(2);
    
    root->left->left = new node(3);
    root->left->right = new node(5);
    
    root->right->left = new node(1);
    root->right->right = new node(30);
    
    return root;
}

void inorder(struct node *root) {
    if(root == NULL) {
        return;
    }
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}



int children_sum(struct node *root) {
    
    if(root->left == NULL and root->right == NULL) {
        return root->data;
    }
    int v1 = 0, v2 = 0;
    if(root->left != NULL) {
        v1 = children_sum(root->left);
    }
    if(root->right != NULL) {
        v2 = children_sum(root->right);
    }
    
    if(root->data <= v1 + v2) {
        root->data = v1 + v2;
        return root->data;
    }
    
    int diff = root->data - (v1 + v2);
    struct node *temp;
    if(root->left != NULL) {
        temp = root->left;
    } else {
        temp = root->right;
    }
    
    while(temp->left != NULL or temp->right != NULL) {
        int d = temp->data;
        d += diff;
        temp->data = d;
        
        if(temp->left != NULL) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    int d = temp->data;
    d += diff;
    temp->data = d;
    
    return root->data;
    
}

int main() {
    
    struct node *root1 = tree1();
    struct node *root2 = tree2();
    
    children_sum(root1);
    children_sum(root2);
    
    inorder(root1);
    cout << '\n';
    inorder(root2);

    return 0;
}
