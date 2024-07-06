// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**

https://www.youtube.com/watch?v=3OXWEdlIGl4&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=19

Zig - zag traversal

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


void zigzag(struct node *root) {
	
	queue<struct node*> q;
	q.push(root);
	
	int xr = 1;
	while(!q.empty()) {
		vector<int> temp;
		int sz = q.size();
		
		while(sz--) {
			struct node *tempNode = q.front();
			q.pop();
			temp.push_back(tempNode->data);
			if(tempNode->left != NULL) {
				q.push(tempNode->left);
			}
			if(tempNode->right != NULL) {
				q.push(tempNode->right);
			}
		}
		
		if(xr == 0) {
			reverse(temp.begin(), temp.end());
		}
		
		for(auto it:temp) {
			cout << it << " ";
		}
		cout << '\n';
		
		xr ^= 1;
	}
}

int main() {
    
    
   struct node *root1 = tree1();
    
   zigzag(root1);
   
    return 0;
}
