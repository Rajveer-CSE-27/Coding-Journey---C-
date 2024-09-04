// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=zQ3zgFypzX4&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=12
https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

DFS use karo.
Different components ka dhyan rakho.
Bass in every dfs call you must not visit parent. Baaki aage  badho.
 
              
**/

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    vector<bool> vis;
    
    bool dfs(int node, vector<int> adj[], int parent) {
        
        if(vis[node] == true) {
            return true;
        }
        vis[node] = true;
        
        for(int i=0; i<adj[node].size(); i++) {
            if(adj[node][i] != parent) {
                if(dfs(adj[node][i], adj, node) == true) {
                    return true;
                }
            }
        }
        return false;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
        // returns true if cycle is present
        
        vis.resize(V, false);
        for(int i=0; i<V; i++) {
            if(vis[i] == false) {
                if(dfs(i,adj, -1) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};




int main() {
       
    return 0;
}
