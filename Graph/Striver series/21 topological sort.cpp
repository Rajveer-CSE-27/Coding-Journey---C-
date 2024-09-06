// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long


/**
Topological sort
Kahn algo
https://github.com/Rajveer-CSE-27/Coding-Journey-CPP/blob/main/Graph/William%20Fiset%20Graph%20Theory/16_topological_sort.cpp
https://www.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort

Indegree se karo
**/

class Solution
{
    public:
    //Function to return list containing vertices in Topological order. 
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        // Kahn's algorithm
        
        vector<int> indegree(V,0);
        for(int i=0; i<V; i++) {
            
            for(int j=0; j<adj[i].size(); j++) {
                indegree[adj[i][j]]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // given DAG hence no need to check visited
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(int next:adj[node]) {
                indegree[next]--;
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return ans;
        
    }
};


int main() {
    
    
    return 0;
}
