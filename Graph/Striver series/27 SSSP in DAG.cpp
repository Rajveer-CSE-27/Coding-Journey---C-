// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph

DAG me single source se shortest path nikalna hai.
Do with BFS from source.
No cycles as graph is DAG. Keep an array to store min distances to all vertices.

**/

class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int> dist(N, -1);
        vector<vector<pair<int,int>>> graph(N);
        for(int i=0; i<M; i++) {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty()) { // BFS
            pair<int,int> node = q.front();
            q.pop();
            
            int len = node.second, n = node.first;
            
            if(dist[n] == -1) {
                dist[n] = len;
            } else {
                dist[n] = min(dist[n], len);
            }
            
            for(pair<int,int> next:graph[n]) {
                
                if(dist[next.first] == -1) { // to save some time we only push when we see that distance by this path is less
                    q.push({next.first, next.second + len});
                } else if(dist[next.first] > next.second + len){
                    q.push({next.first, next.second + len});
                }
            }
        }
        
        return dist;
        
    }
};


int main() {
    
    
    return 0;
}
