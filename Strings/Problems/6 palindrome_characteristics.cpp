// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int p = 31;
const int mod = 1e9 + 9;
string s;
int n;
/**
https://codeforces.com/contest/835/problem/D

This is not the best solution it will give MLE 
but you can practice hashing concept here.

**/

vector<int> pow_p;
vector<int> hash_;
vector<int> reverseHash_;


int compute_hash_(int i, int j) {
    int len = j - i + 1;
    
    int h = (hash_[i + len] + mod - hash_[i]) % mod;
    h = (h * pow_p[n - i - 1])%mod;
    
    return h;
}

int compute_rev_hash_(int i, int j) {
    int len = j - i + 1;
    
    int h = (reverseHash_[i + len] + mod - reverseHash_[i]) % mod;
    h = (h * pow_p[n - i - 1])%mod;
    
    return h;
}

signed main() {
    
    cin >> s;
    
    n = s.length();
    
    pow_p.resize(n);
    hash_.resize(n+1, 0);
    reverseHash_.resize(n+1, 0);
    string revS = s;
    reverse(revS.begin(), revS.end());
    
    pow_p[0] = 1;
    for(int i=1; i<n; i++) {
        pow_p[i] = (pow_p[i-1] * p) % mod;
    }
    
    for(int i=0; i<n; i++) {
        hash_[i+1] = (hash_[i] + (s[i] - 'a' + 1)*pow_p[i]) % mod;
        reverseHash_[i+1] = (reverseHash_[i] + (revS[i] - 'a' + 1)*pow_p[i]) % mod;
    }
    
    // 1 pallindromes
    
    map<int, set<int>> mp;
    int cnt = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(j == i) {
                mp[i].insert(1);
                cnt++;
            } else {
                if(compute_hash_(i,j) == compute_rev_hash_(n-j-1, n-i-1)) {
                    mp[i].insert(j-i+1);
                    cnt++;
                }
            }
        }
    }
    
    for(int k=1; k<=n; k++) {
        cout << cnt << " ";
        
        int tempCnt = 0;
        map<int, set<int>> temp;
        
        for(auto it:mp) {
            int i = it.first;
            set<int> st = it.second;
            
            for(auto it2:st) {
                int len = it2;
                
                if(i+len+len <= n) {
                    int ii = i, jj = i+len-1;
                    int rii = i+len, rjj = i+len+len-1;
                    if(compute_hash_(ii, jj) == compute_rev_hash_(n - rjj - 1, n - rii - 1)) {
                        temp[i].insert(2*len);
                        tempCnt++;
                    }
                }
                if(i + len + len + 1 <= n) {
                    int ii = i, jj = i + len - 1;
                    int rii = i + len + 1, rjj = i + len + len;
                    if(compute_hash_(ii, jj) == compute_rev_hash_(n - rjj - 1, n - rii - 1)) {
                        temp[i].insert(2*len + 1);
                        tempCnt++;
                    }
                }
                
            }
        }
        
        
        mp = temp;
        cnt = tempCnt;
    }
    
    return 0;
}
