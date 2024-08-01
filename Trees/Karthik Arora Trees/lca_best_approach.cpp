// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7; 

/**
https://www.youtube.com/watch?v=s9zZOVsF_eo&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=9
https://cses.fi/problemset/task/1688

LCA best approach.
Time Complexity :: O((log(n)))

Approach :: 

    Let there be 2 nodes u and v.
    First we bring them to the same level as discussed in previous approach.
    Now fron there we try to reach u1 and v1 which are the nodes such that the ancestor of u which is immediate child of lca(u,v) is u1 and that of v is v1.
    And from there the lca will just be 1 jump away that is parent of both of these nodes {u1,v1}.
    
    How to reach u1 and v1 efficiently ? 
        Let difference between level of node (u or v) and lca(u,v) be x.
        So we want to find the (x-1)th ancestor from u and v which will be u1 and v1.
        Note that any kth ancestor  such that k > x-1 will be same for u and v.
        
        So everytime we try to find the greatest k such that kth ancestor of u and that of v are different. Let that be u' and v'
        And replace u with u' and v be v' and do the same.
        This is equivalent to representing (x-1) in power of 2.
    
    Total time :: O(logn) :: See code.

    
**/


vector<int> tree[200001];
int up[200001][20];
int level[200001];

void cal_level() {
    
    queue<pair<int,int>> q;
    q.push({1,0}); // root node level = 0
    
    while(!q.empty()) {
        int m = q.size();
        while(m--) {
            pair<int,int> pr = q.front();
            q.pop();
            level[pr.first] = pr.second;
            
            for(int child:tree[pr.first]) {
                q.push({child, pr.second + 1});
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

int find_ancestor(int node, int jump_value) { // iterative code to find ancestor.
    
    for(int i=19; i>=0; i--) {
        
        if(jump_value == 0 || node == -1) {
            break;
        }
        
        if(jump_value >= (1<<i)) {
            jump_value -= (1<<i);
            node = up[node][i];
        }
    }
    
    return node;
    
}

int lca(int n1, int n2) {
    
    if(level[n1] < level[n2]) {
        swap(n1,n2);
    }
    
    n1 = find_ancestor(n1, level[n1] - level[n2]); // bring n1 and n2 to same level
    
    if(n1 == n2) {
        return n1;
    }
    
    
    for(int i=19; i>=0; i--) { 
        
        if(up[n1][i] != up[n2][i]) { // everytime find the greatest jump that you can make.
            n1 = up[n1][i];
            n2 = up[n2][i];
        }
    }
    
    // This is a logn time function. because max value of i <= logn.
    
    return find_ancestor(n1, 1); // lca will be just the parent of n1 or n2.
} 



void solve() {
    int n,q;
    cin >> n >> q;
    
    for(int i=2; i<=n; i++) {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
    }
    
    cal_level();
    binary_lifting(1,-1);
    
    while(q--) {
        int n1,n2;
        cin >> n1 >> n2;
        
        int ans = lca(n1,n2);
        cout << ans << '\n';
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
