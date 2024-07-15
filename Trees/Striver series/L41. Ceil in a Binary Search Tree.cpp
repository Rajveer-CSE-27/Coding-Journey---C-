// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=KSsk8AhdOZA&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=41

https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

Approach :: 
	Keep a value that represents ans;
	Initialized to -1;
	
	Now at any node :: 
		if node->val < target {
			move to rightSubtree to get larger values.
		}
		else { // this node->val could be a potential answer.
			ans = min(ans, node->val)
			move to leftSubtree to get more smaller values that could be >= tar.
		
		}
		
	Goal is to find smallest value >= target.

Time :: O(height)
Space :: O(1)
**/


struct node {
	int val;
	struct node *left;
	struct node *right;
	
	node(int x) {
		val = x;
		left = NULL;
		right = NULL;
	} 
};

int findCeil(struct node *root, int target) {
	
	struct node *temp = root;
	int ans = -1;
	
	while(temp != NULL) {
		if(temp->val < target) {
			temp = temp->right;
		} else {
			
			if(ans == -1) {
				ans = temp->val;
			} else {
				ans = min(ans, temp->val);
			}
			temp = temp->left;
		}
	}
	return ans;
}

int main() {
    return 0;
}
