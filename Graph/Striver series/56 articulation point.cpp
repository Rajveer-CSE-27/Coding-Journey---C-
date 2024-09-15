// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=64KK9K4RpKE
https://www.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=articulation-point

Articulation point or cut vertex : 
    A node is articulation point if removing the node, increases the number of components in graph.
    
    Used to find single point of failure in a network.
    MUST SEE VIDEO very good

Brute force algo :: 
    Time :: O(V * (V + E))
    Remove each node once, and then count number of components with DFS.
    If number of components increases then that node was AP.

Tarjan's algorithm :: 
    Time :: O(V + E)
    
    Conditions for an AP :: (if a node satisfies either of this condition then it is AP)
        1. If node is root of DFS tree and has atleast 2 children (subgraphs) then it is AP [see 6:30 video]
                                                {there is difference between subgraphs and actual children, see video}
            
           Proof :: Because if we remove this node, as it has no parent and > 1 subgraphs hence it will definitely break the graph into multiple components.
           
           Approach to detect AP for this condition :: 
                        -> Check if parent == -1
                        -> Keep children (subgraph) counter for each node
                        -> On calling DFS for each edge, mark the entire subgraph as visited
                        -> Call DFS on other edges only if node is not visited.
                        -> Increment children counter on each unique DFS call of unvisited nodes from current node.
                        -> If children > 1 then node is AP. 
        
        
        2. If a node is not a root of DFS tree, and if it has atleast 1 child node v, such that NO vertex in the subgraph rooted at v has a back edge to one of the ancestors of current node,
           then the current node is an AP.
           
            Proof :: Becuase if we remove this node, then the subgraph rooted at node v will be a separte component from rest of the graph as it has no backedge to any of the ancestors of current node.
            
            Approach to detect AP for this condition :: 
                        -> Check if parent != -1
                        -> For this node we just need to find that any of it's subgraphs starting from it's child has NO back edge.
                        
                        -> To detect back edge, we need to use firstTime[] and lowestTime[] approach of Tarjan's algo
                        -> firstTime[] = discovery time for a node, lowestTime[i] = l, indicates that i is has a path till a node whose lowestTime = l , and that path do not cross through parent of i in DFS call.
                        
             
                    NOTE :: edge from child to parent is NOT a back edge,
                    Because meaning of AP is that we must not reach ancestor of that node from any of it's child node.
                    
        
    SEE the run of algo [20:40] video.

**/

int t = 0; // timer to assign FirstTime

void dfs(int node, vector<bool>& vis, vector<int>& parent, vector<int>& firstTime, vector<int>& lowestTime, vector<vector<int>>& graph, vector<bool>& articulation) {
    
    t++;
    vis[node] = true;
    
    // visiting the node for the first time
    firstTime[node] = t;
    lowestTime[node] = t;
    
    int subgraphCnt = 0;
    
    for(int adj:graph[node]) {
        
        if(vis[adj] == false) {
            subgraphCnt++;
            parent[adj] = node;
            dfs(adj, vis, parent, firstTime, lowestTime, graph, articulation);
            
            // updating the lowestTime for current node based on children
            lowestTime[node] = min(lowestTime[node], lowestTime[adj]);
            
            if(parent[node] == -1 and subgraphCnt > 1) { // Condition - 1 satisfied
                articulation[node] = true;
            }
            
            if(parent[node] != -1 and (lowestTime[adj] >= firstTime[node])) { // Condition -2 satisfied i.e there exist a subgraph whose do not have a back edge, hence lowest time of child >= firstTime of current node.
                                                                                                                                        // we also keep == because the subgraph ccould have backedge to current node but it will still lead to AP as there will be no edge to ancestor
                articulation[node] = true;
                
            }
        }
        
        if(adj != parent[node]) {
            lowestTime[node] = min(lowestTime[node], firstTime[adj]);
            // firstTime[adj] could be less than that of curent node lowest agar kisi aur path se pehle hi explore ho gaya hai to. Hence consider that condition also
        }
    }
    
    
}

int main() {
   
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n); // considering 0 based undirected graph
    for(int i=0; i<m; i++) {
        int n1,n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    
    vector<bool> vis(n, false);
    vector<int> parent(n, -1);
    vector<int> firstTime(n), lowestTime(n);
    vector<bool> articulation(n, false);
    
    for(int i=0; i<n; i++) {
        if(vis[i] == false) { // new component
            
            dfs(i, vis, parent, firstTime, lowestTime, graph, articulation);
            
        }
    }
    
    // printing the AP's of graph
    for(int i=0; i<n; i++) {
        if(articulation[i] == true) {
            cout << i << " ";
        }
    }
    
    return 0;
}
