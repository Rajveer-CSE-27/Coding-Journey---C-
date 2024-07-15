// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=KcNt6v_56cc&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=40
https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/1321701513/

Approach :: 
	Use recursion ::
		Let current node = curr
		if(curr->val == tar) {
			return curr;
		}
		
		if(tar < curr->val) {
			go to left;
		} else {
			go to right;
		}

Time :: O(height)
Space :: O(1) : No space used in recursion as every step we are returing and not waiting.
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) {
            return root;
        }
        if(root->val == val) {
            return root;
        }
        if(val < root->val) {
            return searchBST(root->left, val);
        }
        return searchBST(root->right, val);
    }
};


int main() {
    return 0;
}
