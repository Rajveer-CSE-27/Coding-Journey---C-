// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

/**
https://www.codechef.com/problems/ENCODING?tab=statement

https://www.youtube.com/watch?v=B7ZWUBfaIq0&list=PLb3g_Z8nEv1hB69JL9K7KfEyK8iQNj9nX&index=4

**/


ll dp[N][11][2];
ll cntDp[N][2];

ll pows[100001];
bool done = 0;

int power10(int n){
    if(!done ){ // so that ye function sirf 1 baar chale life me
        pows[0] = 1;
        for(int i = 1; i <= 100000; i++)
            pows[i] = (pows[i-1] * 10LL) % mod;
        done = 1;
    }
    return pows[n];
}


ll cnt(int n, string& s, bool tight) {
    
    if(tight == 0) {
        ll ans = power10(n);
        return ans;
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
            ans = (ans + cnt(n-1, s, 0))%mod;
        } else {
            ans = (ans + cnt(n-1, s, 1))%mod;
        }
        
    }
    
    return cntDp[n][tight] = ans%mod;
}

ll solve(int n, string& s, int prev, bool tight) {
    
    // if(n == 1) {
    //     int upperbound = 9;
    //     if(tight == true) {
    //         upperbound = s[s.length() - n] - '0';
    //     }
        
    //     ll ans = 0;
        
    //     for(int dig = 0; dig <= upperbound; dig++) {
    //         if(dig != prev) {
    //             ans = (ans + dig)%mod;
    //         }
    //     }
    //     return ans;
    // }
    
    if(n == 0) {
        return 0;
    }
    if(dp[n][prev][tight] != -1) {
        return dp[n][prev][tight];
    }
    
    int upperbound = 9;
    if(tight == true) {
        upperbound = s[s.length() - n] - '0';
    }
    
    ll ans = 0;
    for(int dig = 0; dig <= upperbound; dig++) {
        
        if(dig != prev){
            ll temp = (dig * (1LL * power10(n - 1) * cnt(n - 1, s, tight & (dig == upperbound)))) % mod;
            ans = (ans + temp) % mod;
        }
        ans = (ans + solve(n-1, s, dig,  tight & (upperbound == dig)))%mod;
    }
    return dp[n][prev][tight] = ans%mod;
    
}

ll fun(string& s) {
    int n = s.length();
    
    int prev = -1;
    int pos = n-1;
    
    ll ans = 0;
    for(int i=0; i<n; i++) {
        int val = s[i] - '0';
        
        if(val != prev) {
            
            ll num = power10(pos);
            num = (num * val)%mod;
            ans = (ans + num)%mod;
            
        }
        prev = val;
        pos--;
    }
    
    return ans%mod;
    
}

int main() {
    
    int tc;
    cin >> tc;
    while(tc--) {
        
        string l, r;
        int n,m;
        cin >> n;
        cin >> l;
        cin >> m;
        cin >> r;
        
        memset(dp, -1, sizeof(dp));
        memset(cntDp, -1, sizeof(cntDp));
        ll ans = solve(r.length(), r, 10, 1);
        
        memset(dp, -1, sizeof(dp));
        memset(cntDp, -1, sizeof(cntDp));
        ans = (ans + (mod - solve(l.length(), l, 10, 1)))%mod;
        ans = (ans + fun(l))%mod;
        
        cout << ans << '\n';
        
    }
    
    return 0;
}
