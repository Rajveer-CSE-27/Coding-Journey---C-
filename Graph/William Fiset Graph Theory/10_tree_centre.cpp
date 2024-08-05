// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=nzF_9bjDzdc&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=11
https://leetcode.com/problems/minimum-height-trees/

Centre of the tree :: 
	It is/are node/nodes from which the distance of the farthest node is minimum.
	In other words if we root the tree at the centre then height of the tree will be minimum among all nodes on which we will root the tree.
	
	We can observe that there can be either 1 or 2 tree centres.
	For a node to be centre we can conclude ::
			If everytime we go on removing the leaf nodes (nodes with degree 1) from tree then at last we would be left with tree centre(s).
	
	Hence go on removing the leaf nodes till tree is empty and the last set of nodes that you remove will be tree centre(s).

 Another approach is to take the centre nodes on the longest path possible in the tree. The nodes lying at centre will always be centroids.
 This would use diameter of the tree property.

Time :: O(n)
Space :: O(n)

**/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        // need to find the centre of the tree
        vector<vector<int>> tree(n);
        for(int i=0; i<edges.size(); i++) {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> degree(n);
        vector<int> ans;
        vector<int> leaf;
        vector<bool> vis(n,false);

        for(int i=0; i<n; i++) {
            degree[i] = tree[i].size();
            if(degree[i] == 0) { // tree with only 1 node, edge case
                ans.push_back(i);
                return ans;
            } else if(degree[i] == 1) {
                leaf.push_back(i);
                vis[i] = true;
            }
        }

        while(true) {
            vector<int> leaf2; // for filling new leaf nodes.

            for(int l:leaf) {
                vector<int> temp = tree[l];
                for(int adj:temp) {
                    if(vis[adj] == false) {
                        degree[adj]--;
                        if(degree[adj] == 1) {// hence this is a new leaf node
                            leaf2.push_back(adj);
                            vis[adj] = true;
                        }
                    }
                }
            }
            if(leaf2.size() == 0) { // no more nodes in tree to visit
                break;
            }
            leaf = leaf2;
        }
        return leaf;


    }
};


int main() {
	
	return 0;
}
