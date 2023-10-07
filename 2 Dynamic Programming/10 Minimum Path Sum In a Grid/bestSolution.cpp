/**
Problem Statement : We are given an “N*M” matrix of integers.
                    We need to find a path from the top-left corner to the bottom-right corner of the matrix, 
                    such that there is a minimum cost past that we select.
                    At every cell, we can move in only two directions: right and bottom. 
                    The cost of a path is given as the sum of values of cells of the given matrix.
We need to count the total number of unique paths from the top-left corner of the maze to the bottom-right corner. 
At every cell, we can move either down or towards the right.
                    
Approach : Use more space optimization like previous problems on grid.

Time Complexity = O(m*n) because each cell is only edited once.
Space Complexity = O(n) dp space.
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int m,n;
    cin >> m >> n;
    
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<int> dp(n);
    dp[0] = grid[0][0];
    
    for(int j=1; j<n; j++) {
        dp[j] = grid[0][j] + dp[j-1];
    }
    
    for(int i=1; i<m; i++) {
        
        vector<int> tempDp(n);
        for(int j=0; j<n; j++) {
            if(j == 0) {
                tempDp[j] = grid[i][0] + dp[j];
            } else {
                tempDp[j] = grid[i][j] + min(tempDp[j-1], dp[j]);
            }
        }
        dp = tempDp;
    }
    
    cout << dp[n-1];
    
    return 0;
}
