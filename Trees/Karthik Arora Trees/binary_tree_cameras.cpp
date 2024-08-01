/**
  https://www.youtube.com/watch?v=VBxiavZYfoA&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=11
  https://leetcode.com/problems/binary-tree-cameras/description/

  Time complexity :: O(n)
  Space :: O(n)

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

    int dp[1001][2][2];
    int n = 1;

    void mark_tree(TreeNode* root) {
        // give node values to tree
        if(root == NULL) {
            return;
        }
        root->val = n;
        n++;
        mark_tree(root->left);
        mark_tree(root->right);

    }

    int fun(TreeNode* root, int haveCamera, int parentCamera) {

        int node = root->val;
        if(dp[node][haveCamera][parentCamera] != -1) {
            return dp[node][haveCamera][parentCamera];
        }

        if(haveCamera == 1) {
            // children may or may not have camera
            int ans = 1;
            if(root->left != NULL) {
                TreeNode* temp = root->left;
                ans += min(fun(temp, 1, 1), fun(temp, 0, 1));
            }
            if(root->right != NULL) {
                TreeNode* temp = root->right;
                ans += min(fun(temp, 1, 1), fun(temp, 0, 1));
            }

            return dp[node][haveCamera][parentCamera] = ans;

        }

        if(parentCamera == 1) {
            // children may or may not have camera
            int ans = 0;
            if(root->left != NULL) {
                TreeNode* temp = root->left;
                ans += min(fun(temp, 1, 0), fun(temp, 0, 0));
            }
            if(root->right != NULL) {
                TreeNode* temp = root->right;
                ans += min(fun(temp, 1, 0), fun(temp, 0, 0));
            }
            return dp[node][haveCamera][parentCamera] = ans;
        }

        // atleast 1 child must have camera
        int ans = 0;
        if(root->left != NULL and root->right != NULL) {

            int ans1 = fun(root->left, 1, 0) + fun(root->right, 1, 0);
            int ans2 = fun(root->left, 0, 0) + fun(root->right, 1, 0);
            int ans3 = fun(root->left, 1, 0) + fun(root->right, 0, 0);
            ans = min({ans1, ans2, ans3});
        } else if(root->left != NULL) {
            int ans1 = fun(root->left, 1, 0);
            ans = ans1;
        } else if(root->right != NULL) {
            int ans1 = fun(root->right, 1, 0);
            ans = ans1;
        } else {
            ans = 100000;
            // invalid case
        }
        

        return dp[node][haveCamera][parentCamera] = ans;
    }

    int minCameraCover(TreeNode* root) {
        memset(dp, -1, sizeof(dp));
        mark_tree(root);
        n--;
        
        int ans = min(fun(root, 0, 0), fun(root, 1, 0)); // either we have camera on root or not
        if(ans == 0) {
            ans = 1;
        }

        return ans;
    }
};
