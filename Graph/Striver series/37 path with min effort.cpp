// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=0ytpZyiZFhA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=37
https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort


Dijkstra but thoda bohot change karna hai. Min effort dekh lo kya hota hai question me.
**/


class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // think this as a graph and apply dijkstra but here we need min effor so change code accordingly
        
        // no negative cycles possible here
        int n = rows * columns;
        vector<pair<int,int>> node_cell_map(n);
        for(int i=0; i<rows; i++) {
            for(int j=0; j<columns; j++) {
                int index = i + j + i*(columns - 1);
                node_cell_map[index] = {i,j};
            }
        }
        
        // read the definition of effort
        vector<int> mineffort(n, INT_MAX);
        vector<int> parent(n, -1);
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {0, -1}});
        
        int dirx[4] = {0,0,1,-1};
        int diry[4] = {1,-1,0,0};
        
        while(!pq.empty()) {
            pair<int, pair<int,int>> pr = pq.top();
            pq.pop();
            
            int currEffort = pr.first, node = pr.second.first, par = pr.second.second;
            int maxEffortFromSource = (par == -1) ? 0 : mineffort[par];
            
            maxEffortFromSource = max(maxEffortFromSource, currEffort);
            
            if(mineffort[node] <= maxEffortFromSource) {
                continue;
            }
            mineffort[node] = maxEffortFromSource;
            parent[node] = par;
            
            int x = node_cell_map[node].first, y = node_cell_map[node].second;
            
            for(int k=0; k<4; k++) {
                int x1 = x + dirx[k], y1 = y + diry[k];
                
                if(x1 >= 0 and y1 >= 0 and x1 < rows and y1 < columns) {
                    int d = abs(heights[x][y] - heights[x1][y1]);
                    int node2 = x1 + y1 + x1*(columns - 1);
                    
                    pq.push({d, {node2, node}});
                }
            }
        }
        
        return mineffort[n-1];
    }
};


int main() {
    
    
    return 0;
}
