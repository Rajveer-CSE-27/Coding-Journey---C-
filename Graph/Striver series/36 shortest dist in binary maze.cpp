// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=U5Mw4eyUmw4&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=36
https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze

Simple BFS hi hai.

**/


class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        if(grid[source.first][source.second] == 0 or grid[destination.first][destination.second] == 0) {
            return -1;
        }
        if(source.first == destination.first and source.second == destination.second) {
            return 0;
        }
        
        int dirx[4] = {0,0,-1,1};
        int diry[4] = {1,-1,0,0};
        
        int n = grid.size(), m = grid[0].size();
        
        int dist = 0;
        queue<pair<int,int>> q;
        q.push(source);
        grid[source.first][source.second] = 0;
        
        while(!q.empty()) {
            
            int sz = q.size();
            while(sz--) {
                pair<int,int> node = q.front();
                q.pop();
                
                int x = node.first, y = node.second;
                if(x == destination.first and y == destination.second) {
                    return dist;
                }
                
                for(int k=0; k<4; k++) {
                    int x1 = x + dirx[k], y1 = y + diry[k];
                    
                    if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < m and grid[x1][y1] == 1) {
                        q.push({x1,y1});
                        grid[x1][y1] = 0; // so that it cannot be pushed later
                    }
                }
            }
            
            dist++;
        }
        
        return -1;
    }
};


int main() {
    
    
    return 0;
}
