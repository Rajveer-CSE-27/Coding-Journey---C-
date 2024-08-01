// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7; 

/**
https://www.youtube.com/watch?v=qPxS_rY0OJw&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=8
https://cses.fi/problemset/task/1688
NOTE :: this solution will have TLE in cses problem set as it wants LCA in (logn)

LCA using binary search.
Time Complexity :: O((log(n))^2)

Approach :: 

    Let there be two node u,v whose LCA we want to find.
    Let u be at level h1 and v be at h2 where root node of tree is at level 1.
    
    Let h1 > h2 :: 
        First find the ancestor of u which is at level h2 let us call it u2. This can be done using binary lifting.
    
    Now there are 2 nodes u2 and v both at same level and we want to find there LCA.
    Now, in other words we need to find greatest level x such that :: 1 <= x <= h2 such that if we start from node v and node u2 and go upto level x then the nodes we get is same.
    The required x could be found using binary search on value of x.
    
    Total time complexity :: O(logn * logn) :: for each query q :: 1 logn for binary search and inside each binary search we move to a certain ancestor from nodes u2 and v so logn for that
    Time complexity of making the "up" table for binary lifting :: O(n)
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


int lca_binary_search(int n1, int n2) {
    
    int l1 = level[n1], l2 = level[n2];
    
    if(l1 > l2) {
        int diff = l1 - l2;
        n1 = find_ancestor(n1, diff);
    } else if(l2 > l1) {
        int diff = l2 - l1;
        n2 = find_ancestor(n2, diff);
    }
    
    // now l1 and l2 are on same level
    // do binary search
    
    if(n1 == n2) {
        return n1;
    }
    
    int low = 0, high = level[n1]; // start with 0 becuase if low = 1 it we cannot surely tell that it would not be lca. but in low = 0 we can surely tell it.
    
    while(low != high) { // agar low < high wale concept se karoge to wrong answer aa raha hai
        int mid = (low + high)/2;
        
        int ancestor1 = find_ancestor(n1, mid);
        int ancestor2 = find_ancestor(n2, mid);
        
        if(ancestor1 == ancestor2) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return find_ancestor(n1, low);
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
        
        int ans = lca_binary_search(n1,n2);
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
