// || जय जय जय बजरंग बली ||

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
/**
Problem link :: https://codeforces.com/contest/1107/problem/E
Video :: // see kartik arora remove boxes video
**/

vector<ll> bestPrice;
long long dp[101][101][101];
vector<int> groups;

ll fun(int startIndex, int endIndex, int extras) {
    
    if(startIndex > endIndex) {
        return 0;
    }
    if(dp[startIndex][endIndex][extras] != -1) {
        return dp[startIndex][endIndex][extras];
    }
    
    // if we do not want to group the groups[startIndex] with any other similar group
    ll ans = bestPrice[groups[startIndex] + extras] + fun(startIndex+1, endIndex, 0);
    
    // if we want to group
    // each group can be grouped with alternating groups 
    for(int newStartGroup = startIndex+2; newStartGroup <= endIndex; newStartGroup += 2) {
        
        ll val = fun(startIndex+1, newStartGroup-1, 0) + fun(newStartGroup, endIndex, extras + groups[startIndex]);
        ans = max(val, ans);
    }
    
    return dp[startIndex][endIndex][extras] = ans;
}

void solve() {
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> vc(n+1);
    for(int i=1; i<=n; i++) {
        cin >> vc[i];
    }
    
    // bestPrice[i] = best price that we get if we want to process length = i string
    bestPrice.resize(n+1, 0);
    
    bestPrice[1] = vc[1];
    for(int len=2; len<=n; len++) {
        for(int cut=1; cut<=len; cut++) {
            bestPrice[len] = max(bestPrice[len], vc[cut] + bestPrice[len - cut]);
        }
    }
    
    memset(dp, -1, sizeof(dp));
    //dp[i][j][k] = maximum profit that can be generated from group i to group j with k extras at group i
    
    
    char prev = s[0];
    int cnt = 1;
    
    groups.clear();
    
    for(int i=1; i<n; i++) {
        if(s[i] == prev) {
            cnt++;
        } else {
            groups.push_back(cnt);
            cnt = 1;
            prev = s[i];
        }
    }
    groups.push_back(cnt);
    
    int m = groups.size();
    ll ans = fun(0, m-1, 0);
    
    cout << ans;
    
}

int main() {
    
    int tc = 1;
    //cin >> tc;
    
    while(tc--) {
        solve();
        //cout << '\n';
    }
    
    return 0;    
}
