// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=NzIGLLwZBS8&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=12

Iterative post order traversal of binary tree :: Without recursion 

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

void postorder(struct node *root) {
	
	// very tricky to understand. First go till extreme left then extreme right
	
	stack<struct node*> st;
	struct node *temp = root;
	
	while(temp != NULL or !st.empty()) {
		
		if(temp != NULL) {
			// go to extreme left
			st.push(temp);
			temp = temp->left;
		} else {
			
			struct node *temp2 = st.top()->right;
			
			if(temp2 == NULL) {
				temp2 = st.top();
				cout << temp2->data << " ";
				st.pop();
				
				while(!st.empty() and st.top()->right == temp2) {
					temp2 = st.top();
					cout << temp2->data << " ";
					st.pop();
				}
			} else {
				temp = temp2;
			}
 		
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
    
    postorder(root);
    
    return 0;
}
