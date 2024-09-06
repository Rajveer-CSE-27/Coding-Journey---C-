// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**
Check whether a graph is bipartite.
https://www.youtube.com/watch?v=-vu34sct1g8&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=17
https://www.youtube.com/watch?v=KG5YFfR0j8A&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=18
https://www.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

We will appraoch problem by colouring the graph.
If we can colour the whole graph with atmost 2 colors then graph is bipartite.
We will se both BFS and dfs appraoch

Time :: O(V + E)
Space :: O(V)
**/



bool isBipartite_bfs(int& n, vector<vector<int>>& graph) {
    
    vector<bool> visited(n+1, false);
    vector<bool> color(n+1);
    
    for(int i=1; i<=n; i++) {
        if(visited[i] == false) { // new component
            
            queue<int> q;
            bool flag = 0;
            q.push(i);
            color[i] = flag;
            visited[i] = true;
            
            while(!q.empty()) {
                int node = q.front();
                flag = color[node];
                
                q.pop();
                
                for(int adj:graph[node]) {
                    if(visited[adj] == false) {
                        visited[adj] = true;
                        color[adj] = flag^1;
                        q.push(adj);
                    } else {
                        
                        if(color[adj] == flag) {
                            return false;
                        }
                    }
                }  
            }
            
        }
    }
    
    return true;
}

bool dfs(int node, int col, vector<bool>& visited, vector<bool>& color, vector<vector<int>>& graph) {
    
    visited[node] = true;
    color[node] = col;
    
    bool ans = true;
    
    for(int adj:graph[node]) {
        if(visited[adj] == true) {
            if(color[adj] == col) {
                return false;
            }
        } else {
            ans &= dfs(adj,col^1,visited,color,graph);
        }
    }
    
    return ans;
}

bool isBipartite_dfs(int& n, vector<vector<int>>& graph) {
    
    vector<bool> visited(n+1, false);
    vector<bool> color(n+1);
    
    bool ans = true;
    
    for(int i=1; i<=n; i++) {
        if(visited[i] == false) { // new component
            
            ans &= dfs(i,0,visited,color,graph); 
        }
    }
    
    return ans;
    
}


int main() {
    
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    
    for(int i=0; i<m; i++) {
        int n1,n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
        // undirected graph
    }     
    
    (isBipartite_bfs(n,graph)) ? cout << "YES\n" : cout << "NO\n";
    (isBipartite_dfs(n,graph)) ? cout << "YES\n" : cout << "NO\n";
    
    
    return 0;
}
