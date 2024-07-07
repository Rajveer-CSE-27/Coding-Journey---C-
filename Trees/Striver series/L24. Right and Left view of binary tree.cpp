// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=KV4mRzTjlAk&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=24

Left view :: bfs first element in every iteration
Right view ::  bfs first element in every iteration {take right elements first in bfs}

Time : O(n)
space : O(n)
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

void left_view(struct node *root) {
	
	queue<struct node*> q;
	q.push(root);
	
	while(!q.empty()) {
		int n = q.size();
		
		cout << q.front()->data << " ";
		
		while(n--) {
			struct node *temp = q.front();
			q.pop();
			if(temp->left != NULL) {
				q.push(temp->left);
			}
			if(temp->right != NULL) {
				q.push(temp->right);
			}
		}
	}
	cout << '\n';
}
void right_view(struct node *root) {
	
	queue<struct node*> q;
	q.push(root);
	
	while(!q.empty()) {
		int n = q.size();
		
		cout << q.front()->data << " ";
		
		while(n--) {
			struct node *temp = q.front();
			q.pop();
			
			if(temp->right != NULL) {
				q.push(temp->right);
			}
			if(temp->left != NULL) {
				q.push(temp->left);
			}
			
		}
	}
	cout << '\n';
}

int main() {
    
    struct node *root1 = tree1();
    struct node *root2 = tree2();
    struct node *root3 = tree3();
    struct node *root4 = tree4();
    struct node *root5 = tree5();
    
    cout << "LEFT VIEW\n";
    left_view(root1);
    left_view(root2);
    left_view(root3);
    left_view(root4);
    left_view(root5);
   
   	cout << "RIGHT VIEW\n";
   	right_view(root1);
   	right_view(root2);
   	right_view(root3);
   	right_view(root4);
   	right_view(root5);
   	
   
    return 0;
}
