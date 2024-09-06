// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule

Topological sort
**/

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //Topological
        vector<int> indegree(n,0);
        vector<vector<int>> graph(n);
        for(int i=0; i<m; i++) {
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) {
            
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int next:graph[node]) {
                indegree[next]--;
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        if(ans.size() != n) {
            ans.clear();
        }
        return ans;
    }
};




int main() {
    
    
    return 0;
}
