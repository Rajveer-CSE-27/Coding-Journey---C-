#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
  Problem link :: https://cses.fi/problemset/task/1746
  Approach :: 
  
        use matrix dp[i][j];
        dp[i][j] = number of array possible with ith position in array = j. {Note :: assume that we are starting array from ith position.}
        i will range from [1, n] and j will range from [1, m].
        
        In the array x if x[i] != 0 then :: 
                    only dp[i][x[i]] will have a value > 0 and rest all values will be = 0.
        
        Handling nth row in dp matrix.
        if x[n] != 0 then dp[n][x[n]] = 1 and rest all dp[n][j] = 0;
        Else all dp[n][j] = 1 because at the end with only 1 value only 1 array is possible.
        
        for all i = 1 to n-1 ::
            if(x[i] == 0) then calculate for all possible values of x[i] from [1,m]. Here dp[i][j] = dp[i+1][j-1] + dp[i+1][j] + dp[i+1][j+1] // because max difference between consecutive values could be 1
            Else :: only calculate for dp[i][x[i]] in the same above way. And for rest j :: dp[i][j] = 0;
            
        
        Now total arrays possible will be calculates with 1st row that is values of dp[1][j].
        Here also handle 2 cases :: if(x[1] == 0) 
                                    if(x[1] != 0).
                    
            
**/

int main() {
    
    int n,m;
    cin >> n >> m;
    vector<int> x(n+1);
    
    for(int i=1; i<=n; i++) {
        cin >> x[i];
    }
    
    int mod = 1e9 + 7;
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    // filling the last row.
    if(x[n] == 0) {
        for(int i=1; i<=m; i++) {
            dp[n][i] = 1;
        }
    } else {
        for(int i=1; i<=m; i++) {
            if(i == x[n]) {
                dp[n][i] = 1;
            } 
        }
    }
    
    for(int i=n-1; i>=1; i--) {
        
        // if there is alredy a fixed value at x[i]
        if(x[i] != 0) {
            ll v1 = 0, v2 = 0, v3 = 0;
            if(x[i]-1 >= 1) {
                v1 = dp[i+1][x[i] - 1];
            }
            
            v2 = dp[i+1][x[i]];
            
            if(x[i] + 1 <= m) {
                v3 = dp[i+1][x[i] + 1];
            }
            
            ll ans = (v1 + v2 + v3)%mod;
            dp[i][x[i]] = ans;
        } else {
            
            for(int j=1; j<=m; j++) {
                ll v1 = 0, v2 = 0, v3 = 0;
                if(j-1 >= 1) {
                    v1 = dp[i+1][j - 1];
                }
                v2 = dp[i+1][j];
                
                if(j+1 <= m) {
                    v3 = dp[i+1][j + 1];
                }
                
                ll ans = (v1 + v2 + v3)%mod;
                dp[i][j] = ans;
            }
        }
    }
    
    // edge case for 1st value fixed or not
    if(x[1] == 0) {
        ll res = 0;
        for(int j=1; j<=m; j++) {
            ll val = dp[1][j];
            res = (res + val)%mod;
        }
        cout << res;
    } else {
        cout << dp[1][x[1]];
    }
    
     
    return 0;
}
