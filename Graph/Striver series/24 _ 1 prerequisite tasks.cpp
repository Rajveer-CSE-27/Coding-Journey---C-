// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks
https://www.youtube.com/watch?v=WAOfKpxYHR8&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=24

Topological sort
**/

class Solution {
public:
    bool isPossible(int N,int P, vector<pair<int, int>>& prerequisites) {
        // Topological sort
        
        vector<int> indegree(N, 0);
        vector<vector<int>> graph(N); 
        for(int i=0; i<P; i++) {
            indegree[prerequisites[i].first]++;
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        queue<int> q;
        for(int i=0; i<N; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            
            for(int next:graph[node]) {
                indegree[next]--;
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return (cnt == N);
    }
};



int main() {
    
    
    return 0;
}
