/**
Problem Statement : We are given an “N*M” Maze. The maze contains some obstacles. 
                    A cell is ‘blockage’ in the maze if its value is -1.
                    0 represents non-blockage. There is no path possible through a blocked cell.

We need to count the total number of unique paths from the top-left corner of the maze to the bottom-right corner. 
At every cell, we can move either down or towards the right.
                    
Approach : Optimize space further because we need only previous row to compute current row.

Time Complexity = O(m*n) because each cell is only updated once.
Space Complexity = O(n) dp space.
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
    vector<int> dp(n);
    
    bool flag = false;
    for(int i=0; i<n; i++) {
        if(flag == false) {
            if(maze[0][i] == -1) {
                dp[i] = 0;
                flag = true;
            } else {
                dp[i] = 1;
            }
        } else {
            dp[i] = 0;
        }
    }
    
    // giving values to cells of 1st col
    flag = false;
    
    for(int i=1; i<m; i++) {
        vector<int> tempDp(n);
        
        if(flag == false) {
            if(maze[i][0] == -1) {
                tempDp[0] = 0;
                flag = false;
            } else {
                tempDp[0] = 1;
            }
        } else {
            tempDp[0] = 0;
        }
        
        for(int j=1; j<n; j++) {
            if(maze[i][j] == -1) {
                tempDp[j] = 0;
            } else {
                tempDp[j] = tempDp[j-1] + dp[j];
            }
        }
        dp = tempDp;
    }
    
    int ans = dp[n-1];
    
    cout << ans;
    return 0;
}
