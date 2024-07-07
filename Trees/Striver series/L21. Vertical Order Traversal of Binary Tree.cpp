// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=q_a6lpbKJdw&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=21
Vertical order traversal

Do BFS with keeping account its vertical distance from root.

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

void vertical_traversal(struct node *root) {
	
	queue<pair<struct node*, int>> q;
	q.push({root,0});
	map<int,vector<int>> mp;
	
	while(!q.empty()) {
		int n = q.size();
		
		while(n--) {
			pair<struct node*, int> pr = q.front();
			q.pop();
			mp[pr.second].push_back(pr.first->data);
			
			if(pr.first->left != NULL) {
				q.push({pr.first->left, pr.second - 1});
			}
			if(pr.first->right != NULL) {
				q.push({pr.first->right, pr.second + 1});
			}
		}
	}
	
	for(auto it:mp) {
		vector<int> temp = it.second;
		for(int x:temp) {
			cout << x << " ";
		}
		cout << '\n';
	}
	
	cout << '\n';
}

int main() {
    
    struct node *root1 = tree1();
    struct node *root2 = tree2();
    struct node *root3 = tree3();
    struct node *root4 = tree4();
    struct node *root5 = tree5();
    
    vertical_traversal(root1);
    vertical_traversal(root2);
    vertical_traversal(root3);
    vertical_traversal(root4);
    vertical_traversal(root5);
   
   
    return 0;
}
