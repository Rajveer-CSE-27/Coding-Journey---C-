// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**
Check whether a graph is bipartite.
https://cp-algorithms.com/graph/bipartite-check.html
https://www.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
https://codeforces.com/contest/1144/problem/F

Time :: O(V + E)
space :: O(V)
**/

vector<vector<int>> graph;

int main() {
    
    int n,m;
    cin >> n >> m;
    graph.resize(n+1);
        
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> side(n+1, -1);
    bool bipartite = true;
    queue<int> q;
    
    for(int i=1; i<=n; i++) { // this loop is to handle presence of multiple components
        if(side[i] == -1) {
            side[i] = 0; // start with assigning the first node to side 0
            q.push(i);
            
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                
                for(int adj:graph[node]) {
                    if(side[adj] == -1) {
                        side[adj] = side[node]^1;
                        q.push(adj);
                    } else { 
                        
                        bipartite &= (side[adj] != side[node]);
                        
                    }
                }
            }
        }
    }
    
    
    cout << bipartite;
    
       
    return 0;
}
