// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**

https://www.youtube.com/watch?v=BhuvF_-PWS0&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=18

A traversal of a tree is unique. Hence use any traversal to compare two trees.

Time : O(n)
Space : O(h)

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

struct node *tree3() {
	struct node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    
    root->right = new node(111111);
    root->right->left = new node(7);
    root->right->right = new node(8);
    root->right->right->left = new node(9);
    root->right->right->right = new node(10);
    
    
    return root;
}

vector<int> pre_order_1;
vector<int> pre_order_2;

bool check() {
	
	if(pre_order_1.size() != pre_order_2.size()) {
		return false;
	}
	
	for(int i=0; i<pre_order_2.size(); i++) {
		if(pre_order_1[i] != pre_order_2[i]) {
			return false;
		}
	}
	
	return true;
}

void preOrder(struct node *root, int val) {
	
	if(root == NULL) {
		return;
	}
	
	if(val == 1) {
		pre_order_1.push_back(root->data);
	} else {
		pre_order_2.push_back(root->data);
	}
	
	preOrder(root->left, val);
	preOrder(root->right, val);
	
}


int main() {
    
    
    struct node *root1 = tree1();
    struct node *root2 = tree2();
    
    preOrder(root1,1);
    preOrder(root2,2);
    
    (check()) ? cout << "YES\n" : cout << "NO\n";
    
    root2 = tree3();
    pre_order_1.clear();
    pre_order_2.clear();
    
    preOrder(root1,1);
    preOrder(root2,2);
    
    (check()) ? cout << "YES\n" : cout << "NO\n";
    
    
    
    return 0;
}
