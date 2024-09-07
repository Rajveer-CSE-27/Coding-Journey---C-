// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=9XybHVqTHcQ&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=38
https://www.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops

Socho and then BFS se ho jaega.
**/

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        
        
        // making graph
        vector<vector<pair<int,int>>> graph(n);
        for(vector<int> vc:flights) {
            graph[vc[0]].push_back({vc[1], vc[2]});
        }
        
        K += 2; // L stops hence K+1 flights from source and hence we need to run BFS iteration K+2 times as we are updating the cost in next iteration
        // Do BFS k times
        
        vector<int> cost(n, INT_MAX);
        
        queue<pair<int,int>> q;
        q.push({src,0}); // node, cost
        
        
        while(K > 0 and !q.empty()) {
            int sz = q.size();
            
            while(sz--) {
                pair<int,int> pr = q.front();
                q.pop();
                
                int node = pr.first, currCost = pr.second;
                
                if(cost[node] <= currCost) {
                    continue;
                }
                cost[node] = currCost;
                
                for(pair<int,int> next:graph[node]) {
                    q.push({next.first, next.second + currCost});
                }
            }
            K--;
        }
        
        if(cost[dst] == INT_MAX) {
            return -1;
        }
        return cost[dst];
        
    }
};


int main() {
    
    
    return 0;
}
