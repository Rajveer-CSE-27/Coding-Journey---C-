// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
https://www.youtube.com/watch?v=RuNAYVTn9qM&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=2
https://cses.fi/problemset/task/1130

Approach :: 
    Using DP
    
    DUE to TLE we needed to use Prefix and suffix arrays.
    Time :: O(n)
    Space :: O(n);


**/

vector<vector<int>> tree;
vector<vector<int>> dp;

int fun(int node, int parent, int flag) {
    
    if(tree[node].size() == 1 and node != 1) { // leaf
        return 0;
    }
    
    if(dp[node][flag] != -1) {
        return dp[node][flag];
    }
    
    if(flag == 0) { // that is we do not want to consider the current node. Hence answers will be sum of all the matchings of its children subtrees.
        int ans = 0;
        
        for(int i=0; i<tree[node].size(); i++) {
            if(tree[node][i] != parent) {
                ans += max(fun(tree[node][i], node, 0), fun(tree[node][i], node, 1));
            }
        }
        return dp[node][flag] = ans;
    }
    
    int ans = 0;
    
    
    vector<int> prefix, suffix; // to fasten the results as we were getting TLE
    for(int j=0; j<tree[node].size(); j++) {
        if(tree[node][j] != parent) {
            prefix.push_back(max(fun(tree[node][j], node, 0), fun(tree[node][j], node, 1)));
            suffix.push_back(max(fun(tree[node][j], node, 0), fun(tree[node][j], node, 1)));
        }
    }
    
    for(int i=1; i<prefix.size(); i++) {
        prefix[i] += prefix[i-1];
    }
    for(int i=suffix.size()-2; i>=0; i--) {
        suffix[i] += suffix[i+1];
    }
    
    
    int j=0;
    for(int i=0; i<tree[node].size(); i++) {
        
        int tempAns = 0;
        
        if(tree[node][i] != parent) { // adding this edge hence we cannot take the next value. And may or may not considering all the other children subtrees. 
            
            tempAns = 1 + fun(tree[node][i], node,  0);
            
            tempAns += ((j-1 >= 0) ? prefix[j-1] : 0);
            tempAns += ((j+1 < suffix.size()) ? suffix[j+1] : 0);
            j++;
            
        }
        ans = max(ans, tempAns);
    }
    
    return dp[node][flag] = ans;
}


void solve() {
    int n;
    cin >> n;
    
    tree.resize(n+1);
    for(int i=0; i<n-1; i++) {
        int n1,n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    
    dp.resize(n+1, vector<int>(2, -1)); 
    // dp[i][0] will tell maximum matching from subtree with root = i if we do not want to include node i
    // dp[i][1] will tell maximum matching from subtree with root = i if we want to inlcude node i
    
    int ans = max(fun(1,0,0), fun(1,0,1));
    cout << ans;
    
}

signed main() {
    
    int tc = 1;
    //cin >> tc;
    while(tc--) {
        solve();
        //cout << '\n';
    }
    
    return 0;
}
