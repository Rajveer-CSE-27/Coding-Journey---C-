// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

/**
https://www.youtube.com/watch?v=Smem2tVQQXU&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=6

https://www.codechef.com/problems/TSHIRTS

there are 100 types of tshirt. So if we make mask for each person then it will go upto 2^100. Which is not feasible here.
Rather make mask for each tshirt. It will store set of all the persons that can wear that tshirt.

**/
int person[11][101];
long long dp[101][1025];

long long fun(int tshirt, int mask, int n) {
    
    if(mask == ((1<<n) - 1)) {
        // all the persons have selected there unique tshirts.
        return 1;
    }
    if(tshirt == 101) {
        return 0;
    }
    if(dp[tshirt][mask] != -1) {
        return dp[tshirt][mask];
    }
    
    //either we can ignore the current tshirt that is not consider it in the final set of tshirts worn by all persons.
    long long ans = fun(tshirt + 1, mask, n);
    
    //or we can consider that this tshirt is worn by a valid guy and move to next tshirt
    for(int i=1; i<=n; i++) {
        
        if(person[i][tshirt] == true and ((mask & (1<<(i-1))) == 0)) {
            // ith person can wear tshirt and it is not present in the mask
            int nextMask = (mask ^ (1<<(i-1)));
            ans = (ans + fun(tshirt + 1, nextMask, n))%mod;
        }
    }
    
    return dp[tshirt][mask] = ans;
    
}

void solve() {
    
    memset(person, false, sizeof(person));
    // person[i][j] is true if ith person is able to wear jth tshirt
    
    int n;
    cin >> n;
    // taking input
    string s;
    cin.ignore();
    
    for(int i=0; i<n; i++) {
        
        getline(cin,s);
        stringstream in(s);
        int a;
        while(in>>a) {
            person[i+1][a] = true;
        }
    }
    
    memset(dp, -1, sizeof(dp));
    // dp[i][j] will tell us number of ways such that we are at ith tshirt with current mask = j.
    // mask = j will tell us till now which of the persons have selected there tshirt
    
    int ans = fun(1, 0, n);
    cout << ans;
    
    
}


int main() {
    
    int tc;
    cin >> tc;
    
    while(tc--) {
        solve();
        cout << '\n';
    }
    return 0;
}
