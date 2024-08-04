//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  // https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> ans;
    
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        graph.resize(N);
        visited.resize(N, false);
        ans.resize(N,-1);
        
        for(int i=0; i<M; i++) {
            int n1 = edges[i][0], n2 = edges[i][1];
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
        
        queue<int> q;
        q.push(src);
        int level = 0;
        visited[src] = true;
        
        while(!q.empty()) {
            int m = q.size();
            while(m--) {
                int node = q.front();
                q.pop();
                ans[node] = level;
                
                for(int adj:graph[node]) {
                    if(visited[adj] == false) {
                        visited[adj] = true; // jaise hi queue me push karte ho tabhi hi visited mark kardo warna badme karoge to error aegi due to self loops.
                        q.push(adj);
                    }
                }
            }
            
            level++;
        }
        
        return ans;
        
    }
};


// //{ Driver Code Starts.
// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, m; cin >> n >> m;
//         vector<vector<int>> edges;

//         for (int i = 0; i < m; ++i) {
//             vector<int> temp;
//             for(int j=0; j<2; ++j){
//                 int x; cin>>x;
//                 temp.push_back(x);
//             }
//             edges.push_back(temp);
//         }

//         int src; cin >> src;

//         Solution obj;

//         vector<int> res = obj.shortestPath(edges, n, m, src);

//         for (auto x : res){
//             cout<<x<<" ";
//         }
//         cout << "\n";
//     }
// }

// // } Driver Code Ends
