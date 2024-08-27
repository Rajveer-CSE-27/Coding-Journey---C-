// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
 https://www.youtube.com/watch?v=NIGA-CIIi0k
 
 KMP algorithm :: 
    Used to find all the occurences of a string inside another string.
    Time :: O(n + m)
    Space :: O(m) where m is the size of the smaller string
    
    Note n must be >= m else there would be no occurences.
    
Approach1 :: 
    
    Space :: O(n + m) approach and Time :: O(n + m)
    
    Let strings be s of len = n and t of len = m.
    Need to find all occurences of t in s.
    
    Create a string (t + "#" + s).
    Run the prefix function for this strings. Hence time :: O(n + m)
    Count the number of indices whose (p[i] == m).
    That will be your answer.
    
    
    For reason see the video.
    
Approach2 :: 
    
    Space :: O(m) approach and Time :: O(n + m)
    
    We observe the for the previous approach :: p[i] <= m for any i.
    Hence in prefix function algorithm :: 
            the value of l <= m.
            and if we go on doing l = p[l-1] then l will get smaller and smaller.
            
            Hence to calculate the p[i] we just need p[i-1] which you can store in a variable called prev,
            and all the p[j] for j=0 to j=m.
            
    Hence space :: O(m)
    
See video if confused.
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

vector<int> kmp(string s, string t) {
    
    int m = t.length();
    t += "#";
    // hash is the seperator
    vector<int> p = prefix_function(t);
    
    vector<int> occurences;
    int prev = 0;
    // here prev = p[m] which will be definitely = 0
    
    int n = s.length();
    
    for(int i=0; i<n; i++) {
        int l = prev;
        
        while(l > 0 and s[i] != t[l]) {
            l = p[l-1];
        }
        
        if(s[i] == t[l]) {
            l++;
        }
        prev = l;
        
        if(prev == m) {
            occurences.push_back(i);
        } 
    }
    
    // occurences will return the indices where string t finishes in s
    return occurences;
}

int main() {
    
    string s = "baacabacabacabb";
    string t = "acabaca";
    
    vector<int> ans = kmp(s,t);
    cout << ans.size() << '\n';
    
    for(auto it:ans) {
        cout << it << " ";
    }
    
    return 0;
}
