// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;


/**
https://www.youtube.com/watch?v=fGznXJ-LTbI&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s
https://cses.fi/problemset/task/1674/

Approach :: 
    Do dfs.
    Time Complexity :: O(n).
**/

vector<vector<int>> tree;
vector<int> ans;

int dfs(int node, int parent) {
    
    int curr = 0;
    for(int i=0; i<tree[node].size(); i++) {
        if(tree[node][i] != parent) {
            curr += dfs(tree[node][i], node);
        }
    }
    
    ans[node] = curr; // subordinate do not include the current node. Only its descendants.
    
    return curr+1; // becuase we are sending number of nodes in current subtree to the parent
}

void solve() {
    int n;
    cin >> n;
    
    tree.resize(n+1);
    ans.resize(n+1, -1);
    for(int i=2; i<=n; i++) {
        int x;
        cin >> x;
        tree[x].push_back(i);
    }
    
    dfs(1,0);
    for(int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
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
