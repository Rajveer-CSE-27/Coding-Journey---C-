// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
 
/**
https://www.youtube.com/watch?v=lD_irvBkeOk&list=PLb3g_Z8nEv1hB69JL9K7KfEyK8iQNj9nX&index=5

https://cses.fi/problemset/task/2220/
**/
 
ll dp[20][11][2][2];
 
ll solve(int n, string& s, int prev, bool tight, bool leading_0) {
    
    if(n == 0) {   
        if(leading_0 == 1) {
            return 0;
        }
        return 1;
    }
    
    if(dp[n][prev][tight][leading_0] != -1) {
        return dp[n][prev][tight][leading_0];
    }
    
    int upperbound = 9;
    
    if(tight == true) {
        int val = s[s.length() - n] - '0';
        upperbound = val;
    }
    
    ll ans = 0;
    
    if(leading_0 == 1) {
        ans += solve(n-1, s, 10, 0, 1);
    }
    
    for(int dig = 0; dig <= upperbound; dig++) {
        
        
        if(dig != prev) {
            if(dig == 0) {
                if(leading_0 != 1) {
                    ans += solve(n-1, s, dig, tight & (upperbound == dig), 0);
                }
            } else {
                ans += solve(n-1, s, dig, tight & (upperbound == dig), 0);
            }
            
        }
    }
    
    return dp[n][prev][tight][leading_0] = ans;
     
}
 
int main() {
    
    ll a,b;
    cin >> a >> b;
    
    bool flag = false;
    if(a == 0) {
        flag = true;
    } else {
        a--;
    }
    
    string A = to_string(a);
    string B = to_string(b);
    
    memset(dp, -1, sizeof(dp));
    ll ans = solve(B.length(), B, 10, 1, 1);
    
    memset(dp, -1, sizeof(dp));
    ans -= solve(A.length(), A, 10, 1, 1);
    
    if(flag == true) {
        ans++;
    }
    
    cout << ans;
    
    return 0;
}
