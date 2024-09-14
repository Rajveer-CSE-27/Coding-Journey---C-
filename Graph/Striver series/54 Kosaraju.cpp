// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=R6uoSjZ2imo&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=54

Kosaraju for SCC

Time :: O(3*(V + E))

Must see video

In the graph we have a path like :: 
        scc1 -> scc2 -> scc3 .... -> sccn
        
        (if graph not connected then ) scc(n+1)-> scc(n+2) .... ->sccm
        
        and so on.
        
        Now if you reverse all edges in graph :: 
        scc1 <- scc2 <- scc3 .... <- sccn
        
        
        inside an scc you can go from any node to another node.
        Hence start dfs from a node.
        Keep a storage of nodes in such a way that node whose dfs end time took longest will be given priority.
        Reverse the graph i.e form transpose of graph
        
        start the DFS again with the priority.
        And whenever you encounter a not visited node in stack, that will be your scc starting point.

Must see video

        
**/

void dfs(int node, vector<vector<int>>& graph, stack<int>& st, vector<bool>& vis) {
    vis[node] = true;
    
    for(int adj:graph[node]) {
        if(vis[adj] == false) {
            dfs(adj, graph, st, vis);
        }
    }
    
    // at the end add this in stack as dfs for this node completes
    st.push(node); 
}

void dfs2(int node, vector<bool>& vis, vector<vector<int>>& transposeGraph, vector<int>& tempScc) {
    vis[node] = true;
    
    for(auto adj:transposeGraph[node]) {
        if(vis[adj] == false) {
            dfs2(adj, vis, transposeGraph, tempScc);
        }
    }
    
    
    tempScc.push_back(node);
}

void kosaraju(vector<vector<int>>& graph, int n) {
    
    // make first dfs and store the elements based on their finish time.
    // node with highest finish time will be given priority in next call
    
    vector<bool> vis(n, false);
    stack<int> st; // will store nodes with required priority order
    
    for(int i=0; i<n; i++) {
        
        if(vis[i] == false) { // new component
            dfs(i, graph, st, vis);
        }
    }
    
    // reverse all the edges of the graph
    vector<vector<int>> transposeGraph(n);
    
    for(int i=0; i<n; i++) {
        for(int adj:graph[i]) {
            transposeGraph[adj].push_back(i);
        }
    }
    
    vis.clear();
    vis.resize(n, false);
    
    vector<vector<int>> scc;
    
    // make a dfs again based on priority
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        
        if(vis[node] == false) {
            // new scc 
            vector<int> tempScc;
            dfs2(node, vis, transposeGraph, tempScc);
            scc.push_back(tempScc);
        }
    }
    
    
    for(auto it:scc) {
        for(auto it2:it) {
            cout << it2 << " ";
        }
        cout << '\n';
    }
}

int main() {
   
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n); // 0 based directed graph
    
    for(int i=0; i<m; i++) {
        int n1,n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
    }
    
    // print all scc's in the graph
    kosaraju(graph, n);
   
    return 0;
}
