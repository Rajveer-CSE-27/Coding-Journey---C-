// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://www.youtube.com/watch?v=uRbJ1OF9aYM&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=20
https://www.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

Appraoch :: similar to detecting cycle in di-graph.

imp question
**/

class Solution {
  public:
  
    vector<bool> terminal;
    vector<bool> safe;
    
    bool dfs(int node, vector<bool>& currCallVis, vector<bool>& vis, vector<int> adj[]) {
        
        if(currCallVis[node] == true) {
            // there is cycle hence no node in currentCall can be safe
            return false;
        }
        
        if(vis[node] == true) {
            // path already explored, if this node safe then current Call nodes may be safe. Depends on their other childs as this child is safe.
            if(safe[node] == true) {
                return true;
            }
            return false;
        }
        
        vis[node] = true;
        currCallVis[node] = true;
        
        bool checkSafe = true;
        for(int next:adj[node]) {
            checkSafe &= dfs(next, currCallVis, vis, adj);
        }
        
        currCallVis[node] = false;
        // similar to cycle detection step
        
        if(checkSafe == true) {
            safe[node] = true;
            return true;
        }
        
        return false;
        
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        terminal.resize(V,false);
        safe.resize(V,false);
        
        for(int i=0; i<V; i++) {
            if(adj[i].size() == 0) {
                terminal[i] = true;
                safe[i] = true;
            }
        }
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++) {
            if(vis[i] == false) { // new component
                
                vector<bool> currCallVis(V, false);
                dfs(i, currCallVis, vis, adj);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<V; i++) {
            if(safe[i] == true) {
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};

int main() {
    
    
    return 0;
}
