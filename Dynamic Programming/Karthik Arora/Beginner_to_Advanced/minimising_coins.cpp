#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;

/**
Problem link :: https://cses.fi/problemset/task/1634/

Approach :: 
        the value of x was in range [1, 1e6]. Hence we could construct an array of size 1e6. Therefore we could solve this using DP.
        
        Let the sorted coins order be :: [c1, c2, c3, ... , cn].
        Now for any target sum(i) with minimum number of coins ::
                = min( target sum(i - c1) + 1, target sum(i - c2) + 1, ..... ,  target sum(i - cn + 1).
            
            Not to handle the case where target sum(i - cj) is not possible.
        
        Hence we apply iterative DP here.
         
**/


int main() {
    
    int n,x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for(int i=0; i<n; i++) {
        cin >> coins[i];
    }
    
    sort(coins.begin(), coins.end());
    
    int dp[x+1];
    dp[0] = 0;
    
    for(int i=1; i<=x; i++) {
        int ans = -1;
        for(int j=0; j<n; j++){
            if(i - coins[j] >= 0) {
                if(dp[i - coins[j]] == -1) {
                    // important edge case
                    continue;
                }
                int val = dp[i - coins[j]] + 1;
                if(ans == -1) {
                    ans = val;
                } else {
                    ans = min(ans,val);
                }
            } 
        }
        dp[i] = ans;
    }
    
    cout << dp[x];
    
    return 0;
}
