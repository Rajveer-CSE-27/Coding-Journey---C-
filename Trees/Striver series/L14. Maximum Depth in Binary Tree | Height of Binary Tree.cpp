// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=eD3tmO66aBA&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=15

Time : O(n)
space : O(h)

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

int fun(struct node *root, int curr_depth) {
	
	if(root == NULL) {
		return curr_depth;
	}
	
	int val1 = fun(root->left, curr_depth+1);
	int val2 = fun(root->right, curr_depth+1);
	
	return max(val1,val2);
	
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
    
    int depth = fun(root, 0);
    cout << depth;
    
    return 0;
}
