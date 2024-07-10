// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=_-QHfMDde90&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=27

Lowest common ancestor in Binary tree.
Time : O(n)
Space : O(h) stack space.

See video for what is LCA

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

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

// NOTE : this problem assumes that both a and b are present in tree.
int lca(struct node *root, int a, int b) {
    
    // if we have found a node having value either a or b then we will return from that value. As that same node could be lca(a,b).
    // Else we check for lca in left subtree and right subtree.
    // If we get a value from both left and right subtree then this current node will be lca then only its left subtree contained one of the values and right subtree contained other.
    // If we get a value from one of the left or right subtree then we forward that same value further.
    // at the end the value returned by root will be the lca(a,b).
    // se video for better explaination
    
    if(root == NULL) {
        return -1;
    }
    
    if(root->data == a or root->data == b) {
        return root->data;
    }
    
    int v1 = lca(root->left, a, b);
    int v2 = lca(root->right, a, b);
    
    if(v1 == -1 and v2 == -1) {
        return -1;
    }
    
    if(v1 == -1 or v2 == -1) {
        return max(v1,v2);
    }
    
    return root->data;
    
}

int main() {
    
    struct node *root1 = tree1();
    cout << lca(root1, 7, 10) << '\n';
    cout << lca(root1, 7, 6) << '\n';
    cout << lca(root1, 2, 6) << '\n';
    cout << lca(root1, 10, 10) << '\n';
    

    return 0;
}
