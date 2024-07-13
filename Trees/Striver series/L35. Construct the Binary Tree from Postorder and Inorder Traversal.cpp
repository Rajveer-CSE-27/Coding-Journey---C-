// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=LgLRTaEMRVc&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=35
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Approach :: 
    Similar to problem (inorder + preorder) but here root_index starts from back.
    And we go to right subtree first and then leftSubtree.
    


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

    map<int,int> inorder_index;

    int root_index;
    TreeNode* fun(vector<int>& postorder, vector<int>& inorder, int l, int r) {
        if(l > r) {
            return NULL;
        }

        root_index--;
        int root_val = postorder[root_index];
        TreeNode* root = new TreeNode(root_val);

        root->right = fun(postorder, inorder, inorder_index[root_val]+1, r);
        root->left = fun(postorder, inorder, l, inorder_index[root_val]-1);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++) {
            inorder_index[inorder[i]] = i;
        }

        root_index = n;
        TreeNode* ans = fun(postorder, inorder, 0, n-1);
        return ans;
    }
};
