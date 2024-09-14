// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://leetcode.com/problems/critical-connections-in-a-network/
https://www.youtube.com/watch?v=qrAub5z8FeA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=55

Approach is like Tarjan's algorithm.
Bridges are the edges whose removal will disconnect a graph

Must see video.

Approach :: 
    Keep 2 arrays : firstTime, lowestTime
    firstTime will store the time when we visited a node for the first time.
    lowestTime will store the lowest time needed to visit the node.
    
    On each dfs call increment the timer as we are visiting a new node on each DFS call.
    
    When visiting a node for first time, make firstTime[i] = lowestTime[i] = t;
    Now visit all it's adjacent nodes which are unvisited.
    
    On returning from all adjacent nodes call, it is time to update the lowestTime for current node.
    Visit to all adjacent node EXCEPT parent, and if lowestTime[adj] < lowestTime[node] then make lowestTime[node] = lowestTime[adj]
    
    After that we need to check the possible bridge from current node to it's adjacent nodes except parent.
    ******* if firstTime of currentnode >= lowestTime of adj node then adj node has another path till currentNode and this is not a bridge
        // if < then it is a bridge as we can just reach the adjacent node from this edge only.
        
    Hence we will find all bridges
        
**/

int t = 0; // timer

void dfs(int node, vector<bool>& vis, vector<int>& firstTime, vector<int>& lowestTime, vector<vector<int>>& graph, int parent, vector<pair<int,int>>& bridges) {
    // increment timer on each DFS call, so that time to visit a node is unique
    t++;
    vis[node] = true;
    // visiting for first time, hence
    firstTime[node] = t;
    lowestTime[node] = t;
    
    // dfs to all adjacent nodes
    for(int adj:graph[node]) {
        if(vis[adj] == false) {
            dfs(adj, vis, firstTime, lowestTime, graph, node, bridges);
        }
    }
    
    // updating the lowest of current node, by looking at lowest of all nodes except parent
    for(int adj:graph[node]) {
        if(adj != parent) {
            if(lowestTime[adj] < lowestTime[node]) {
                lowestTime[node] = lowestTime[adj];
            }
        }
    }
    
    // checking for possible bridge from current node to adj node, except parent
    
    for(int adj:graph[node]) {
        if(adj != parent) {
            if(firstTime[node] < lowestTime[adj]) {
                bridges.push_back({node, adj});
            }
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
    vector<int> firstTime(n), lowestTime(n);
    
    vector<pair<int,int>> bridges;
    
    for(int i=0; i<n; i++) {
        if(vis[i] == false) { // new component
            dfs(i, vis, firstTime, lowestTime, graph, -1, bridges);
        }
    }
    
    cout << bridges.size() << '\n';
    for(auto it:bridges) {
        cout << it.first << " " << it.second << '\n';
    }
   
    return 0;
}
