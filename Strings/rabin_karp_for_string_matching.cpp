// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://cp-algorithms.com/string/rabin-karp.html
Rabin-Karp Algorithm for string matching

    -> Problem statement : Given a string s and another string t. You need to find the locations in s where string t occurs.
    -> Time complexity :: O(|s| + |t|) for rabin karp method
    
    -> Approach :: 
            Get the hash value for string t in O(|t|) time.
            For each substring of len = |t| in s compute it's hash value and if it equals to that of hash value of t then this is a valid substring.
            The above step can be done in O(|s|) time
                        -> as we can compute hash for any substring of s in O(1) once we compute hash of all it's prefix and that will take O(|s|) time.
            
            hence overall time :: O(|s| + |t|)

**/

vector<int> rabin_karp(string s, string t) {
    // will give all occurences of t in s
    
    int p = 31;
    // assuming both contains lowerCase letters.
    int mod = 1e9 + 9;
    
    int n = s.length(), m = t.length();
    
    // precomputing pow_ps of p
    vector<long long> pow_p(max(n,m));
    pow_p[0] = 1;
    for(int i=1; i<pow_p.size(); i++) {
        pow_p[i] = (pow_p[i-1] * p) % mod;
    }
    
    // computing has value of t
    long long h = 0;
    for(int i=0; i<m; i++) {
        h = (h + (t[i] - 'a' + 1)*pow_p[i]) % mod;
    }
    
    // computing hash for all prefixes of s
    vector<long long> hash(n+1, 0);
    for(int i=0; i<n; i++) {
        hash[i+1] = (hash[i] + (s[i] - 'a' + 1)*pow_p[i]) % mod;
    } 
    
    vector<int> occurences;
    for(int i=0; i+m-1 < n; i++) {
        long long hTemp = (hash[i+m] + mod - hash[i]) %mod;
        
        
        if(hTemp == (h * pow_p[i]) % mod) { // ye multiply by pow_p[i] wala step is important for substring problems.
            occurences.push_back(i);
        }
    }
    
    return occurences;
}

int main() {
   
   
    string s,t;
    cin >> s >> t;
    vector<int> ans = rabin_karp(s,t);
    cout << ans.size() <<'\n';
    for(int i:ans) {
        cout << i << " ";
    }
    
    return 0;
}
