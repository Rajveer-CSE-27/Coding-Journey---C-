// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
Problem Link :: https://leetcode.com/problems/minimum-path-sum/description/?envType=problem-list-v2&envId=55ac4kuc
Problem type :: Minimum (Maximum) Path to Reach a Target.
Statetment type :: Given a target find minimum (maximum) cost / path / sum to reach the target.

Approach :: Choose minimum (maximum) path among all possible paths before the current state, then add value for the current state.

Reccurence at any i,j :: dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
Just handle base cases of 1st row and 1st column.

Time :: O(n*m)
Space :: O(n*m)


**/


int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int dp[n][m];
    dp[0][0] = grid[0][0];

    for(int j=1; j<m; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    for(int i=1; i<n; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n-1][m-1];
}

int main() {
    
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }
    
    int ans = minPathSum(grid);
    cout << ans;
    
    return 0;    
}
