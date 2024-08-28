// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://www.youtube.com/watch?v=CpZh4eF8QBw

Z-function :: 

    Given string s which has length = n
    
    z[i] = length of the longest substring starting at index i which is also a prefix of the string s.
    
    The first element of Z-function,  z[0] , is generally not well defined. 
    Here we will assume it is zero (although it doesn't change anything in the algorithm implementation).
    
    Hence we calculate z[i] for all i = 0 to n-1
    Time complexity :: O(n) 
    
    Example :: 
        s = aabxaayaab
        z = 0100210310
        
        s = aaaaa
        z = 04321

See the video to understand why we only need O(n) time to compute z_function.
Also read the paragraph Asymptotic behavior of the algorithm :: https://cp-algorithms.com/string/z-function.html

    
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
    
    string s = "abcdabcdabcd";
    vector<int> z = z_function(s);
    for(auto it:z) {
        cout << it << " ";
    }
    
    return 0;
    
    
}
