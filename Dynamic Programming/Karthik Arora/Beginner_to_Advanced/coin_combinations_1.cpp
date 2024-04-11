#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem link :: https://cses.fi/problemset/task/1635/

Approach :: 
        the value of x was in range [1, 1e6]. Hence we could construct an array of size 1e6. Therefore we could solve this using DP.
        For any value i we observe that number of ways = 
            f(i) = f(i - c1) + f(i - c2) + ... + f(i - cn).
            
        Edge case is that if we have i == cj then we increment f(i) by 1. Because we have a coin of same value.

Time Complexity :: O(x * n)
Space Complexity :: O(x + n).

**/

int main() {
    
    int n, x;
    cin >> n >> x;
    int mod = 1e9 + 7;

    vector<int> coins(n);
    
    for(int i=0; i<n; i++) {
        cin >> coins[i];
    }
        
    vector<int> dp(x+1, 0);
    dp[0] = 1; // for edge case
    
    for(int i=1; i<=x; i++) {
        for(int j=0; j<n; j++) {
            if(i - coins[j] >= 0) {
                dp[i] += dp[i - coins[j]];
                dp[i] %= mod;
            }
        }
        
    }
    
    cout << dp[x];
    
    return 0;
}
