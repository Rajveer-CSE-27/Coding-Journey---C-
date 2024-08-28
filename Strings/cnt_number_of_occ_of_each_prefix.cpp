// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://cp-algorithms.com/string/prefix-function.html

Counting the number of occurrences of each prefix in the string
Brute force time :: O(n*n)

Part 1 :: 
    Counting the number of occurrences of each prefix in the same string s.
    
Approach :: 
    Use prefix_function.
    
    p[i] will give longest proper prefix which is equal to suffix ending at index i.
    
    Using p[i] we can calculate number of times each prefix will occuring in the string.
    
    See code for explaination.
    

Time complexity :: O(n + n) = O(n)
Space complexity :: O(n)


**/

vector<int> prefix_function(string s) {
    
    int n = s.length();
    vector<int> p(n);
    p[0] = 0;
    
    for(int i=1; i<n; i++) {
        
        int l = p[i-1];
        while(l > 0 and s[i] != s[l]) {
            l = p[l-1];
        }
        
        if(s[i] == s[l]) {
            l++;
        }
        p[i] = l;
        
    }
    
    return p;

}

vector<int> compute_prefix_cnt(string s) {
    
    vector<int> p = prefix_function(s);
    int n = p.size();
    
    // first count the occurences of all prefixes in p
    vector<int> ans(n + 1, 0);
    
    for(int i=0; i<n; i++) {
        ans[p[i]]++;
    }
    
    // if prefix of length = 5 occurs x times then x would be added to cnt of prefixes of len = 4, 3, 2, 1;
    // to aise har larger prefix jitni bhi baar occur hota hai utne ko smaller prefixes ke cnt me add karo
    
    for(int i=n-1; i>0; i--) {
        ans[p[i-1]] += ans[i];
    }
    
    // At the end we need to add 1 to each result, since we also need to count the original prefixes also.
    
    for(int i=0; i<=n; i++) {
        ans[i]++;
    }
    
    return ans;
}


int main() {
    
    string s = "aaaaabaa";
            
    vector<int> ans = compute_prefix_cnt(s);
        
    for(int prefLen = 1; prefLen <= s.length(); prefLen++) {
        cout << ans[prefLen] << " ";
    }
    
    
    
    return 0;
    
    
}
