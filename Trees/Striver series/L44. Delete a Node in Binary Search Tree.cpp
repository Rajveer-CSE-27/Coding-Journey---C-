// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=kouxiP_H5WE&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=44
https://leetcode.com/problems/delete-node-in-a-bst/submissions/1321760514/

Handle the cases where root has key efficiently.

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp = root;
        TreeNode* temp2 = NULL;

        while(temp != NULL and temp->val != key) {
            temp2 = temp;
            if(temp->val < key) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        if(temp == NULL) {
            // value not found;
            return root;
        }
        
        if(temp->left == NULL) { // if only right child present or NO Child present.
        	
            if(temp2 == NULL) { // if root node has key
                root = temp->right;
            } else {
                if(temp2->val > temp->val) {
                    temp2->left = temp->right;
                } else {
                    temp2->right = temp->right;
                }
            }
        } else if(temp->right == NULL){ // if only Left child present
            if(temp2 == NULL) {
                root = temp->left;
            } else {
                if(temp2->val > temp->val) {
                    temp2->left = temp->left;
                } else {
                    temp2->right = temp->left;
                }
            }
        } else { // if both children present
            // take right child of temp to extreme right of LEFTSUBTREE of left child;
            TreeNode* l = temp->left;
            while(l->right != NULL) {
                l = l->right;
            }
            l->right = temp->right;
            temp->right = NULL;

            if(temp2 == NULL) {
                root = temp->left;
            } else {
                if(temp2->val > temp->val) {
                    temp2->left = temp->left;
                } else {
                    temp2->right = temp->left;
                }
            }
        }

        return root;
    }
};
int main() {
    return 0;
}
