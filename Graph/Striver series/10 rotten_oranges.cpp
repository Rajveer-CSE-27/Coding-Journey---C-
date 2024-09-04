// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=yf3oUhkvqA0&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=10
https://www.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges

Jab bhi ek saath multiple cheeze update karne ka kuch sawal me dikhe vo bhi level wise,
to BFS socho.

Here BFS.
                          
**/

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                }
            }
        }
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        int dirx[4] = {0,0,1,-1};
        int diry[4] = {1,-1,0,0};
        
        while(!q.empty()) {
            
            pair<pair<int,int>,int> pr = q.front();
            q.pop();
            
            int i = pr.first.first, j = pr.first.second, t = pr.second;
            
            for(int k=0; k<4; k++) {
                int x = i + dirx[k], y = j + diry[k];
                
                if(x < n and y < m and x >=0 and y >=0 and grid[x][y] == 1 and dist[x][y] > t + 1) {
                    dist[x][y] = t + 1;
                    q.push({{x,y}, t+1});
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 and dist[i][j] == INT_MAX) {
                    return -1;
                } else if(grid[i][j] == 1) {
                    ans = max(ans, dist[i][j]);
                }
            }
        }
        return ans;
        
    }
};


int main() {
       
    return 0;
}
