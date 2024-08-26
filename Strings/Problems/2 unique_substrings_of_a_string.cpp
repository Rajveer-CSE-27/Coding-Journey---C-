// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**

Time :: O(n*n) this does not care about size of string


A solution with  O(nlogn)  is described in the article about Suffix Arrays,
and it's even possible to compute it in O(n)  using a Suffix Tree or a Suffix Automaton.

**/

vector<ll> power;

void pre_compute_powers(int m) {
    
    power.push_back(1);
    ll pow_val = 1;
    int p = 31;
    int mod = 1e9 + 9;
    
    for(int i=1; i<m; i++) {
        pow_val = (pow_val*p) % mod;
        power.push_back(pow_val);
    }
    
}

int main() {
    
    string s;
    cin >> s;
    
    int n = s.length();
    pre_compute_powers(n);
    
    int m = 1e9 + 9;
    vector<ll> hash(n+1, 0);
    // compute hash value for each prefix substring jisse computing hash_val of substring(i,j) is easier.
    
    for(int i=0; i<n; i++) {
        hash[i+1] = (hash[i] + (s[i] - 'a' + 1)*power[i]) % mod;
    }
    
    int ans = 0;
    for(int len=1; len<=n; len++) {
        set<ll> hash_set;
        
        for(int i=0; i<=n - len; i++) {
            ll h = (h[i + len] + mod - h[i]) % mod;
            h = (h * power[n - i - 1])%mod;
            
            // h is the hash value of subtring starting from i and having length = len.
            
            hash_set.insert(h);
        }
        
        ans += hash_set.size();
    }
    
    cout << ans;
    
    return 0;
}
