// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**
https://www.youtube.com/watch?v=LdOnanfc5TM&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=33
https://www.youtube.com/watch?v=Xu8jjJnwvxE&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=34

Video dekh lo best explained hai.

Imp points :: 
    Residual edge ki capacity 0 hogi and uska flow value <=0 ho sakta hai. {but capacity - flow will always >= 0}
    Residual graph is that which contains both original(forward edges) and residual (backward edges).
    
    A path can contain both forward and backward edges.
    
    Jab bhi tum ek path ko augment karoge, 
            -> to uss path ke saare edges ka flow ek min value se increase karoge and uss path ke jitne bhi complimentary edges hai uske flow ko tum usi value se decrease karoge.
            -> i.e path me 2 forward and 1 backward edge hai to unki value ko increase karogi and uske equivalent 2 backward and 1 forward edge ki value(flow) ko tum decrease karoge by same amount.
    
    Max flow :: 
        Sum of the bottlenecks found in each augmenting path is equal to the max-flow.
        Bottlenecks i.e jo min value tumne find ki hai har step me vo hai bottlneck value.
        
        Explaination :: 
            Bottleneck value at each step will represent max flow on that path. 
            Hence sum of all values will represent max flow in graph.
        
    See video for explaination
    
Time complexity :: 
    It depends on algorithm that we use to find augmented path each time.
    If we use DFS then time complexity :: O(F*E)
    Where F is the max-flow value of graph.
    
    This is becuase in worst case, everytime bottlneck value could come = 1 and we would keep on adding it and removing the path with that bottleneck value.
    See video for example.
    Hence total time we run algo is O(F) and each time time complexity O(E) for DFS.
    Hence O(FE).
    
    With BFS :: time complexity :: O(V * E * E).

Will learn much faster ways later.
	
**/

/*
    Algorithms: Ford Fulkerson + (DFS / BFS)
    Description: Ford Fulkerson Algorihtm implemented using DFS. Also you can use
    BFS, which will change the complexity. Both implemented so just comment line 69
    and uncomment line 70 to change algorihtms. Ford Fulkerson is used to find Max 
    Flow or Min Cut. 
    For the sake of simplicity I used 2D array to represent the graph.
*/

#define maxN 101

bool BFS(int ways[maxN][maxN], int * parent, bool * visited, int n, int s, int t){

    queue<int> q;

    parent[s] = -1;
    q.push(s);

    while (!q.empty()) {
        
        int u = q.front();
        q.pop();
        
        for (int i = 0; i < n ; ++i) {
            if (!visited[i] && ways[u][i] > 0) {
                q.push(i);
                parent[i] = u;
                visited[i] = true;
            }
        }
    }

    return visited[t];
}

bool DFS(int rGraph[maxN][maxN], int * parent, bool * visited, int n, int x, int t){

    // cout << x << " ";
    if(x == t) return true;
    visited[x] = true;

    for(int i = 0; i < n; ++i){
        if(rGraph[x][i] > 0 && !visited[i]){
            parent[i] = x;
            if(DFS(rGraph, parent, visited, n, i, t))
                return true;
        }
    }
    return false;

}

int FordFulkerson(int graph[maxN][maxN], int n, int s, int t){

    int rGraph[maxN][maxN];
    int parent[maxN];
    bool visited[maxN];

    // Replicate the graph for residual one
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            rGraph[i][j] = graph[i][j];

    int max_flow = 0;

    while(BFS(rGraph, parent, visited, n, s, t)){ 
    // while(DFS(rGraph, parent, visited, n, s, t)){
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
    
    for(int j = 0, a, b, k; j < m; ++j){
        cin >> a >> b >> k;
        graph[a][b] = k;
    }
    int s, t;
    cin >> s >> t; // s -> starting point, t -> ending point

    cout << "Max Flow in this graph is: " << FordFulkerson(graph, n, s, t) << endl;

}
