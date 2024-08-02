// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7; 

/**
https://www.youtube.com/watch?v=gj0zp--fBL8&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=14
https://codeforces.com/contest/461/problem/B

Must see video
**/

vector<int> tree[100001];
bool isBlack[100001];
int dp_black[100001]; // number of components that can be generated from current node such that each component has 1 black node and other white nodes. 
int dp_white[100001]; // number of components that can be generated from current node such that component containing the current node as all white nodes and rest all componenets have exactly 1 black node and other white.

void dfs(int node, int parent) {
    
    // first solve for all child nodes
    for(int child:tree[node]) {
        if(child != parent) {
            dfs(child, node);
        }
    }
    
    if(isBlack[node] == true) {
        dp_white[node] = 0;
        
        int ans = 1;
        for(int child:tree[node]) {
            if(child != parent) {
                ans = (ans * (dp_black[child] + dp_white[child]))%mod;
            }
        }
        dp_black[node] = ans;
    } else {
        
        vector<int> child_white, child_black;
        for(int child:tree[node]) {
            if(child != parent) {
                child_white.push_back(dp_white[child]);
                child_black.push_back(dp_black[child]);
            }
        }
        
        int m = child_white.size();
        
        if(m == 0) { // leaf node
            dp_white[node] = 1;
            dp_black[node] = 0;
            return;
        }
        
        
        vector<int> pref(m), suff(m);
       
        pref[0] = (child_white[0] + child_black[0])%mod;
        for(int i=1; i<m; i++) {
            int val = (pref[i-1] * (child_white[i] + child_black[i]))%mod;
            pref[i] = val;
        }
        
        suff[m-1] = (child_white[m-1] + child_black[m-1])%mod;
        for(int i=m-2; i>=0; i--) {
            int val = (suff[i+1] * (child_white[i] + child_black[i]))%mod;
            suff[i] = val;
        }
        
        dp_white[node] = pref[m-1];
        dp_black[node] = 0;
        int temp = 0;
        
        int j = 0;
        for(int child:tree[node]) {
            if(child != parent) {
                
                int leftWhiteWays = (j == 0) ? 1 : pref[j-1];
                int rightWhiteWays = (j == m-1) ? 1 : suff[j+1];
                
                int curr = (((leftWhiteWays * rightWhiteWays)%mod) * dp_black[child])%mod;
                temp = (temp + curr)%mod;
                j++;
            }
        }
        
        dp_black[node] = temp;
    }
}

void solve() {
    int n;
    cin >> n;
    
    for(int i=0; i<n-1; i++) {
        int x;
        cin >> x;
        tree[i+1].push_back(x);
        tree[x].push_back(i+1);
    }
    
    for(int i=0; i<n; i++) {
        cin >> isBlack[i];
    }
    
    dfs(0, -1);
    cout << dp_black[0];

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
