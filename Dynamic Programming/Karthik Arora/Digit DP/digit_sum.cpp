// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

ll dp[17][2];
ll cntDp[17][2];

ll cnt(int n, string& s, bool tight) {
    // this will count how many times the current digit will be used in whole number
    
    if(tight == 0) {
        return (pow(10, n) + 0.1);
        // using pow can sometimes result in double values so adding 0.1 helps
    }
    
    if(n == 0) {
        return 1;
    }
    
    if(cntDp[n][tight] != -1) {
        return cntDp[n][tight];
    }
    
    ll ans = 0;
    int upperbound = s[s.length() - n] - '0';
    for(int dig = 0; dig <= upperbound; dig++) {
        
        if(dig < upperbound) {
            ans += cnt(n-1, s, 0);
        } else {
            ans += cnt(n-1, s, 1);
        }
        
    }
    return cntDp[n][tight] = ans;
    
}

ll solve(int n, string& s, bool tight) {
    
    if(n == 1) {
        if(tight == 0) {
            return 45;
        } else {
            int val = s[s.length() - n] - '0';
            return (val * (val + 1))/2;
        }
    }
    
    if(dp[n][tight] != -1) {
        return dp[n][tight];
    }
    
    int upperbound = 9;
    if(tight == true) {
        upperbound = s[s.length() - n] - '0';
    }
    
    ll ans = 0;
    for(int dig = 0; dig <= upperbound; dig++) {
                
        if(dig < upperbound) {
            ans += dig*cnt(n-1, s, 0) +  solve(n-1, s, 0);
        } else {
            if(tight == true) {
                ans += dig*cnt(n-1, s, 1) +  solve(n-1, s, 1);
            } else {
                ans += dig*cnt(n-1, s, 0) + solve(n-1, s, 0);
            }
        }
    }
    return dp[n][tight] = ans;
}

int main() {
    
    
    int tc;
    cin >> tc;
    
    while(tc--) {
        ll a, b;
        cin >> a >> b;
        
        a--;
        a = max(0ll, a);
        
        string A = to_string(a);
        string B = to_string(b);
        
        memset(dp, -1, sizeof(dp));
        memset(cntDp, -1, sizeof(cntDp));
        ll ans = solve(B.length(), B, 1);
        
        memset(dp, -1, sizeof(dp));
        memset(cntDp, -1, sizeof(cntDp));
        ans -= solve(A.length(), A, 1); 
        cout << ans << '\n';
    }
    
    return 0;
}
