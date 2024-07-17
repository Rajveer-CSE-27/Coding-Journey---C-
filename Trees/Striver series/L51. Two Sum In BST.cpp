// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=ssL3sHwPeb4&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=51
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/1324062024/

Approach 1 :: 
    Do any traversal. Keep a set that stores the node values.
    If at any node with value = x, the set already contains value :: k-x then return true else false.
    
    Time :: O(n)
    Space :: O(n) 
    
Approach 2 :: 
    Best approach for saving space.
    Time :: O(n)
    Space :: O(2*h).
    
    In previous problem we learned about the BST iterator and how we can get the next value of inorder traversal.
    So now keep 2 stacks.
    One containing the inorder traversal , i.e at any time it would pop out the next element of inorder traversal. i.e smallest element
    Another containing the reverse of the inorder traversal., i.e at any time it would pop out the biggest element.
    
    At the end use these 2 stacks to perform 2sum.
    Max size of any stack will be O(h) as we learned earlier.


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
    set<int> st;

    bool inorder(TreeNode* root, int& k) {
        if(root == NULL) {
            return false;
        }

        bool l = inorder(root->left,k);

        int x = root->val;
        if(st.find(k-x) != st.end()) {
            return true;
        }
        st.insert(x);

        bool r = inorder(root->right,k);
        return l or r;

    }

    bool findTarget(TreeNode* root, int k) {
        return inorder(root,k);
    }
};


class Approach2 {
public:

    stack<TreeNode*> inorder, reverseInorder;
    
    void fillStack1(TreeNode* root) { // for inorder
        TreeNode* temp = root;
        while(temp != NULL) {
            inorder.push(temp);
            temp = temp->left;
        }
    }

    bool hasNext1() { // not needed but still I coded
        return (inorder.size() > 0);
    }

    int next1() {
        TreeNode* temp = inorder.top();
        inorder.pop();
        fillStack1(temp->right);
        return temp->val;
    }

    void fillStack2(TreeNode* root) { // for reverse of inorder.
        TreeNode* temp = root;
        while(temp != NULL) {
            reverseInorder.push(temp);
            temp = temp->right;
        }
    }

    bool hasNext2() {
        return (reverseInorder.size() > 0);
    }

    int next2() {
        TreeNode* temp = reverseInorder.top();
        reverseInorder.pop();
        fillStack2(temp->left);
        return temp->val;
    }

    bool findTarget(TreeNode* root, int k) {

        // approach using BST iterator for inorder and BST iterator for reverse of inorder. 
        fillStack1(root);
        fillStack2(root);

        int l = next1(), r = next2(); // l and r will be smallest and largest element respectively

        while(l < r) {
            if(l + r == k) {
                return true;
            }
            if(l + r < k) { // need to go to right
                l = next1();
            } else { // need to go to left
                r = next2();
            }
        }
        
        return false;
    }
};
int main() {
    return 0;
}
