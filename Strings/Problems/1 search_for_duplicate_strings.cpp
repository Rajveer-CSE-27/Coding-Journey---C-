// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem :: 
    Given n string, each no longer then m characters.
    Find all duplicate strings and write their indices together as groups.
    
Approach :: 
    String hashing.
    Saare similar strings ki hash value same hogi to unko ek saath club kardo.

Time complexity :: 
    
    Compute hash for all the strings 
    O(nm)
    Grouping :: O(nlogn)
    
    Time :: O(nm + nlogn)
    
    
    Agar hash naa use karte to O(nmlogn) hota.

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

ll compute_hash(string& s) {
    
    // nothing given so let p = 31
    int p = 31;
    int m = 1e9 + 9; // ye m given m se alag hai. Ek mat samaj lena
    ll hash_val = 0;
    
    int n = s.length();
    
    for(int i=0; i<n; i++) {
        hash_val = (hash_val + (s[i] - 'a' + 1)*power[i]) % m;
    }
    return hash_val;
        
}

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<string> vc(n);
    for(int i=0; i<n; i++) {
        cin >> vc[i];
    }
    
    pre_compute_powers(m);
    
    map<ll,vector<int>> mp;
    for(int i=0; i<n; i++) {
        mp[compute_hash(vc[i])].push_back(i);
    }
    
    for(auto it:mp) {
        vector<int> temp = it.second;
        for(int i:temp) {
            cout << i << " ";
        } 
        cout << '\n';
    }
    
    return 0;
}
