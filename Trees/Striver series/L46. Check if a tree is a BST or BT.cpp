// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=f-sj7I5oXEI&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=46
https://leetcode.com/problems/validate-binary-search-tree/submissions/1322840247/

Approach 1 ::
    -> Do inorder traversal.
    -> If strictly sorted then BST else no
    -> Time :: O(n), space :: O(n) + O(h) recursion
    
Approach 2 ::
    -> Use recursion
    -> At each node if its value lies in valid range and its left Subtree is a BST and right subtree is a BST then the tree with current node as root is BST.
    
    -> Time :: O(n), space :: O(h)

**/



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:

    bool fun(TreeNode* root, long long lower, long long upper) { // current node val must be > lower and <upper
        if(root == NULL) {
            return true;
        }

        if(root->val <= lower) {
            return false;
        }
        if(upper != LLONG_MIN and root->val >= upper) {
            return false;
        }
        
        // take care to update lower and upper.
        return fun(root->left, lower, root->val) and fun(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        
        return fun(root,LLONG_MIN,LLONG_MIN);
    }
};

int main() {
    return 0;
}
