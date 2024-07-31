// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7; 

/**
https://www.youtube.com/watch?v=SOhZqL6HPjQ&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=6
https://codeforces.com/contest/161/problem/D

Important question.
It will teach you how to get unique pair of nodes for given condition
**/

vector<vector<int>> tree;
vector<vector<int>> dp; 

void dfs(int node, int parent, int& k, int& ans) {
    
    dp[node][0] = 1;
    for(int child:tree[node]) {
        if(child != parent) {
            
            dfs(child, node, k, ans);
            for(int i=0; i<k; i++) {
                ans += (dp[node][i] * dp[child][k - i - 1]);
            }
            
            // unique pair of nodes ke liye current child ki information iss step se pehle add mat karo.
            
            // adding the values of child now so that it interacts with future values only. And hence we only get unique pair of nodes.
            for(int i=1; i<=k; i++) {
                dp[node][i] += dp[child][i-1];
            }
        }
    }
}

void solve() { 
  
   int n,k;
   cin >> n >> k;
   
   tree = vector<vector<int>>(n+1);
   dp = vector<vector<int>>(n+1, vector<int>(k+1,0));
   // dp[i][j] = number of nodes in subtree of node i that are at distance j.
   
   for(int i=0; i<n-1; i++) {
    int n1,n2;
    cin >> n1 >> n2;
    tree[n1].push_back(n2);
    tree[n2].push_back(n1);
   }
   
   int ans = 0;
   dfs(1,0,k,ans);
   
   cout << ans;
}


signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    
    int tc = 1;
    //cin >> tc;
    while(tc--) {
        solve();
        //cout << '\n';  
    }
    return 0;
}
