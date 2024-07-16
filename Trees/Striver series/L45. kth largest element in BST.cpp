// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=9TJYWh0adfk&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=45
https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

Kth largest element

Approach 1 :: O(N) time approach
    -> Count number of nodes in the BST. Let = n
    -> Try to find (n - k + 1) th smallest element using inorder traversal.
    -> This will be the kth largest element.
    
    Time : O(n) + O(h)
    Space : O(h).
    
Approach 2 :: O(h) time approach.
    
    -> Apply the reverse technique of inorder : right, root, left
    -> Keep a counter and get the kth largest value.
    
    Time :: O(H)
    Space :: O(H). 

**/



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Approach1 {
public:
    
    int countNodes(TreeNode* root) {
        if(root == NULL) {return 0;}
        
        int l = countNodes(root->left);
        int r = countNodes(root->right);
        return 1 + l + r;
    }

    int cnt = 0, ans;
    
    void inorder(TreeNode* root, int& t) {
        if(root == NULL) {
            return;
        }
        
        inorder(root->left, t);
        cnt++;
        if(cnt == t) {
            ans = root->val;
            return;
        }
        inorder(root->right, t);
    }
    
    int kthLargest(TreeNode* root, int k) {
        int n = countNodes(root);
        int v = n-k+1;
        inorder(root, v);
        
        return ans;
        
    }
};

class Approach2 {
public:
    int cnt = 0, ans;

    void inorder(TreeNode* root, int& k) {
        
        if(root == NULL) {
            return;
        }
        inorder(root->right,k);
        cnt++;
        if(cnt == k) {
            ans = root->val;
            return;
        }
        inorder(root->left, k);

    }
    
    int kthLargest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};

int main() {
    return 0;
}
