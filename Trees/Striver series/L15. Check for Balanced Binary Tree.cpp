// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=Yt50Jfbd8Po&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=15
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

bool ans = true;

int fun(struct node *root, int h) {
	
	if(root == NULL) {
		return h;
	}
	int left = fun(root->left, h+1);
	int right = fun(root->right, h+1);
	
	if(abs(left - right) > 1) {
		ans = false;
	}
	return max(left, right);
	
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
    
    int height = fun(root, 0);
    
    (ans) ? cout << "YES" : cout << "NO";
    
    
    
    return 0;
}
