// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.codechef.com/AABH2020/problems/ODTPIC

**/

vector<int> a;
vector<int> b;

vector<bitset<4001>> a1;
vector<bitset<4001>> b1;

void solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    
    bitset<4001> btst = (a1[r1] ^ a1[l1 - 1]);
    bitset<4001> btst2 = (b1[r2] ^ b1[l2 - 1]);
    
    btst ^= btst2;
    cout << btst.count();
    
}

int main() {
    
    int n,m,q;
    cin >> n >> m >> q;
    a.resize(n+1);
    b.resize(m+1);
    
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int j=1; j<=m; j++) {
        cin >> b[j];
    }
    
    a1.resize(n+1);
    b1.resize(m+1);
    
    bitset<4001> btst;
    
    a1[0] = btst;
    b1[0] = btst;
    
    for(int i=1; i<=n; i++) {
        btst.flip(a[i]);
        a1[i] = btst;
    }
    bitset<4001> btst2;
    for(int i=1; i<=m; i++) {
        btst2.flip(b[i]);
        b1[i] = btst2;
    }
    
    
    while(q--) {
        solve();
        cout << '\n';
    }
    
    return 0;
    
}
