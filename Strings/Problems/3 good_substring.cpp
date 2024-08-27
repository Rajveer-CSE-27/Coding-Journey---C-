// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define int long long

/**
https://codeforces.com/contest/271/problem/D

This approach include using 2 p and mod values
To get lesser probability for collision
**/


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin >> s;
    string bad;
    cin >> bad;
    int k;
    cin >> k;
    
    int n = s.length();
    
    int p1 = 31, p2 = 29;
    int mod1 = 1e9 + 9, mod2 = 1e9 + 13;
    
    set<pair<int,int>> hash_set;
    
    for(int i=0; i<n; i++) {
        int power1 = 1, power2 = 1;
        int badCnt = 0;
        
        int h1 = 0, h2 = 0;
        
        for(int j=i; j<n; j++) {
            if(bad[s[j]-'a'] == '0') {
                badCnt++;
            }
            
            if(badCnt > k) {
                break;
            }
            
            h1 = (h1 + (s[j] - 'a' + 1)*power1) % mod1;
            h2 = (h2 + (s[j] - 'a' + 1)*power2) % mod2;
            power1 = (power1 * p1) % mod1;
            power2 = (power2 * p2) % mod2;
            
            hash_set.insert({h1,h2});
            
        }
    }
    
    cout << hash_set.size();
    
    return 0;
}
