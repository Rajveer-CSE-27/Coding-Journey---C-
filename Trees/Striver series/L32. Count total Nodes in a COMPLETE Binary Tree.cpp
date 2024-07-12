// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=u-yWemKGWO0&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=33

https://leetcode.com/problems/count-complete-tree-nodes/

Time Complexity ::: 
        Checking left height or right height at any point takes : O(logn)
        
        Now how many times countNodes will be called.
            Due to complete binary tree by taking multiple examples we can see that countNodes will be called atmost log(n) time.
            Because at any node if (l != r) then either its leftSubtree or its rightSubtree would be a perfect binary tree due to property of complete binary tree that starts to fill last level from left.
            Hence total time :: O((log(n))^2)
            
        Space :: O(log(n))


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

    int left_height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        return 1 + left_height(root->left);
    }
    int right_height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return 1 + right_height(root->right);
    }

    int countNodes(TreeNode* root) {
        int l = left_height(root);
        int r = right_height(root);

        if(l == r) { // becuase now the subtree with currentNode as root is a perfect binary tree and hence it has nodes = 2^(h) - 1.
            int ans = (1<<l) - 1;
            return ans;
        }


        // else count nodes from left subtree, right subtree and add 1 to return total nodes.
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans; 
    }
};
