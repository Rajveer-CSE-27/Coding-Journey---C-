// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**

Suffix arrays introduction :: 
    https://www.youtube.com/watch?v=zqKlL3ZpTqs&list=PLDV1Zeh2NRsCQ_Educ7GCNs3mvzpXhHW5&index=1
    
    Suffix is a nonempty substring at the end of the string.
    Eg horse :: 
            e, se, rse, orse, horse are all suffixes of the string.
            
    Suffix array is an array which contains all sorted suffixes of a string.
    Eg camel :: 
            
        suffixes :: camel, amel, mel, el, l
        indices ::  0,     1,    2,   3,  4
        The indices reprsents the index in string from where that suffix began
        
        if we sort these strings lexiographically :: amel, camel, el, l, mel
        Then sequence of the original indices ::     1,    0,     3,  4, 2
        
        Hence the suffix array for the string :: [1,0,3,4,2]
        
    The suffix array provides a compressed representation of the sorted suffixes without actually storing those suffixes.
    
    Note :: suffix arrays can do everything suffix trees can, with some additional information
            such as a Longest Common Prefix (LCP) array.
            Hence using suffix arrays is better than suffix trees.
            

Construction of suffix arrays :: 
    https://www.youtube.com/watch?v=_TUeAdu-U_k
    
    Suffix arrays can be constructed in O(nlogn) with the help of radix sort. {Because the values of suffix arrays are bounded <=n-1 . Hence on a bounded range radix sort works in O(n)}
    
    The approach to construct a suffix array is beautifully explained in video.
    See it.
    
Code to construct suffix array is explained here : https://cp-algorithms.com/string/suffix-array.html
    
        
    
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


int main() {
    
    string s = "camel";
    vector<int> ans = suffix_array_construction(s);
    for(auto it:ans) {
        cout << it << " ";
    }
    
    return 0;
    
    
}
