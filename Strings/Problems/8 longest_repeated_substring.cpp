// || जय जय जय बजरंग बली ||
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
Finding Longest repeated substring/s in a string (LRS).

Find the substring that repeats maximum time.
We will use lcp array for this.

We will check the lcp[i] which have max value/s.
        
        See video : https://www.youtube.com/watch?v=OptoHwC3D-Y&list=PLDV1Zeh2NRsCQ_Educ7GCNs3mvzpXhHW5&index=6
        
        if lcp[i] = max_value = m
        then first string formed by first m characters of the suffix_array_string present there will be a part of all LRS's
    
    
    Hence just look at max value in lcp array                         
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
    
    s += "$"; // this needs to smaller than any character in string
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
    
    string s = "ababbaabaa";
    
    //string s = "abracadabra";
    
    vector<int> suffx_array = suffix_array_construction(s);
    vector<int> lcp_array = lcp_construction(s, suffx_array);
    
    
    int mx = *max_element(lcp_array.begin(), lcp_array.end());
    
    vector<string> lrs;
    
    int n = s.length();
    
    for(int i=0; i<lcp_array.size(); i++) {
        if(lcp_array[i] == mx) {
            int k = suffx_array[i];
            string t;
            
            for(int j=0; j<mx; j++) {
                t += s[k];
                k++;
            }
            lrs.push_back(t);
        }
    }
    
    for(auto it:lrs) {
        cout << it << " ";
    }
    
    
    return 0;
    
    
}
