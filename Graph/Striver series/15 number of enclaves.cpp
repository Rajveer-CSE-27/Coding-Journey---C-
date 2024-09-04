// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=rxKcepXQgU4&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=15
https://www.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves

Start dfs from each boundary cell.
Mark cells that are reachable and go on converting them to 0.
At the end count number of 1 cells in grid.



**/

class Solution {
  public:
  
    int dirx[4] = {0,0,1,-1};
    int diry[4] = {1,-1,0,0};
  
    void dfs(int i, int j, int& n, int& m, vector<vector<int>> &grid) {
        
        grid[i][j] = 0;
        
        for(int k=0; k<4; k++) {
            int x = i + dirx[k], y = j + diry[k];
            
            if(x < n and y < m and x >= 0 and y >= 0 and grid[x][y] == 1) {
                dfs(x,y,n,m,grid);
            }
        }
        
    }
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        for(int j=0; j<m; j++) {
            if(grid[0][j] == 1) {
                dfs(0,j,n,m,grid);
            }
            if(grid[n-1][j] == 1) {
                dfs(n-1,j,n,m,grid);
            }
        }
        
        for(int i=0; i<n; i++) {
            if(grid[i][0] == 1) {
                dfs(i,0,n,m,grid);
            }
            if(grid[i][m-1] == 1) {
                dfs(i,m-1,n,m,grid);
            }
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};



int main() {
       
    return 0;
}
