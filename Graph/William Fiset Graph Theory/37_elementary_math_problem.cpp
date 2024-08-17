// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>

using namespace std;
#define int long long


/**
https://open.kattis.com/problems/elementarymath
https://www.youtube.com/watch?v=zrGnYstL4ss&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=37

Bipartite matching problem.
Just need to crack what will be on set U and set V.

**/

#include <utility>
struct HopcroftKarp {
    vector<int> g, l, r;
    int ans;

    HopcroftKarp(int n, int m, const vector<pair<int, int>>& e)
        : g(e.size()), l(n, -1), r(m, -1), ans(0) {

        vector<int> deg(n + 1);
        for (auto& [x, y] : e)
            deg[x]++;
        
        for (int i = 1; i <= n; i++)
            deg[i] += deg[i - 1];
        
        for (auto& [x, y] : e)
            g[--deg[x]] = y;

        vector<int> a, p, q(n);
        for (;;) {
            a.assign(n, -1);
            p.assign(n, -1);
            int t = 0;

            for (int i = 0; i < n; i++) {
                if (l[i] == -1) {
                    q[t++] = a[i] = p[i] = i;
                }
            }

            bool match = false;
            for (int i = 0; i < t; i++) {
                int x = q[i];
                if (~l[a[x]])
                    continue;

                for (int j = deg[x]; j < deg[x + 1]; j++) {
                    int y = g[j];
                    if (r[y] == -1) {
                        while (~y) {
                            r[y] = x;
                            swap(l[x], y);
                            x = p[x];
                        }
                        match = true;
                        ans++;
                        break;
                    }

                    if (p[r[y]] == -1) {
                        q[t++] = y = r[y];
                        p[y] = x;
                        a[y] = a[x];
                    }
                }
            }

            if (!match)
                break;
        }
    }
};

void solve() {
    int l, r, m;
    
    // l = number of vertices in set U
    // r = number of vertices in set V
    // number of edges between set U and V
    
    cin >> l >> r >> m;
    vector<pair<int, int>> e(m);
    
    // inputting the edges
    for (auto& [x, y] : e)
        cin >> x >> y;
    
    HopcroftKarp hk(l, r, e);
    
    cout << hk.ans << "\n"; // this gives maximum flow in graph i.e MCBM


    for (int i = 0; i < l; i++) { // this will give edges belonging to maximum matching.
        if (~hk.l[i]) {
            cout << i << " " << hk.l[i] << "\n";
        }
    }
}



signed main (){
    
    
    //solve();
    
    int n;
    cin >> n;
    vector<pair<int,int>> vc(n);
    
    for(int i=0; i<n; i++) {
        cin >> vc[i].first >> vc[i].second;
    }
    
    // if we get repeated pairs then it's fine becuase instead of tempering value of capacity of edge we can add edge with capacity 1 for same pair again. Both will be same.
    
    // bipartite graph
    // set U = pairs (a,b)
    // set V = possible values of elementary operations
    
    vector<pair<int,int>> e;
    int cnt = 0;
    map<int,int> mp;
    map<int,int> mp2;
    
    for(int i=0; i<n; i++) {
        set<int> st; // so that a pair and a value cannot have multiple edges
        st.insert(vc[i].first + vc[i].second);
        st.insert(vc[i].first - vc[i].second);
        st.insert(vc[i].first * vc[i].second);
        
        for(auto it:st) {
            if(mp.find(it) == mp.end()) {
                mp[it] = cnt;
                mp2[cnt] = it;
                e.push_back({i,cnt});
                
                cnt++;
            } else {
                e.push_back({i,mp[it]});
            }
        }
    }
    
    
    HopcroftKarp hk(n, cnt, e);
        
    if(hk.ans != n) {
        cout << "impossible";
    } else {
        
        for(int i=0; i<n; i++) {
            if(~hk.l[i]) {
                int val = hk.l[i];
                val = mp2[val];
                
                
                if(val == vc[i].first + vc[i].second) {
                    cout << vc[i].first << " + " << vc[i].second << " = " << val << '\n';
                } else if(val == vc[i].first - vc[i].second) {
                    cout << vc[i].first << " - " << vc[i].second << " = " << val << '\n';
                } else {
                    cout << vc[i].first << " * " << vc[i].second << " = " << val << '\n';
                }
                
            }
        }
        
    }
    
    
    return 0;
    
}
