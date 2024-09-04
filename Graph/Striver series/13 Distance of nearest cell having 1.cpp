// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=edXdVwkYHF8&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=13
https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1

BFS kyuki level wise aage badh rahe hai.
Note that non - diagonal travel me 1 increment hoga
and diagonal travel me 2 increment hoga.

**/

class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int>,int>> q;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({{i,j},0});
                }
            }
        }
        
        int dirx[4] = {0,0,1,-1};
        int diry[4] = {1,-1,0,0};
        int dirx2[4] = {1,1,-1,-1};
        int diry2[4] = {1,-1,1,-1};
        
        while(!q.empty()) {
            pair<pair<int,int>,int> pr = q.front();
            q.pop();
            int i = pr.first.first, j = pr.first.second, d = pr.second;

            ccc
            for(int k=0; k<4; k++) {
                int x = i + dirx[k], y = j + diry[k];
                
                if(x < n and y < m and x >= 0 and y >= 0 and ans[x][y] > d+1) {
                    ans[x][y] = d+1;
                    q.push({{x,y},d+1});
                }
            }
            
            // diagonal travel me 2 increment hoga
            for(int k=0; k<4; k++) {
                int x = i + dirx2[k], y = j + diry2[k];
                
                if(x < n and y < m and x >= 0 and y >= 0 and ans[x][y] > d+2) {
                    ans[x][y] = d+2;
                    q.push({{x,y},d+2});
                }
            }
            
            
        }
        
        return ans;
    }
};


int main() {
       
    return 0;
}
