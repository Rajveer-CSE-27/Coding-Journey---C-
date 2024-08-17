// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://www.youtube.com/watch?v=1ewLrXUz4kk&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=40

Capacity scaling algorithm for max flow in network.
This is a slight upgrade of Ford-fulkerson algorithm with DFS.

Capacity scaling is the idea that we should prioritize taking edges with larger capacities to avoid ending up
with a path that has a small bottleneck.

Let U = the value of the largest edge capacity in the initial flow graph.
Let D = the largest power of 2 less than or equal to U.

The capacity scaling heuristic says that you should only take edges whose remaining capacity is ≥ D in order to
achieve a better runtime. Every edge in the selected path must have capacity >= D

If no such path exists then D = D/2.

Continue doing this till D > 0.

Time complexity of capacity scaling with DFS = O(E * E * log(U)).
**/

#define maxN 101


bool DFS(int rGraph[maxN][maxN], int * parent, bool * visited, int n, int x, int t, int D){


    if(x == t) return true;
    visited[x] = true;

    for(int i = 0; i < n; ++i){
        if(rGraph[x][i] >= D && !visited[i]){
            parent[i] = x;
            if(DFS(rGraph, parent, visited, n, i, t, D))
                return true;
        }
    }
    return false;

}

int CapacityScaling(int graph[maxN][maxN], int n, int s, int t, int D){

    int rGraph[maxN][maxN];
    int parent[maxN];
    bool visited[maxN];

    // Replicate the graph for residual one
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            rGraph[i][j] = graph[i][j];

    int max_flow = 0;

    
    while(D > 0){ 
        
        if(DFS(rGraph, parent, visited, n, s, t, D) == false) {
            D /= 2;
            continue;
        }
        memset(visited, false, sizeof(visited));
        int path_flow = 0xfffffff; // Current flow to add on the max flow later

        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main (){
    
    int n, m;
    int graph[maxN][maxN];

    cin >> n >> m; // n: nodes, m: edges
    
    int U = 0;
    
    for(int j = 0, a, b, k; j < m; ++j){
        cin >> a >> b >> k;
        graph[a][b] = k;
        U = max(U,k);
    }
    int s, t;
    cin >> s >> t; // s -> starting point, t -> ending point
    
    int v = floor(log2(U));
    int D = (1<<v);

    cout << "Max Flow in this graph is: " << CapacityScaling(graph, n, s, t, D) << endl;

}
