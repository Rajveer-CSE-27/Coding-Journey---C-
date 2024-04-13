#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem link :: https://cses.fi/problemset/task/1637/

Approach :: For a value x :: try subtracting each digit and check for remaining value of x. Use dp.
**/

int main() {
    
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    
    dp[0] = 0;
    for(int i=1; i<min(10,n+1) /** if n < 10**/; i++) {
        dp[i] = 1;
    }
    
    for(int i=10; i<=n; i++) {
        int x = i;
        int ans = INT_MAX;
        
        while(x > 0) {
            int val = x%10;
            if(dp[i - val] != -1 /** if we subtract from 0 s**/) {
                ans = min(ans, 1 + dp[i - val]);
            }
            x /= 10;
        }
        dp[i] = ans;
    }
    cout << dp[n];
     
    return 0;
}
