// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=-YbXySKJsX8&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=36

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

Use BFS.

    To serialize :: 
        For string :: use '.' character to distinguish between starting and ending of 2 different values.
        use '#' if the node is NULL

        use to_string() to convert int to string. {it also handles negative values}.
    
    To deserialize ::
        use BFS again.
        Handle negative values and also '#'.
        

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if(root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();

            while(n--) {
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp == NULL) {
                    ans += "#";
                } else {
                    string x = to_string(temp->val);
                    ans += x;
                    q.push(temp->left);
                    q.push(temp->right);
                }

                ans += ".";
            }
        }
        return ans;


    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s = data;
        int n = s.length();
        if(s.length() == 0) {
            return NULL;
        }

        int i = 0;
        int x = 0;
        bool checkNeg = false;
        while(i < n and ((s[i] >= '0' and s[i] <= '9') or (s[i] == '-'))) {
            if(s[i] == '-') {
                checkNeg = true;
                i++;
                continue;
            }
            x *= 10;
            x += (s[i] - '0');
            i++;
        }
        if(checkNeg) {
            x *= -1;
        }
        TreeNode* root = new TreeNode(x);
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int m = q.size();

            while(m--) {
                TreeNode* temp = q.front();
                q.pop();
                i++;
                if(i<n and s[i] == '.') {
                    i++;
                }
                bool flag = false;
                bool neg = false;
                x = 0;
                while(i < n and ((s[i] >= '0' and s[i] <= '9') or (s[i] == '-'))) {
                    if(s[i] == '-') {
                        neg = true;
                        i++;
                        continue;
                    }
                    flag = true;
                    x *= 10;
                    x += (s[i] - '0');
                    i++;
                }
                if(flag) {
                    if(neg == true) {
                        x *= -1;
                    }
                    TreeNode* l = new TreeNode(x);
                    temp->left = l;
                    q.push(l);
                }

                flag = false;
                neg = false;
                x = 0;
                i++;
                if(i<n and s[i] == '.') {
                    i++;
                }
                while(i < n and ((s[i] >= '0' and s[i] <= '9') or (s[i] == '-'))) {
                    if(s[i] == '-') {
                        neg = true;
                        i++;
                        continue;
                    }
                    flag = true;
                    x *= 10;
                    x += (s[i] - '0');
                    i++;
                }
                if(flag) {
                    if(neg == true) {
                        x *= -1;
                    }
                    TreeNode* r = new TreeNode(x);
                    temp->right = r;
                    q.push(r);
                }
            }
        }
        return root;
    }
};
