// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=xm_W1ub-K-w&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=42
https://www.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-bst

Approach :: 
	Keep a value that represents ans;
	Initialized to -1;
	
	Now at any node :: 
		if node->val > target {
			move to leftSubtree to get smaller values.
		}
		else { // this node->val could be a potential answer.
			ans = max(ans, node->val)
			move to rightSubtree to get more bigger values that could be <= tar.
		
		}
		
	Goal is to find greatest value <= target.

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

int findFloor(struct node *root, int target) {
	
	struct node *temp = root;
	int ans = -1;
	
	while(temp != NULL) {
		if(temp->val > target) {
			temp = temp->left;
		} else {
			
			if(ans == -1) {
				ans = temp->val;
			} else {
				ans = max(ans, temp->val);
			}
			temp = temp->right;
		}
	}
	return ans;
}

int main() {
    return 0;
}
