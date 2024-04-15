#include <bits/stdc++.h>
using namespace std;
#define ll long long


/**
Problem link :: https://cses.fi/problemset/result/9017415/

Approach :: Iterate through the coins array.
            If we cross ith coin we will never come back. 
            At any index i there are 2 options ;: Take it or leave it.
            
            bool dp[i] = whether at any time sum = i is possible or not.
            
            See code.

**/

int N = 1e6 + 1;

int main() {
    
    vector<bool> dp(N, false);
    
    int n;
    cin >> n;
    vector<int> coins(n+1);
    for(int i=1; i<=n; i++) {
        cin >> coins[i];
    }
    
    dp[coins[1]] = true;
    
    for(int i=2; i<=n; i++) {
        
        vector<bool> dp2(N, false);
        
        for(int j=1; j<=N; j++) {
            if(dp[j] == true) {
                dp2[j] = true;
                dp2[j + coins[i]] = true;
            }
        }
        dp2[coins[i]] = true;
        dp = dp2;
    }
    
    int cnt = 0;
    for(int i=1; i<=N; i++) {
        if(dp[i] == true) {
            cnt++;
        }
    }
    
    cout << cnt << '\n';
    for(int i=1; i<=N; i++) {
        if(dp[i] == true) {
            cout << i << " ";
        }
    }
    
    return 0;
}
