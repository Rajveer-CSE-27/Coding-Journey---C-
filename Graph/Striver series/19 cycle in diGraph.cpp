// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**
Directed Graph Cycle detection
https://www.youtube.com/watch?v=9twcmtQj4DU&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=19
https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

Approach :: just check that a node is not repeated in current dfs recursion call

Do dfs
**/


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int node, vector<bool>& currentCallVis, vector<bool>& vis, vector<int> adj[]) {
        
        if(currentCallVis[node] == true) {
            return false; // cycle is present
        }
        
        if(vis[node] == true) {
            return true; // path already explored and no cycle detected
        }
        
        vis[node] = true;
        currentCallVis[node] = true;
        
        bool ans = true;
        
        for(int next:adj[node]) {
            ans &= dfs(next, currentCallVis, vis, adj);
        }
        
        currentCallVis[node] = false; // very important step. So the same node can be visited from another parent in same dfs call
        // current call se ab node ko hatana bhi zaruuri hai
        
        return ans;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++) {
            
            if(vis[i] == false) { // new component
                
                vector<bool> currentCallVis(V, false);
                if(dfs(i, currentCallVis, vis, adj) == false) {
                    return true; // returning true because cycle is present
                }
            }
            
        }
        return false;
    }
};




int main() {
    
    
    return 0;
}
