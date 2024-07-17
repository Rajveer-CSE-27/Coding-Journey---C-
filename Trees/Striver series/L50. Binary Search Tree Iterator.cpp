// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=D2jMcmxU4bs&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=50
https://leetcode.com/problems/binary-search-tree-iterator/submissions/1323968174/

see video for problem statement.

Approach :: 
    We will maintain a stack.
    If we are at currentNode then first we will push all elements from node to extreme left in stack.
    
    Whenever we call next() we will pop the top element from stack. And go to the right of the popped element and fill till extreme left starting from right of the popped element.
    
    In this way we will. have inorder traversal whenever we call next().
    This idea comes from property of inorder traversal :: Left Root Right.
    
    Time :: O(n)
    Space :: O(h)
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

class BSTIterator {
public:
    stack<TreeNode*> st;
    
    void fillStack(TreeNode* root) { // this function will fill stack from current node to its extreme left
        TreeNode* temp = root;
        while(temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
    }

    BSTIterator(TreeNode* root) {
        fillStack(root); // first fill stack from root node.
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        fillStack(temp->right); // go to right and then fill stack once we pop.
        return temp->val;
    }
    
    bool hasNext() {
        return (st.size() > 0);
    }
};


int main() {
    return 0;
}
