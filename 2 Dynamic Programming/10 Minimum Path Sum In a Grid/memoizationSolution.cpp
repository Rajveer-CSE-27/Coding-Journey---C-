/**
Problem Statement : We are given an “N*M” matrix of integers.
                    We need to find a path from the top-left corner to the bottom-right corner of the matrix, 
                    such that there is a minimum cost past that we select.
                    At every cell, we can move in only two directions: right and bottom. 
                    The cost of a path is given as the sum of values of cells of the given matrix.
We need to count the total number of unique paths from the top-left corner of the maze to the bottom-right corner. 
At every cell, we can move either down or towards the right.
                    
Approach : Use memoization over recursion because this problem contains overllaping subproblems.

Time Complexity = O(m*n) because each cell is only edited once.
Space Complexity = O(m+n) auxillary stack space + O(m*n) dp space.
**/

#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dp) {
    
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    
    if(x == 0 and y == 0) {
        return dp[x][y] = grid[x][y];
    }
    if(x == 0) {
        return dp[x][y] = grid[x][y] + minPathSum(grid,x,y-1,dp);
    }
    if(y == 0) {
        return dp[x][y] = grid[x][y] + minPathSum(grid,x-1,y,dp);
    }
    
    return dp[x][y] = grid[x][y] + min(minPathSum(grid,x-1,y,dp),minPathSum(grid,x,y-1,dp));
}

int main() {
    
    int m,n;
    cin >> m >> n;
    
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<int>> dp(m,vector<int>(n,-1));
    
    int ans = minPathSum(grid, m-1, n-1, dp);
    cout << ans;
    return 0;
}
