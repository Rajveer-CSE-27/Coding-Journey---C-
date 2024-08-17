// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>

using namespace std;
#define ll long long


/**
https://judge.yosupo.jp/problem/bipartitematching

Matching on Bipartite Graph

Given a bipartite graph calculate MCBM and also show the edges which are a part of maximum matching.
That is the edges which are from vertex belonging to set U to vertex belonging to set V which actually are a part of maximum matching.


Here we will use Hopcroft Karp algorithm
Best algorithm for bipartite matching.
Time complexity :: O(sqrt(n) * m) where n and m are size of sets U and V respectively.

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
    // this is for unweighted bipartite graph only
}



int main (){
    
    
    solve();
    return 0;
    
}
