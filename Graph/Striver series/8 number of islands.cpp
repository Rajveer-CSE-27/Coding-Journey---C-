// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**

https://www.youtube.com/watch?v=muncqlKJrH0&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=8
https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands

Connected components in a grid.
Use dfs
apna dimaag mat lagao just go in all directions.

Time :: O(n*m) as you will visit each cell atmost 1 time.
Space :: O(1) as we manipulate the grid itself.
                          
**/

class Solution {
  public:
    
    int dirx[8] = {-1,1,0,0,1,1,-1,-1};
    int diry[8] = {0,0,-1,1,1,-1,1,-1};
    
    void dfs(int i, int j, vector<vector<char>>& grid, int& n, int& m) {
        
        grid[i][j] = '0';
        
        for(int k=0; k<8; k++) {
            int x = i + dirx[k], y = j + diry[k];
            
            if(x < n and y < m and x >= 0 and y >= 0 and grid[x][y] == '1') {
                dfs(x,y,grid,n,m);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
        
        return cnt;
    }
};

int main() {
       
    return 0;
}
