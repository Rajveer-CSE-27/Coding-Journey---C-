// || जय जय जय बजरंग बली ||
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.codechef.com/problems/CHEFQUE

use bitset of size 2^32 to keep track of values.
Note sm must be calculated along q. Do not iterate for all values 1 to 2^32 afterwards
            
**/


int main() {
    
    ll q, s, a, b;
    cin >> q >> s >> a >> b;
    
    const ll N = (1LL<<32);
    bitset<N> btst;
    
    ll sm = 0;
    while(q--) {
        ll val = s/2;
        
        if(s&1) {
            if(btst[val] == 0) {
                sm += val;
                btst[val] = 1;
            }
        } else {
            if(btst[val] == 1) {
                sm -= val;
                btst[val] = 0;
            }
        }
        
        s = (s*a + b)%N;
    }
    
    cout << sm;
    return 0;
    
}
