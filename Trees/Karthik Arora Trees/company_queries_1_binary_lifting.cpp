// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7; 

/**


Approach 1 :: 
    O(n*q) approach. That is each query takes O(n) time.
    Mark the parent of each node.
    In each query go from current node to kth ancestor by parent traversing.
    Hence time :: O(nq).
    
Approach 2 :: 
    Binary lifting approach.
    We will fill up array for all the nodes in total nlogn time. Because for each node we will make a jump of O(logn).
    At the end we will get the kth ancestor in logk time.
    Total time :: O(nlogn) + O(logk).
    
**/


class Approach1 {
public:
    
    int n;
    vector<int> tree[200001];
    int parent[200001];
     
    void find_parent(int node, int p) {
        parent[node] = p;
        
        for(int i=0; i<tree[node].size(); i++) {
            find_parent(tree[node][i], node);
        }
    }
     
    void solve() {
        int node, k;
        cin >> node >> k;
        
        int currentNode = node;
        while(k--) {
            currentNode = parent[currentNode];
            if(currentNode == 0) {
                cout << -1;
                return;
            }
        }
        cout << currentNode;
    }
     
    int main() {
        
        int q;
        cin >> n >> q;
        for(int i=2; i<=n; i++) {
            int boss;
            cin >> boss;
            tree[boss].push_back(i);
        }
        
        find_parent(1,0);
        
        while(q--) {
            solve();
            cout << '\n';
        }
        
        
        return 0;
    }
    
};


class Approach2 {
public:
    
    vector<int> tree[200001];
    int up[200001][20]; // because for skew tree max value of jump = log2(200001) ~ 20.
    
    
    void binary_lifting(int node, int parent) {
        
        up[node][0] = parent; // jump of 2^0 = 1 will lead us to parent.
        
        for(int i=1; i<20; i++) {
            
            // jump(node, 2^i) = jump(node,2^(i-1)) and then from there again jump(new_node, 2^(i-1)). Hence total jump = 2^(i-1) + 2^(i-1) = 2^(i).
            if(up[node][i-1] != -1) {
                up[node][i] = up[up[node][i-1]][i-1];
            } else {
                up[node][i] = -1;
            }
        }
        
        //dfs
        for(int child:tree[node]) {
            if(child != parent) {
                binary_lifting(child, node);
            }
        }
        
    }
    
    int find_ancestor(int node, int jump_required) {
        
        // base case
        if(node == -1) {
            return -1;
        }
        if(jump_required == 0) {
            return node;
        }
        
        for(int i=19; i>=0; i--) { // get the biggest possible jump
            
            // so in binary representation of jump_required we are finding largest set bit.
            if(jump_required >= (1<<i)) {
                return find_ancestor(up[node][i], jump_required - (1<<i));
            }
            
        }
    }
    
    int main() {
        int n,q;
        cin >> n >> q;
        
        for(int i=2; i<=n; i++) {
            int boss;
            cin >> boss;
            tree[boss].push_back(i);
        }
        
        binary_lifting(1,-1); // root,-1
        
        while(q--) {
            int node, k;
            cin >> node >> k;
            int ans = find_ancestor(node, k);
            cout << ans << '\n';
        } 
        
    }
};


signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    
    int tc = 1;
    //cin >> tc;
    while(tc--) {
        //solve();
        //cout << '\n';  
    }
    return 0;
}
