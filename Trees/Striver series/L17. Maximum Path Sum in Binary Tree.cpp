// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**

https://www.youtube.com/watch?v=WszrfSwMz58&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=17

Do not forget to return the current node value because all of its subtree value could be -ve.

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


int ans = 0;

int fun(struct node *root) {
	
	if(root->left == NULL and root->right == NULL) {
		return root->data;
	}
	
	if(root->left == NULL) {
		int temp = fun(root->right);
		temp += root->data;
		
		ans = max({ans, temp, root->data}); // also return root->data if it is maximum
		
		return temp;
	}
	if(root->right == NULL) {
		int temp = fun(root->left);
		temp += root->data;
		
		ans = max({ans, temp, root->data}); // also return root->data if it is maximum
		
		return temp;
	}
	
	int temp1 = fun(root->right);
	temp1 += root->data;
	int temp2 = fun(root->left);
	temp2 += root->data;
	
	
	int tempAns = temp1 + temp2 - root->data;
	ans = max({ans, tempAns, temp1, temp2, root->data}); // also return root->data if it is maximum
	
	return max({temp1, temp2, root->data});
	
}

int main() {
    
    // forming a tree
    
    
    struct node *root1 = tree1();
    int bestSm = fun(root1);
    cout << ans << '\n';
    
    ans = 0;
    struct node *root2 = tree2();
    bestSm = fun(root2);
    cout << ans << '\n';
    
    ans = 0;
    struct node *root3 = tree3();
    bestSm = fun(root3);
    cout << ans << '\n';
    
    ans = 0;
    struct node *root4 = tree4();
    bestSm = fun(root4);
    cout << ans << '\n';
    
    ans = 0;
    struct node *root5 = tree5();
    bestSm = fun(root5);
    cout << ans << '\n';
    
    return 0;
}
