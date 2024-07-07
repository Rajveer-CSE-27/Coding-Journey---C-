// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=0ca1nvR0be4&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=20

Boundary traversal :: 
	
	The left boundary is defined as the path from the root to the left-most node. 
	The right boundary is defined as the path from the root to the right-most node. 
	If the root doesn’t have left subtree or right subtree, then the root itself is left boundary or right boundary. 
	Note this definition only applies to the input binary tree, and not apply to any subtrees.
	
	The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if it exists. 
	If not, travel to the right subtree. Repeat until you reach a leaf node.
	The right-most node is also defined in the same way with left and right exchanged. 
	
Boundary order traversal me sirf left boundary, right boundary and leaf hote hai.
Please see definition of left boundary and right boundary in above paragraph

Time :: O(n)
Space :: O(h)

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

void inroder(struct node *root, vector<int>& leaf_boundary) {
	
	if(root == NULL) {
		return;
	}
	
	if(root->left == NULL and root->right == NULL) {
		leaf_boundary.push_back(root->data);
		return;
	}
	
	inroder(root->left, leaf_boundary);
	inroder(root->right, leaf_boundary);
}

void boundary_traversal(struct node *root) {
	
	vector<int> left_boundary;
	// left boundary except leaf nodes.
	struct node *temp = root;
	
	while(true) {
		left_boundary.push_back(temp->data);
		
		if(temp->left != NULL) {
			temp = temp->left;
		} else if(temp->right != NULL) {
			temp = temp->right;
		} else {
			left_boundary.pop_back();
			break;
			
		}
	}
	
	vector<int> right_boundary;
	temp = root;
	
	temp = temp->right; //because we do not want to include root here
	while(true) {
		if(temp == NULL) {
			break;
		}
		
		right_boundary.push_back(temp->data);
		
		if(temp->right != NULL) {
			temp = temp->right;
		} else if(temp->left != NULL) {
			temp = temp->left;
		} else {
			right_boundary.pop_back();
			break;
		}
	}
	reverse(right_boundary.begin(), right_boundary.end());
	
	vector<int> leaf_boundary;
	temp = root;
	// to get leaves from left to right use inroder traversal.
	
	inroder(root, leaf_boundary);
	
	for(int x:left_boundary) {
		cout << x << " ";
	}
	for(int x:leaf_boundary) {
		cout << x << " ";
	}
	for(int x:right_boundary) {
		cout << x << " ";
	}
	cout << '\n';
}


int main() {
    
    struct node *root1 = tree1();
    struct node *root2 = tree2();
    struct node *root3 = tree3();
    struct node *root4 = tree4();
    struct node *root5 = tree5();
    
    boundary_traversal(root1);
    boundary_traversal(root2);
    boundary_traversal(root3);
    boundary_traversal(root4);
    boundary_traversal(root5);
   
   
    return 0;
}
