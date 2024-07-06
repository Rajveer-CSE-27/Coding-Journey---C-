// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=ySp2epYvgTE&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=13

Iterative all traversal of binary tree :: Without recursion 

With tree in the form of structure.

Appraoach :: 
		-> algo ::
				take stack<pair<int,int>> st;
				a stack element {x,y} :: x = value of current node, iteration of current node.
				
				for any stack top {x,y} ::
						if(y == 1) {
							pop()
							insert it in the preorder list.
							push(x,y+1)
							if left of x exist then push {x->left, 1}
						} else if(y == 2) {
							pop()
							insert it in the inorder list.
							push(x,y+1)
							if right of x exist then push {x->right,1}
						} else {
							pop()
							insert it in the postorder list.
						}

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

void allTraversals(struct node *root) {
	
	stack<pair<struct node*, int>> st;
	st.push({root,1});
	
	vector<int> preorder, inorder, postorder;
	
	while(!st.empty()) {
		pair<struct node*, int> temp = st.top();
		st.pop();
		
		if(temp.second == 1) {
			preorder.push_back(temp.first->data);
			st.push({temp.first, 2});
			if(temp.first->left != NULL) {
				st.push({temp.first->left, 1});
			}
			
		} else if(temp.second == 2) {
			inorder.push_back(temp.first->data);
			st.push({temp.first, 3});
			if(temp.first->right != NULL) {
				st.push({temp.first->right, 1});
			}
			
			
		} else {
			postorder.push_back(temp.first->data);
		}
	}
	
	cout << "Preorder :: ";
	for(auto it:preorder) {
		cout << it << " ";
	}
	cout << "\nInorder :: ";
	for(auto it:inorder) {
		cout << it << " ";
	}
	cout << "\nPostorder :: ";
	for(auto it:postorder) {
		cout << it << " ";
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
    
    allTraversals(root);
    
    return 0;
}
