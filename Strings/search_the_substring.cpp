// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
Pattern finding :: 
    
    Given a text t and pattern p.
    Find the occurence of this pattern in text t.
    
We will use z_function.
Time :: O(n + m)
Space :: O(n + m)

Approach ::

    Calculate zArray for string (p + "#" + t)
    
    Let p.length() = n and t.length() = m
    For all indices i > n :: 
            if (z[i] == n) 
                    Then index (i-n-1) is the index in string t from where pattern starts
    
**/


vector<int> z_function(string s) {
    
    int n = s.length();
    vector<int> ans(n);
    
    ans[0] = 0;
    int l = 0, r = 0;
    
    // l = leftboundary of zbox, r = rightboundary of zbox
    
    for(int i=1; i<n; i++) {
        if(i < r) {
            ans[i] = min(r - i, ans[i-l]);
        }
        
        while(i + ans[i] < n and s[ans[i]] == s[i + ans[i]]) {
            ans[i]++;
        }
        
        // update the boundary of zbox
        if(i + ans[i] > r) {
            l = i;
            r = i + ans[i];
        }
    }
    
    return ans;
}

int main() {
    
    string text = "aaaaaaabaaaba";
    string pattern = "aa";
    
    
    string s = pattern + "#" + text;
    vector<int> z = z_function(s);
    
    for(int i=pattern.length() + 1; i<s.length(); i++) {
        if(z[i] == pattern.length()) {
            
            int index = i - pattern.length() - 1;
            cout << index << " ";
            
        }
    }
    
    return 0;
    
    
}
