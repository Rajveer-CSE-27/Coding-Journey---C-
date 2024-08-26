// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://codeforces.com/contest/61/problem/E

PBDS
j ke around game khelni hai
for each j find out number of greater elements before it and number of smaller elements after it. 
Multiply both and add to answer.

Keep 2 osets
Also elements are distinct.
**/

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int main() {
    
    int n;
    cin >> n;
    vector<int> vc(n);
    
    for(int i=0; i<n; i++) {
        cin >> vc[i];
    }
    
    oset o1, o2;
    for(int i=0; i<n; i++) {
        o2.insert(vc[i]);
    }
    
    ll ans = 0ll;
    for(int j=0; j<n; j++) {
        
        o2.erase(o2.find(vc[j]));
        int sz = o1.size();
        
        ll icnt = sz - o1.order_of_key(vc[j]);
        ll kcnt = o2.order_of_key(vc[j]);
        
        ll cnt = (icnt * kcnt);
        ans += cnt;
        
        o1.insert(vc[j]);
        
    }
    cout << ans;
    
    return 0;
}
