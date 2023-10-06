/**
Problem Statement : Given two values M and N, which represent a matrix[M][N]. 
                    We need to find the total unique paths from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).
                    At any cell we are allowed to move in only two directions:- bottom and right.
                    
Approach : We will save more space because at each iteration we just need previous row and not the whole matrix.

Time Complexity = O(m*n) because for each cell we will be exploring only once.
Space Complexity = O(n) : dp space.
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int m,n;
    cin >> m >> n;
    
    vector<int> dp(n,1);
    
    
    for(int i=1; i<m; i++) {
        vector<int> temp(n, 0);
        
        for(int j=0; j<n; j++) {
            if(j == 0) {
                temp[j] = 1;
            } else {
                temp[j] = temp[j-1] + dp[j];
            }
        }
        dp = temp;
    }
    
    int ans = dp[n-1];
    
    cout << ans;
    return 0;
}
