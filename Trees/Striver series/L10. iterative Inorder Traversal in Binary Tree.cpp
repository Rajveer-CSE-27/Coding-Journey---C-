// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=lxTGsVXjwvM&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=10

Iterative in order traversal of binary tree :: Without recursion 
With tree in the form of structure.
NOTE :: iska tareeka alag hai dhyan rakho

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

void inorder(struct node *root) {
	
	stack<struct node*> st;
	
	struct node *temp = root;
	
	while(true) {
		if(temp != NULL) {
			st.push(temp);
			temp = temp->left;
		} else {
			
			if(st.empty() == true) {
				break;
			}
			temp = st.top();
			st.pop();
			cout << temp->data << " ";
			temp = temp->right;
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
    
    inorder(root);
    
    return 0;
}
