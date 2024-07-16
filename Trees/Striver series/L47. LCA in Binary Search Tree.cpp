// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=cX_kPV_foZc&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=47
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/1322848198/

Approach :: 
    at any node 
            ->if val > both then go left 
            -> if val < both then go right
            -> else this is the LCA.
            
    Time :: O(h)
    Space :: O(1);

**/



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int v1 = p->val, v2 = q->val;

        TreeNode* temp = root;
        while(true) {
            int v = temp->val;
            if(v > v1 and v > v2) {
                temp = temp->left; 
            } else if(v < v1 and v < v2) {
                temp = temp->right;
            } else {
                return temp;
            }
        }
        return NULL;
    }
};

int main() {
    return 0;
}
