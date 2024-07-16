// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=9TJYWh0adfk&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=45
https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

Approach 1 :: Using extra space 
    -> Keep a map that contains each node with number of left elements and number of right elements to it.
    -> Start from root node and val = k.
    
            -> if number of nodes in left subtree >= k then our required node is in left subtree. Go there with same value of k.
            -> if number of nodes in left subtree + 1 == k then our current node is required node.
            -> if number of nodes in left subtree + 1 < k then need to go to right subtree with k -= left subtree + 1 becuase we discarded leftsubtree +1 small nodes.
            
    At last you will get answer.
    -> Time :: O(N) + O(H)
    -> Space : O(N) for map, O(H) for recursion.
    
Approach 2 :: without using  extra space.
    -> Inorder traversal of BST gives sorted values.
    -> So keep doing inorder traversal till you find k values.
    -> And return the ans.
    
    Time :: O(H)
    Space :: O(H). 

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

class Approach1 {
public:
    map<TreeNode*,pair<int,int>> child; 

    int fun(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }
        int l = fun(root->left);
        int r = fun(root->right);

        int ans = l+r+1;
        child[root] = {l,r};
        return ans;

    }

    int kthSmallest(TreeNode* root, int k) {
        int totalNodes = fun(root);
        
        TreeNode* temp = root;

        while(true) {

            if(child[temp].first >= k) { // if number of nodes in left subtree >= k then our required node is there
                temp = temp->left;
            } else if(child[temp].first + 1 == k){
                // we found node
                return temp->val;
            } else {
                // node is in the right subtree
                k -= (child[temp].first + 1);
                temp = temp->right;
            }
        }

        return -1;

    }
};

class Approach2 {
public:
    int cnt = 0, ans;

    void inorder(TreeNode* root, int& k) {
        
        if(root == NULL) {
            return;
        }
        inorder(root->left,k);
        cnt++;
        if(cnt == k) {
            ans = root->val;
            return;
        }
        inorder(root->right, k);

    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};

int main() {
    return 0;
}
