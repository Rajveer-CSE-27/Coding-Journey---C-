// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
https://www.youtube.com/watch?v=mw2J6lvZZJ4&list=PLDjGkpToBsYCaRoQ-_S5MRxYMuKgHD62w&index=4
https://codeforces.com/gym/304970/problem/C

Approach :: 
    Because we are given data for alternative depths hence BFS must come in mind.
    Do BFS.
    At each node try to minimize the value we put in that node.
    Handle 2 cases :: if given val(sum from root to current) = -1, or given val != -1
    
**/


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1);
    vector<int> val(n+1);
    
    for(int i=2; i<=n; i++) {
        int n2;
        cin >> n2;
        tree[n2].push_back(i);
    }
    for(int i=1; i<=n; i++) {
        cin >> val[i];
    }
    
    int flag = 0;
    queue<pair<int,int>> q;
    q.push({1,0});
    int ans = 0;
    
    while(!q.empty()) {
        int m = q.size();
        while(m--) {
            int node = q.front().first;
            int sm = q.front().second; // sm from root till parent of current node
            q.pop();
            
            if(flag == 0) {
                if(sm > val[node]) { 
                    cout << -1;
                    return;
                }
                int nodeVal = (val[node] - sm);
                ans += nodeVal;
                for(int i=0; i<tree[node].size(); i++) {
                    q.push({tree[node][i], val[node]});
                }
            } else {
                
                // checking whether sum till any child is > sum till parent
                if(tree[node].size() != 0) {
                    int mn = LLONG_MAX;
                    for(int i=0; i<tree[node].size(); i++) {
                        int temp = val[tree[node][i]];
                        if(temp < sm) {
                            cout << -1;
                            return;
                        }
                        mn = min(mn, temp);
                    }
                    
                    int nodeVal = mn - sm; // giving the minimum value to the node by checking all the children.
                    ans += nodeVal;
                    for(int i=0; i<tree[node].size(); i++) {
                        q.push({tree[node][i], sm + nodeVal});
                    }
                }
                
                
            }
            
        } 
        
        flag ^= 1;
        
    }
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
