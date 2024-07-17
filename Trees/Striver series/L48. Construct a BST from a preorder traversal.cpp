// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=UmJT3j26t1I&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=48
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

Approach 1 :: 
    -> You have preorder traversal.
    -> Get the inorder traversal by sorting the preoder.
    -> Now you have preoder and inorder traversal of a binary tree. Construct the binary tree from it and that. will be a. BST
    -> Time :: O(nlogn) + O(n)
    -> Space :: O(n)

Approach 2 ::
    -> Use stack to keep the parent nodes which whose values will be greater than current node.
    -> at any node if value < stack top then stacktop->left = new node.
    ->              else  pop in the stack till you get stacktop->val > current val and add current node to the right of the last poped node.
    
    -> Time :: O(n)
    -> Space :: O(n)
    
Approach 3 :: 
    -> Using limits at each node.
    -> Check for all the indices that you can put in left of current node. Here new limit will be value of current node.
    -> check for all the indeices that you can put right of current node. Here no change in limit, it will be equal to value of parent node.
    
    -> Time :: O(3*n) = O(n) in worst case we visit a node 3times.
    -> Space :: O(1)
    WATCH VIDEO FOR MORE EXPLAINATION.
        

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
class Approach2 {
public:

    void fun(TreeNode* root, stack<TreeNode*>& st, int& index, vector<int>& preorder) {
        index++;
        if(index == preorder.size()) {
            return;
        }

        int x = preorder[index];
        TreeNode* temp = new TreeNode(x);

        if(x < st.top()->val) { // then add to the left child of stack top
            st.top()->left = temp;
            st.push(temp);
            fun(temp,st,index,preorder);
        } else {
            TreeNode* temp2 = NULL;
            while(!st.empty() and st.top()->val < x) { // pop till you empty stack or get stack top > x
                temp2 = st.top();
                st.pop();
            }
            temp2->right = temp;
            st.push(temp); // only push current node at the end.
            fun(temp,st,index,preorder);
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);
        
        
        int index = 0;
        fun(root,st,index, preorder);
        return root;
    }
};


class Approach3 {
public:

    TreeNode* build(vector<int>& preorder, int& i, int limit) {
        if(i == preorder.size()) {
            return NULL;
        }
        if(preorder[i] >= limit) { // this will return to previous root.
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[i]);
        i++;//increment i
        
        root->left = build(preorder,i,root->val); // check if you can add anything to left from current i
        root->right = build(preorder,i,limit); // limit will be that of parent node. Because ultimately you are adding to left of parent node only.

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
};


int main() {
    return 0;
}
