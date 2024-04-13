#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem link :: https://cses.fi/problemset/result/9003660/

Approach :: The recurrence relation looks like :: 
                    f(i,j) = f(i+1,j) + f(i,j+1)
                    Number of paths from cell (i,j) = number of paths from (i+1,j) + from (i,j+1)
            
            For all cells where trap exist make :: f(i,j) = 0
            Handle the edge cases if trap exist at cell (1,1) or (n,n)
            Make f(n,n) = 1.
            
            Start from bottom cell. For any current cell (i,j) we would know value of f(i+1,j) and f(i,j+1) hence get the value f(i,j) and uper badho.
            
            Use dp as we are calcultating f(i,j) multiple times.
**/

int main() {
    
    int mod = 1e9 + 7;
    
    int n;
    cin >> n;
    
    char grid[n+1][n+1];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> grid[i][j];
        }
    } 
    
    int dp[n+1][n+1];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            dp[i][j] = -1;
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(grid[i][j] == '*') {
                dp[i][j] = 0;
            }
        }
    }
        
    //edge case
    if(dp[1][1] == 0 or dp[n][n] == 0) {
        cout << 0;
        return 0;
    }
    
    dp[n][n] = 1;
    
    for(int i=n; i>=1; i--) {
        for(int j=n; j>=1; j--) {
            
            if(i == n and j == n) { // we will not perform for <n,n>
                continue;
            }
            
            if(dp[i][j] != 0) {
                
                // checking for right neighbour
                ll val1 = 0;
                if(j+1 <= n) {
                    val1 = dp[i][j+1];
                }
                
                // checking for bottom neighbour
                ll val2 = 0;
                if(i+1 <= n) {
                    val2 = dp[i+1][j];
                }
                
                ll ans = (val1 + val2)%mod;
                dp[i][j] = ans;
                
            }
        }
    }
    
    cout << dp[1][1]; 
     
    return 0;
}
