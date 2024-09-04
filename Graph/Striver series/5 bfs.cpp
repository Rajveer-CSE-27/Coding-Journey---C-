// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph
https://www.youtube.com/watch?v=-tgVpUgsQ5k&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=5

BFS me jab element add karo tabhi visited mark kardo. Warna problem aegi
Time :: O(V + E)
Space :: O(V)
                          
**/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        bool vis[V] = {false};
        queue<int> q;
        q.push(0);
        vis[0] = true;
        vector<int> ans;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int nextNode:adj[node]) {
                if(vis[nextNode] == false) {
                    q.push(nextNode);
                    vis[nextNode] = true;
                }
            }
        }
        return ans;
    }
};



int main() {
       
    return 0;
}
