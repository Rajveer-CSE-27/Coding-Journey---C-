/**

  https://www.youtube.com/watch?v=sWf7k1x9XR4&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=38
  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

  Swap left and right child. Then process further recursion. Later join the current left node to end of current right node to create LL.
  
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
    TreeNode* fun(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }

        // swap left and right child
        TreeNode* l = root->left;
        TreeNode* r = root->right;

        if(l == NULL and r == NULL) {
            return root;
        }

        root->left = r;
        root->right = l;

        // visit the right node
        TreeNode* rightEnd = fun(root->right); // rightmost end of right node
        // visit the left node 
        TreeNode* temp = fun(root->left); // rightmost end of left node
        TreeNode* ans = temp; // becuase we will insert left nodes at the right of right node so this will be ultimate end of linked list.
        

        if(rightEnd == NULL) {
            root->right = root->left;

        } else {
            rightEnd->right = root->left;
        }
        root->left = NULL;
        if(ans == NULL) {
            return rightEnd; // ultimate end of linked list.
        }
        return ans;

    }

    void flatten(TreeNode* root) {
        root = fun(root);
    }
};
