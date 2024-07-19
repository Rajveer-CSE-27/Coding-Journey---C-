// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**

BST ka question ho to ek baar inorder zaruur socho.

https://www.youtube.com/watch?v=ZWGW7FminDM&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=52
https://leetcode.com/problems/recover-binary-search-tree/description/

Exactly 2 nodes are swapped;

Approach 1 :: 
    Get the inorder traversal of tree.
    Sort it.
    Form another tree.
    Time :: O(n) + O(nlogn) 
    Space :: O(n)
    
Approach 2 :: 
    Do not store inorder traversal explicitly.
    If exactly 2 nodes are swapped then :: 
        Inorder traversal should look like :: 
                x1,x2,x3,x4,x5,........,xn
                
                Where :: 
                    Case 1 :: There can be two i's such that xi > x(i+1). I.e if the swapped nodes are not adjacent in inorder traversal.
                    Case 2 :: There can be one i such that xi > x(i+1). I.e if the swapped nodes are adjacent in inorder traversal.
                    
            So maintain a previous Value of inorder traversal.
            At the end swap the required 2 values.
            
            Case 1 :: swap first xi and second xi+1
            Case 2 :: swap only xi and only xi+1
    
    Time :: O(n)
    space :: O(h) recursion


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

    TreeNode* firstViolation = NULL;
    TreeNode* mid = NULL;
    TreeNode* secondViolation = NULL;
    bool flag = false;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        inorder(root->left);

        if(prev == NULL) {
            prev = root;
        } else {
            if(root->val > prev->val) {
                prev = root;
            } else if(flag == false) {
                firstViolation = prev;
                mid = root;
                flag = true;
                prev = root;
            } else {
                secondViolation = root;
                return;
            }
        }

        inorder(root->right);

    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        int t1 = firstViolation->val;
        if(secondViolation == NULL) { // adjacent nodes in inorder
            int t2 = mid->val;
            firstViolation->val = t2;
            mid->val = t1;
        } else {
            int t2 = secondViolation->val;
            firstViolation->val = t2;
            secondViolation->val = t1;
        }

    }
};

int main() {
    return 0;
}
