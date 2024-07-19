// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=X0oXMdtUDwo&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=53
https://www.geeksforgeeks.org/problems/largest-bst/1

Approach :: 
        At each node first check whether we can build a BST from current node.
        If yes then count total nodes.
        If at a node we can form left subtree as BST and right subtree as BST  + some condition,then we can form current subtree as BST.
        This can happen by comparing biggest left element < current val and smallest right element > current val at each level.
        
        Time :: O(n)
        Space :: O(h)
**/

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    
    int ans = 0; // global variable for answer.
    
    pair<int,pair<int,int>> fun(Node* root) { // this function will return :: {number of nodes forming BST, {min element till now, max element till now}}
        
        if(root == NULL) {
            return {0,{-1,-1}};
        }
        pair<int,pair<int,int>> l = fun(root->left);
        pair<int,pair<int,int>> r = fun(root->right);
        
        if(l.first == -1 or r.first == -1) { // -1 indicates no valid BST from heere. Hence in any parent node there must be no valid BST
            return {-1,{-1,-1}}; 
        }
        
        if(l.first == 0 and r.first == 0) { // edge case 1 :: If no child
            ans = max(ans, 1);
            return {1,{root->data,root->data}};
        }
        
        if(l.first == 0) { // edge case 2 :: if no right child
            int rightMin = r.second.first;
            
            if(rightMin > root->data) {
                int nodes = r.first + 1;
                ans = max(ans, nodes);
                return {nodes,{ root->data, r.second.second}};
            } else {
                return {-1,{-1,-1}};
            }
        }
        
        
        if(r.first == 0) { // edge case 3 :: if no left child
            int leftMax = l.second.second;
            if(leftMax < root->data) {
                int nodes = l.first + 1;
                ans = max(ans, nodes);
                return {nodes,{ l.second.first, root->data}};
            } else {
                return {-1,{-1,-1}};
            }
        }
        
        int rightMin = r.second.first;
        int leftMax = l.second.second;
        
        if(rightMin > root->data and leftMax < root->data) {
            int nodes = l.first + r.first + 1;
            ans = max(ans, nodes);
            return {nodes,{ l.second.first, r.second.second}};
        }
        
        return {-1,{-1,-1}};
        
    }
    
    
    int largestBst(Node *root) {
        fun(root);
        return ans;
    }
};

int main() {
    return 0;
}
