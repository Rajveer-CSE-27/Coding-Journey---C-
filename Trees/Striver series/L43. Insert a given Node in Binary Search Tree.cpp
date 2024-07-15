// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=FiFiNvM29ps&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=43
https://leetcode.com/problems/insert-into-a-binary-search-tree/

Approach :: 
	Find where the target node could be. And later insert the node there.

Time :: O(height)
Space :: O(1)
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root == NULL) {
            root = new TreeNode(val);
            return root;
        }

        TreeNode* temp = root;
        TreeNode* temp1 = NULL;
        // temp1 will be parent to temp always.

        while(temp != NULL) {
            temp1 = temp;
            if(temp->val < val) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        if(temp1->val < val) {
            temp1->right = new TreeNode(val);
        } else {
            temp1->left = new TreeNode(val);
        }

        return root;

    }
};

int main() {
    return 0;
}
