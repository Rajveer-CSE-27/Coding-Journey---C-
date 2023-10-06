/**
Problem Statement : Given two values M and N, which represent a matrix[M][N]. 
                    We need to find the total unique paths from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).
                    At any cell we are allowed to move in only two directions:- bottom and right.
                    
Approach : We will apply tabulation over the memoization solution to save the space.

Time Complexity = O(m*n) because for each cell we will be exploring only once.
Space Complexity = O(m*n) : dp space.
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int m,n;
    cin >> m >> n;
    
    vector<vector<int>> dp(m, vector<int>(n));
    for(int i=0; i<m; i++) {
        dp[i][0] = 1;
    }
    for(int j=0; j<n; j++) {
        dp[0][j] = 1;
    }
    
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    int ans = dp[m-1][n-1];
    
    cout << ans;
    return 0;
}
