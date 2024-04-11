#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;

/**
Problem link :: https://cses.fi/problemset/task/1633/

Approach :: Recurrence relation formed :: f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6)

            Just handle the edge cases from n = 1 to n = 6.
            For n = 1 to n = 6
                Recurrence relation :: f(i) = f(i-1) + f(i-2) + .. + f(1) + 1.
            
            Using iterative dp
            
Time complexity :: O(n)
Space complexity :: O(1) :: Because we only used array of size = 6
**/


int main() {
    
    int n;
    cin >> n;
    
    ll dp[7];
    
    dp[1] = 1;
    
    // edge casees.
    for(int i=2; i<=6; i++) {
        int sm = 0;
        for(int j=1; j<i; j++) {
            sm += dp[j];
        }
        dp[i] = sm + 1;
    }
    
    if(n <= 6) {
        cout << dp[n]%mod;
        return 0;
    }
    
    
    for(int i=7; i<=n; i++) {
        ll sm = 0;
        for(int j=1; j<=6; j++) {
            sm = (sm + dp[j])%mod;
        }
        for(int j=1; j<6; j++) {
            dp[j] = dp[j+1];
        }
        dp[6] = sm;
    }
    
    cout << dp[6]%mod;
    
    return 0;
}
