// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=aZNaLrVebKQ&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=34

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

Approach :: 
    fun(l,r) :: 
        this says that build a tree whose values lie between indices [l,r] of inorder traversal.
        At each time the root will be the current element of preorder traversal. 
            Start with curr = 0 and increment each time you call function : fun for a valid l,r;
        
        divide into subtasks of left subtree and rightsubtree and solve.
        
        To get the index of current root node in inorder array, keep a map.

    Note :: each value in this tree must be unique.
    


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
    int root_index = -1;
    
    TreeNode* fun(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if(l > r) {
            return NULL;
        }

        root_index++; // incrementing the index in preorder each time we call function.

        int root_val = preorder[root_index]; // this will be the root node for a tree that needs to be formed from elements that lie in range [l,r] of inorder array
        TreeNode* root = new TreeNode(root_val);

        if(l == r) {
            return root;
        }

        TreeNode* leftChild = NULL;
        TreeNode* rightChild = NULL;

        leftChild = fun(preorder, inorder, l, inorder_index[root_val]-1); // dividing the same task for forming leftSubtree
        rightChild = fun(preorder, inorder, inorder_index[root_val]+1, r); // for forming rightSubtree
        
        root->left = leftChild;
        root->right = rightChild;
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i =0; i<n; i++) {
            inorder_index[inorder[i]] = i;
        }

        TreeNode* ans = fun(preorder, inorder, 0, n-1);
        return ans;
    }
};
