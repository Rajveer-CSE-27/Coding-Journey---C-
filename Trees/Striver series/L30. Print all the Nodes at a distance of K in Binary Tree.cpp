// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**

https://www.youtube.com/watch?v=i9ORlEy6EsI&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=30

first assign the parent to each node(using BFS). So we can travel in all directions for BFS.
Also when doing actual BFS keep track of which nodes you visited to avoid visiting them again.
Finally print all the nodes which are at distance K from target node.
Handle few edge cases.

Time : O(n)
Space :: O(n + n + n).

https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    map<TreeNode*, TreeNode*> parent;

    void bfs(TreeNode* root) {
        parent[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();

            while(n--) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL) {
                    q.push(temp->left);
                    parent[temp->left] = temp;
                }
                if(temp->right != NULL) {
                    q.push(temp->right);
                    parent[temp->right] = temp;
                }
            }
        }

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // assign parent to each node.
        bfs(root);

        queue<TreeNode*> q;
        q.push(target);
        set<TreeNode*> vis;
        
        vector<int> ans;
        ans.push_back(target->val);
        if(k == 0) {
            return ans;
        }

        while((!q.empty())) {
            
            int n = q.size();
            vector<int> tempAns;
            while(n--) {
                TreeNode* temp = q.front();
                q.pop();

                vis.insert(temp);
                if(temp->left != NULL and vis.find(temp->left) == vis.end()) {
                    q.push(temp->left);
                    tempAns.push_back(temp->left->val);
                }
                if(temp->right != NULL and vis.find(temp->right) == vis.end()) {
                    q.push(temp->right);
                    tempAns.push_back(temp->right->val);
                }
                if(parent[temp] != NULL and vis.find(parent[temp]) == vis.end()) {
                    q.push(parent[temp]);
                    tempAns.push_back(parent[temp]->val);
                }
            }
            ans = tempAns;

            k--;
            if(k == 0) {
                return ans;
            }
        }

        vector<int> temp;
        return temp;
    }
};
