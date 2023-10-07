/**
Problem Statement : We are given an “N*M” matrix of integers.
                    We need to find a path from the top-left corner to the bottom-right corner of the matrix, 
                    such that there is a minimum cost past that we select.
                    At every cell, we can move in only two directions: right and bottom. 
                    The cost of a path is given as the sum of values of cells of the given matrix.
We need to count the total number of unique paths from the top-left corner of the maze to the bottom-right corner. 
At every cell, we can move either down or towards the right.
                    
Approach : Use tabulation over memoization to save the space.

Time Complexity = O(m*n) because each cell is only edited once.
Space Complexity = O(m*n) dp space.
**/

#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dp) {
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
    
    vector<vector<int>> dp(m,vector<int>(n));
    dp[0][0] = grid[0][0];
    
    for(int i=1; i<m; i++) {
        dp[i][0] = grid[i][0] + dp[i-1][0]; 
    }
    
    for(int j=1; j<n; j++) {
        dp[0][j] = grid[0][j] + dp[0][j-1];
    }
    
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    cout << dp[m-1][n-1];
    
    return 0;
}
