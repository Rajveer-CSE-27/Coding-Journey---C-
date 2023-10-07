/**
Problem Statement : We are given an “N*M” Maze. The maze contains some obstacles. 
                    A cell is ‘blockage’ in the maze if its value is -1.
                    0 represents non-blockage. There is no path possible through a blocked cell.

We need to count the total number of unique paths from the top-left corner of the maze to the bottom-right corner. 
At every cell, we can move either down or towards the right.
                    
Approach : Use memoization approach over recursion because of overlapping subproblems.

Time Complexity = O(m*n) because each cell is only updated once.
Space Complexity = O(m+n) : auxillary stack space + O(m*n) dp space.
**/

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(vector<vector<int>> maze, int x, int y, vector<vector<int>>& dp) {
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    
    if(maze[x][y] == -1) {
        return dp[x][y] = 0;
    }
    if(x == 0 or y == 0) {
        return dp[x][y] = 1;
    }
    
    return dp[x][y] = uniquePaths(maze,x-1,y,dp) + uniquePaths(maze,x,y-1,dp);
}

int main() {
    
    int m,n;
    cin >> m >> n;
    
    vector<vector<int>> maze(m, vector<int>(n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> maze[i][j];
        }
    }
    vector<vector<int>> dp(m, vector<int>(n, -1));
    
    int ans = uniquePaths(maze, m-1, n-1, dp);
    cout << ans;
    return 0;
}
