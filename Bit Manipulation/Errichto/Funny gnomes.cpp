// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.codechef.com/problems/SHAIKHGN?tab=statement

brute force approach.
Higher approach requires binary lifting

**/

vector<bitset<501>> vc;


void solve() {
   int k, x;
   cin >> k >> x;
   
   int n = vc.size() - 1;
   if(k == 0) {
        cout << 1 << '\n' << x;
        return;
   }
   bitset<501> btst = vc[x];
   
   k--;
   while(k--) {
    
     bitset<501> temp;
     for(int i=1; i<=n; i++) {
       if(btst[i] == 1) {
        temp |= vc[i];
       }
     }
     
     btst = temp;
   }
   
   int ans = btst.count();
   cout << ans << '\n';
   
   if(ans == 0) {
    cout << -1;
    return;
   }
   
   for(int i=1; i<=n; i++) {
    if(btst[i] == 1) {
        cout << i << " ";
    }
   }
    
}

int main() {
    
    int n;
    cin >> n;
    
    vc.resize(n+1);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int x;
            cin >> x;
            if(x == 1) {
                vc[i].flip(j);
            }
        }
    }
    
    int m;
    cin >> m;
    
    
    while(m--) {
        solve();
        cout << '\n';
    }
    
    return 0;
    
}
