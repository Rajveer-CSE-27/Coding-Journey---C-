// used for finding longest pallindromic substring in a given string
// || जय जय जय बजरंग बली ||

//https://www.youtube.com/watch?v=ei7qghJEj4Y
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct manacher {
    vector<int> p;
    // p[i] = maximum length pallindrome such that i will be the centre
    
    void run_manacher(string s) {
        int n = s.length();
        p.resize(n, 1);
        
        cout << s << '\n';
        int left = 1, right = 1;
        for(int i=1; i<n; i++) {
             
            p[i] = max(1, min(right - i, p[left + right - i])); 
            /** very important expression ratt lo. It tells that if we have current left(l)
                and right(r) then mirror of index i will be l+r-i. Because centre will be same for both.
                
                Now i will have the length of pallindrome with centre i >= p[mirror of i].
                Hence start expanding from this length and not 1.
                Note that p[i] must not have starting pallindrome length such that it would cross the current right position . 
                Hence p[i] = min(r-i, p[l+r-i]);
                
                Also minimum pallindrome length is 1. p[i] = max(1, min(r-i, p[l+r-i])); 
            **/
            
            // now start expanding the current p[i] and check whether larger pallindrome exists
            
            while((i+p[i] < n) and (i - p[i] >= 0) and (s[i - p[i]] == s[i + p[i]])) {
                p[i]++;
            }
            
            // if required update the new right and left.
            if(i + p[i] > right) {
                left = i - p[i];
                right = i + p[i];
            }
        }
        
        for(int x:p) {
            cout << x << " ";
        }
        cout << '\n';        
    }
    
    void build_hash_string(string s) {
        string t;
        
        for(char c:s) {
            t += string("#") + c;
        }
        t += "#";
        run_manacher(t);
    }
    int getLongest(int centre, bool odd) {
        int realPosition = 2*centre + 1 + (!odd);
        return p[pos] - 1;
    }
    bool checkPallindrome(int l, int r) {
        if((r - l + 1) <= getLongest((l+r)/2, l%2 == r%2) {
            return 1;
        }
        return 0;
    }
    
}m; // that is object of manacher will be named as m

void solve() {
    
    string s = "babbabbabc";
    m.build_hash_string(s);
    
    s = "babad";
    m.build_hash_string(s);
}

int main() {
    
    solve();
    
    return 0;
}
