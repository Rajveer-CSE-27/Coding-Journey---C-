// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
https://www.youtube.com/watch?v=2yAEj-0A8bk&list=PLb3g_Z8nEv1hB69JL9K7KfEyK8iQNj9nX&index=2


**/

ll dp[20][2][2][2];

ll solve(int n, string& s, bool parity, bool leading_0, bool tight) {
    
    if(n == 0) {
        return 1;
    }
    
    if(dp[n][parity][leading_0][tight] != -1) {
        return dp[n][parity][leading_0][tight];
    }
    
    ll ans = 0;
    if(parity == 1 /** current digit needs to be odd **/) {
    
        
        if(leading_0 == 1) {
            // there will be no tight for smaller strings
            ans += solve(n-1, s, 1, 1, 0);
        }
        
        int upperbound = 9;
        if(tight == 1) {
            upperbound = s[s.length() - n] - '0';
        }
        
        for(int i=1; i<=upperbound; i+=2) {
            if(i < upperbound) {
                ans += solve(n-1, s, 0, 0, 0);
            } else {
                
                if(tight == 1) {
                    ans += solve(n-1, s, 0, 0, 1);
                } else {
                    ans += solve(n-1, s, 0, 0, 0);
                }
                
            }
        }
    } else {
        
        // no need of leading_0 because if parity is even then there is definitely someone ahead of this digit
        
        int upperbound = 9;
        if(tight == 1) {
            upperbound = s[s.length() - n] - '0';
        }
        
        for(int i=0; i<=upperbound; i+=2) {
            if(i < upperbound) {
                ans += solve(n-1, s, 1, 0, 0);
            } else {
                
                if(tight == 1) {
                    ans += solve(n-1, s, 1, 0, 1);
                } else {
                    ans += solve(n-1, s, 1, 0, 0);
                }
            }
        }
    }
    
    return dp[n][parity][leading_0][tight] = ans;
    
}

int main() {
    
    ll l, r;
    cin >> l >> r;
    
    l--;
    
    string L = to_string(l);
    string R = to_string(r);
    
    memset(dp, -1, sizeof(dp));
    
    ll ans = solve(R.length(), R, 1, 1, 1);
    
    
    // note :: har string ke liye alag dp table hoga DIGIT DP me
    memset(dp, -1, sizeof(dp));
    ans -= solve(L.length(), L, 1, 1, 1);
    
    cout << ans;
    
    return 0;
}
