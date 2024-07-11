// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=2r5wLmQfD6g&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=31

https://www.geeksforgeeks.org/problems/burning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=burning-tree


**/

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    map<Node*, Node*> parent;
    Node* tar = NULL;
    
    void assign_parent(Node* root, int target) {
        parent[root] = NULL;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                Node* temp = q.front();
                
                if(temp->data == target) {
                    tar = temp;
                }
                
                q.pop();
                if(temp->left != NULL) {
                    parent[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right != NULL) {
                    parent[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
    }
    
    set<Node*> vis;
    int height(Node* root) {
        
        if(root == NULL) {
            return 0;
        }
        vis.insert(root);
        
        int l = 0, r = 0, p = 0;
        if(vis.find(root->left) == vis.end()) {
            l = height(root->left);
        }
        if(vis.find(root->right) == vis.end()) {
            r = height(root->right);
        }
        if(vis.find(parent[root]) == vis.end()) {
            p = height(parent[root]);
        }
        
        int h = 1 + max({l,r,p});
        return h;
        
    }
  
    // ACTUAL FUNCTION
    int minTime(Node* root, int target) 
    {
        // Assign parent to each node. Then find the node which is farthest from target node. That is equivalent to finding height of the tree rooted at target node.
        
        assign_parent(root, target);
        int ans = height(tar);
        return ans-1; // because time to burn self is 0
        
    }
};
