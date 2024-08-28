// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
https://cp-algorithms.com/string/prefix-function.html

Counting the number of occurrences of each prefix
Brute force time :: O(n*n)

Part 1 :: 
    Counting the number of occurrences of each prefix in the same string s.
Part 2 :: 
    Counting the number of occurrences of each prefix in a different string t.
    
Approach :: 
    Use prefix_function.
    
    p[i] will give longest proper prefix which is equal to suffix ending at index i.
    
    Using p[i] we can calculate number of times each prefix will occuring in the string.
    
    See code for explaination.
    
this approach is for Part 1.
For part 1 use the trick (s + "#" + t) as in KMP.
Then calculate the prefix function for the string t 
And then use the same function for caluculating the answer.

Part 1 :: 
Time complexity :: O(n + n) = O(n)
Space complexity :: O(n)

Part 2 :: 
Time complexity :: O(n + m + n) = O(n + m)
Space complexity :: O(m)

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

vector<int> kmp_prefix_s(string s, string t) {
    
    int m = t.length();
    t += "#";
    // hash is the seperator
    vector<int> p = prefix_function(t);
    
    vector<int> prefix_s;
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
        
        prefix_s.push_back(prev); 
    }
    
    // returns prefix function for string s with prefixes of t
    return prefix_s;
}

vector<int> compute_prefix_cnt(vector<int> p) {
    
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

vector<int> compute_prefix_cnt_2(vector<int> p) {
    
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
    
    // At the end we do not need to add 1 to each result. like part 1 as original prefixes are not present in this string
    
    return ans;
}

int main() {
    
    string s = "baacabacabacabb";
    string t = "acabaca";
    
    // Part 1
    // calculating number of occurences of each prefix of s in s itself 
    
    vector<int> p = prefix_function(s);
    vector<int> ans = compute_prefix_cnt(p);
        
    for(int prefLen = 1; prefLen <= s.length(); prefLen++) {
        cout << ans[prefLen] << " ";
    }
    cout << '\n';
    
    // Part 2
    // calculating number of occurences of each prefix of t in s
    p = kmp_prefix_s(s,t);    
    ans = compute_prefix_cnt_2(p);
    
    
    for(int prefLen = 1; prefLen <= t.length(); prefLen++) {
        cout << ans[prefLen] << " ";
    }
    
    
    return 0;
    
    
}
