// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
Finding unique substrings in a string 
We will use lcp array to do that.

Example :: 
    s = "azaza"
    Hence total substrings ::  "a", "az", "aza", "azaz", "azaza",
                                "z", "za", "zaz", "zaza", 
                                "a", "az", "aza",
                                "z", "za",
                                "a".
    
    We need to find count of unique substrings.
    
    Note that lcp[i] = number of common characters in prefix of string at suffix_array index i and i+1.
    
    Here lcp array ::  
        1               a
        3               aza
        0               azaza
        2               za
                        zaza
    
    lcp[0] = 1 this helps us to conclude that ::
                    due to a and aza there will be 1 substring {a} that will be repeated becuase it occurs in both.
    
    lcp[1] = 3 this helps us to conclude that ::       
                    due to aza and azaza there will be 3 substrings {a, az, aza} that will be repeated becuase all of them occur in both.
    .
    .
    .
    
    Hence total number of repeated substrings = sum of of lcp[i]
    
    Hence total number of unique substrings in a string = total substrings - number of repeated substrings.
                                                        = (n*(n+1))/2 - sum(lcp)
                                                        
        
    Time :: O(nlogn + n + n) = O(nlogn)                                
**/


vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    
    // time :: O(nlogn)
    // space :: O(n)
    
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    
    // if you want to know smallest cyclic shift then 
    //                              return sorted_shifts[0] at this line
    
    
    
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}


vector<int> lcp_construction(string& s, vector<int> p) {
    
    // kasai algorithm
    // time :: O(n)
    // space :: O(n)
    
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

int main() {
    
    string s = "azaza";
    vector<int> suffix_array = suffix_array_construction(s);
    vector<int> lcp_array = lcp_construction(s, suffix_array);
    
    int n = s.length();
    int ans = (n*(n+1))/2;
    
    int sm = 0;
    for(int i=0; i<lcp_array.size(); i++) {
        sm += lcp_array[i];
    }
    
    ans -= sm;
    cout << ans;
    
    return 0;
    
    
}
