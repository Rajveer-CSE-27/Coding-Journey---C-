// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=mw2J6lvZZJ4&list=PLDjGkpToBsYCaRoQ-_S5MRxYMuKgHD62w&index=4
https://codeforces.com/gym/304970/problem/B

Approach :: 
    At each node find the expected length if we visit each child. And add them up.
    Start from root node.
    Do dfs to explore whole path at once.

**/

vector<vector<int>> tree;

double dfs(int node, int parent) {
    
    int totalChild = tree[node].size() - 1;
    if(node == 1) {
        totalChild++;
    }
    
    if(totalChild == 0) {
        return 0;
    }
    double currentExpectedLen = 0.0;
    
    for(int i=0; i<tree[node].size(); i++) {
        if(tree[node][i] != parent) {
            currentExpectedLen += (1.0 + dfs(tree[node][i],node))/totalChild;
        }
    }
    return currentExpectedLen;
    
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
    
    double ans = dfs(1,0);
    cout << fixed << setprecision(10) << ans;
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
