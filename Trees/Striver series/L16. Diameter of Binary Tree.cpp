// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=Rezetez59Nk&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=16

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

int ans = 0;

int fun(struct node *root) {
	
	
	if(root == NULL) {
		return 0;
	}
	int left = fun(root->left);
	int right = fun(root->right);
	
	int diameter = left + right;
	ans = max(ans, diameter);
	
	return 1 + max(left, right);
	
}


int main() {
    
    // forming a tree
    
    
    struct node *root1 = tree1();
    int h = fun(root1);
    cout << ans << '\n';
    
    ans = 0;
    struct node *root2 = tree2();
    h = fun(root2);
    cout << ans << '\n';
    
    ans = 0;
    struct node *root3 = tree3();
    h = fun(root3);
    cout << ans << '\n';
    
    
    
    
    return 0;
}
