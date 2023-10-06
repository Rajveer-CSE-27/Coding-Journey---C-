/**
Problem Statement : Given two values M and N, which represent a matrix[M][N]. 
                    We need to find the total unique paths from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).
                    At any cell we are allowed to move in only two directions:- bottom and right.
                    
Approach : We will apply memoization over the recursion solution to save the time. Because this problem has 
           overlapping subproblems.

Time Complexity = O(m*n) because for each cell we will be exploring only once.
Space Complexity = O(m+n) : auxillary stack space + O(m*n) dp space. 
**/

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int x, int y, vector<vector<int>>& dp) {
    
    if(x == 0 or y == 0) {// base case because any element of 1st row or 1st column could be reached by only 1 path.
        return dp[x][y] = 1;
    }
    
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    
    return dp[x][y] = uniquePaths(x-1,y,dp) + uniquePaths(x,y-1,dp);
    
}


int main() {
    
    int m,n;
    cin >> m >> n;
    
    vector<vector<int>> dp(m, vector<int>(n,-1));
    
    int ans = uniquePaths(m-1,n-1, dp);
    
    cout << ans;
    return 0;
}
