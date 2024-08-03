// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7; 

/**
https://www.youtube.com/watch?v=8Nq3THy2Kw0&t=39s
https://cses.fi/problemset/task/1136/

Approach ::: 
    For each a,b in question find their lca.
    Now theoretically value of each node from lca to a and from lca to b should be incremented by 1. And at the end value of lca should be decreemented by 1 becuase we added twice to it.
    
    Now to implement the above line efficientlty
    
        Do :: val[a]++
              val[b]++
              we must decrement value of lca :: val[lca]--;
              also we must decrement parent of lca becuase when we count for a path from down to up we do not add values further than lca
              val[parent(lca)]--;
        
        do this much in each query.
    
    At the end :: 
        The answer for a node will be sum of all values in its subtree.
        Because :: 
            
            the sum of all its subtree values will represent total number of paths passing through the current node as any path that will pass through the current node, 
            would either originate from subtree or end in subtree or both.

**/

vector<vector<int>> tree; 
vector<vector<int>> up;
vector<int> level;
vector<int> val;
vector<int> res;

void cal_level() {
    
    int n = tree.size();
    queue<pair<int,int>> q;
    q.push({1,0});
    vector<bool> visited(n, false);
    visited[1] = true;
    
    while(!q.empty()) {
        int m = q.size();
        
        while(m--) {
            int node = q.front().first, l = q.front().second;
            q.pop();
            level[node] = l;
            
            for(int child:tree[node]) {
                if(visited[child] == false) {
                    visited[child] = true;
                    q.push({child, l+1});
                }
            }
        }
    }
}

void binary_lifting(int node, int parent) {
    
    up[node][0] = parent;
    for(int i=1; i<20; i++) {
        if(up[node][i-1] != -1) {
            up[node][i] = up[up[node][i-1]][i-1];
        } else {
            up[node][i] = -1;
        }
    }
    
    // dfs
    for(int child:tree[node]) {
        if(child != parent) {
            binary_lifting(child, node);
        }
    }
}

int find_ancestor(int node, int jump_value) {
    
    for(int i=19; i>=0; i--) {
        if(node == -1 or jump_value == 0) {
            break;
        }
        
        if(jump_value >= (1<<i)) {
            node = up[node][i];
            jump_value -= (1<<i);
        }
    }
    
    return node;
    
}

int find_lca(int n1, int n2) {
    
    if(level[n1] < level[n2]) {
        swap(n1,n2);
    }
    
    n1 = find_ancestor(n1, level[n1] - level[n2]);
    if(n1 == n2) {
        return n1;
    }
    
    for(int i=19; i>=0; i--) {
        if(up[n1][i] != up[n2][i]) {
            n1 = up[n1][i];
            n2 = up[n2][i];
        }
    }
    
    return find_ancestor(n1, 1);
}

int dfs(int node, int parent) {
    
    // result for current node will be sum of all values of current subtree
    int ans = val[node];
    for(int child:tree[node]) {
        if(child != parent) {
            ans += dfs(child, node);
        }
    }
    
    return res[node] = ans;
    
}

void solve() {
    int n,m;
    cin >> n >> m;
    
    tree.resize(n+1);
    up.resize(n+1, vector<int>(20));
    level.resize(n+1);
    
    for(int i=0; i<n-1; i++) {
        int n1,n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    
    cal_level();
    binary_lifting(1,-1);
    
    val.resize(n+1, 0);
    res.resize(n+1);
    while(m--) {
        int n1,n2;
        cin >> n1 >> n2;
        
        int lca = find_lca(n1,n2);
        val[n1]++;
        val[n2]++;
        val[lca]--;
        int par = find_ancestor(lca,1);
        if(par != -1) {
            val[par]--;
        }
    }
    
    dfs(1,-1);
    
    for(int i=1; i<=n; i++) {
        cout << res[i] << " ";
    }
}


int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    
    int tc = 1;
    //cin >> tc;
    while(tc--) {
        solve();
        //cout << '\n';  
    }
    return 0;
}
