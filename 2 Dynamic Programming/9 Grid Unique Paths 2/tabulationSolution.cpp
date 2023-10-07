/**
Problem Statement : We are given an “N*M” Maze. The maze contains some obstacles. 
                    A cell is ‘blockage’ in the maze if its value is -1.
                    0 represents non-blockage. There is no path possible through a blocked cell.

We need to count the total number of unique paths from the top-left corner of the maze to the bottom-right corner. 
At every cell, we can move either down or towards the right.
                    
Approach : Use tabulation approach over memoization to save the space.

Time Complexity = O(m*n) because each cell is only updated once.
Space Complexity = O(m*n) dp space.
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int m,n;
    cin >> m >> n;
    
    vector<vector<int>> maze(m, vector<int>(n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> maze[i][j];
        }
    }
    vector<vector<int>> dp(m, vector<int>(n));
    
    // giving values to cells of 1st row
    bool flag = false;
    for(int i=0; i<n; i++) {
        if(flag == false) {
            if(maze[0][i] == -1) {
                dp[0][i] = 0;
                flag = true;
            } else {
                dp[0][i] = 1;
            }
        } else {
            dp[0][i] = 0;
        }
    }
    
    // giving values to cells of 1st col
    flag = false;
    for(int i=0; i<m; i++) {
        if(flag == false) {
            if(maze[i][0] == -1) {
                dp[i][0] = 0;
                flag = true;
            } else {
                dp[i][0] = 1;
            }
        } else {
            dp[i][0] = 0;
        }
    }
    
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(maze[i][j] == -1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    
    int ans = dp[m-1][n-1];
    
    cout << ans;
    return 0;
}
