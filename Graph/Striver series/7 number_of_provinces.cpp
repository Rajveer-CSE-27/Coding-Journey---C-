// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**

https://www.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
https://www.youtube.com/watch?v=ACzkVtewUYA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=7

Need to find number of connected components.
DFS
Time :: O(V + E)
Space :: O(V)
                          
**/

class Solution {
  public:
  
    vector<bool> vis;
    
    void dfs(int node, vector<vector<int>>& adj, int& V) {
        vis[node] = true;
        
        for(int i=0; i<V; i++) {
            if(adj[node][i] == 1 and vis[i] == false) {
                dfs(i,adj,V);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int cntComponents = 0;
        vis.resize(V, false);
        
        for(int i=0; i<V; i++) {
            if(vis[i] == false) {
                cntComponents++;
                dfs(i, adj, V);
            }
        }
        
        
        return cntComponents;
    }
};



int main() {
       
    return 0;
}
